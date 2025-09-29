/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:49:31 by akonstan          #+#    #+#             */
/*   Updated: 2025/09/26 18:49:36 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft_extended/libft.h"

//Enum with all the redirection types
typedef enum s_redirect_type
{
	RE_IN,
	RE_OUT,
	RE_APPEND,
	RE_HEREDOC
} t_redirect_type;

//Enum with all the token types. Quotes should not be their own tokens
//We filter them in the lexer out and we set squotesd or dquoted flags
//on the token
typedef enum s_token_type
{
	T_WORD,
	T_RE_IN,
	T_RE_OUT,
	T_RE_APPEND,
	T_RE_HEREDOC,
	T_PIPE_OP,
	T_END
} t_token_type;

//Token structure which the lexer will give as output
//We will work on a single linked list of tokens called CHAIN
typedef struct s_token
{
	char			*string;
	t_token_type	type;
	bool			is_single_quoted;
	bool			is_double_quoted;
	struct s_token	*next;
} t_token;

//Redirections structure, shows what kind of redirection we have and
//where it should target
typedef struct s_redirect
{
	t_redirect_type	type;
	char			*target_file;
} t_redirect;

//Command struct that holds the actuall command to execute and any 
//redirections (if they exist)
//the token array will be holding the tokens during parsing and the expander
//will use them to create the argv array to pass to the executor
typedef struct s_cmd
{
	char		**argv;
	t_token		**cmd_tokens;
	t_redirect	*redirection;
} t_cmd;

//Pipe structure that holds the command on the current pipe and
//a pointer pointing to the next pipe
typedef struct s_pipe
{
	t_cmd			*command;
	unsigned int	cmd_amount;
	struct s_pipe	*next;
} t_pipe;

//PARSER FUNCTIONS
t_pipe	*parser(t_token **chain);
//TOKENS HELPER FUNCTIONS
t_token	*ft_new_token(t_token_type type, char *str);
t_token	*ft_get_last_token(t_token *chain);
void	ft_add_token(t_token **chain, t_token *token);
