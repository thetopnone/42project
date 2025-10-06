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

//Enum with quotation type
//We have the Q_NONE type because ft_bzero will set the enum var to 0
//which is the first member of the enum group 
typedef enum s_quote_type
{
	Q_NONE,
	Q_DOUBLE,
	Q_SINGLE
} t_quote_type;

//Enum with all the redirection types
typedef enum s_redir_type
{
	RE_NONE,
	RE_IN,
	RE_OUT,
	RE_APPEND,
	RE_HEREDOC
} t_redir_type;

//Enum with all the token types. Quotes should not be their own tokens
//We filter them in the lexer out and we set squotesd or dquoted flags
//on the token
//T_END will be signaling the end of a token chain
typedef enum s_token_type
{
	T_NONE,
	T_WORD,
	T_REDIR,
	T_PIPE_OP,
	T_END
} t_token_type;

//Token structure which the lexer will give as output
//We will work on a single linked list of tokens called CHAIN
typedef struct s_token
{
	char			*string;
	t_token_type	type;
	t_quote_type	q_type;
	struct s_token	*next;
} t_token;

//Redirections structure, shows what kind of redirection we have and
//where it should target
//The two bools describe the filename
typedef struct s_redirect
{
	t_redir_type		type;
	char				*target;
	t_quote_type		q_type;
	struct s_redirect	*next;
} t_redirect;

//Command struct that holds the actuall command to execute and any 
//redirections (if they exist)
//the token array will be holding the tokens during parsing and the expander
//will use them to create the argv array to pass to the executor
typedef struct s_cmd
{
	char		**argv;
	t_token		*cmd_chain;
	t_redirect	*red_chain;
} t_cmd;

//Pipe structure that holds the command on the current pipe and
//a pointer pointing to the next pipe
typedef struct s_pipe
{
	t_cmd			*command;
	unsigned int	cmd_amount;
	struct s_pipe	*next;
} t_pipe;

//This is an error holding struct. We will pass t_error variables as
//arguments so that functions will assign the value to the specific 
//error type
typedef struct s_error
{
	int	remove_token;
	int	remove_dir;
	int	add_pipe;
} t_error;

//-----------------------------------------------------------------
//PARSER FUNCTIONS
//-----------------------------------------------------------------
t_pipe	*parser(t_token **chain);
//-----------------------------------------------------------------
//PARSER HELPER FUNCTIONS
//-----------------------------------------------------------------
size_t	ft_pipelen(t_token *chain);
t_pipe	*ft_get_last_pipe(t_pipe *pipeline);
t_pipe	*ft_new_pipe(t_token **chain);
void	ft_add_pipe(t_pipe **pipeline, t_token **chain);
//-----------------------------------------------------------------
//PARSER HELPER 2 FUNCTIONS
//-----------------------------------------------------------------
t_redirect	*ft_get_red_chain(t_token s*cmd_chain);
void		ft_purify_cmd_chain(t_token *cmd_chain);
t_token		*ft_get_cmd_chain(t_token **chain);
//-----------------------------------------------------------------
//REDIRECTION HELPER FUNCTIONS
//-----------------------------------------------------------------
t_redirect	*ft_new_redir(t_redirect_type type, char *target);
t_redirect	*ft_get_last_redir(t_redirect *red_chain);
void		ft_add_redir(t_redirect **red_chain, t_redirect *redirect);
size_t		ft_redirlen(t_redirect *red_chain);
//-----------------------------------------------------------------
//TOKENS HELPER FUNCTIONS
//-----------------------------------------------------------------
t_token	*ft_new_token(t_token_type type, char *str);
t_token	*ft_get_last_token(t_token *chain);
void	ft_add_token(t_token **chain, t_token *token);
size_t	ft_chainlen(t_token *chain);
//-----------------------------------------------------------------
//CLEANER FUNCTIONS
//-----------------------------------------------------------------
void	ft_clear_token(t_token **chain, t_token *token);
//-----------------------------------------------------------------
//CLEANER HELPER FUNCTIONS
//-----------------------------------------------------------------
void	ft_clear_head_token(t_token **chain);