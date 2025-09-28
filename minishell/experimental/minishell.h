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
# include <stdlib.c>
# include <unistd.h>
# include <stdio.h>
# include <read/read.h>
# include <read/history.h>
# include <fcntl.h>
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
	T_PIPE,
	T_END
} t_token_type;

//Token structure which the lexer will give as output
typedef struct s_token
{
	char				*string;
	enum t_token_type	type;
	bool				is_single_quoted;
	bool				is_double_quoted;
	struct t_token		*next;
} t_token;

//Redirections structure, shows what kind of redirection we have and
//where it should target
typedef struct s_redirect
{
	enum t_redirect_type	type;
	char					*target_file;
} t_redirect;

//Command struct that holds the actuall command to execute and any 
//redirections (if the exist)
typedef struct s_cmd
{
	char		**argv;
	t_redirect	*redirection;
} t_cmd;

//Pipe structure that holds the command on the current pipe and
//a pointer pointing to the next pipe
typedef struct s_pipe
{
	t_cmd			*command;
	unsigned int	cmd_amount;
	struct t_pipe	*next;
} t_pipe;

//Parser functions
t_pipe		**parser(t_token **tokens);
