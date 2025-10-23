/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:31:19 by akonstan          #+#    #+#             */
/*   Updated: 2025/10/02 17:54:00 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_freearr(char **arr, size_t index)
{
	while (index > 0)
	{
		index--;
		free(arr[index]);
	}
	free(arr);
}

size_t	ft_word_amount(char *s, char c, t_error *err)
{
	t_word_amount	state;

	ft_bzero(&state, sizeof(t_word_amount));
	while (*s)
	{
		if (*s == '"' || *s == '\'' || *s == '>' || *s == '<')
			ft_handle_quo_red_wa(&s, &state);
		else if (*s == c && !(state.in_squote || state.in_dquote))
		{
			state.in_word = 0;
			s++;
		}
		else if (*s != c && state.in_word == 0)
		{
			state.in_word = 1;
			state.words++;
			s++;
		}
		else
			s++;
	}
	if (state.in_squote || state.in_dquote)
		err->word_amount = 1;
	return (state.words);
}

//Added redirection case where it will always treat redirections
//and the target as different tokens
//Also fixed a small bug for starting or trailing spaces (check)
char	*ft_write_word(char **s, char c)
{
	t_write_word	init;
	static int		redir;

	ft_bzero(&init, sizeof(t_write_word));
	init.start = *s;
	while (**s)
	{
		if (**s == '"' || **s == '\'' || **s == '>' || **s == '<')
		{
			if (ft_handle_quo_red_ww(s, &redir, &init.i))
				break ;
		}
		else if (**s == c)
			break ;
		(*s)++;
		init.i++;
	}
	init.word = malloc((*s - init.start + 1) * sizeof(char));
	if (!init.word)
		return (NULL);
	ft_strlcpy(init.word, init.start, *s - init.start + 1);
	return (init.word);
}

//(Check)
int	ft_split_logic(char **str_arr, char *s, char c)
{
	size_t		index;
	int			quote;

	index = 0;
	quote = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			str_arr[index] = ft_write_word(&s, c);
			if (!str_arr[index])
			{
				ft_freearr(str_arr, index);
				return (0);
			}
			index++;
		}
	}
	str_arr[index] = NULL;
	return (1);
}

char	**ft_split_mini(char *s, char c, t_error *err)
{
	char		**str_arr;

	if (!s || *s == '\0')
	{
		str_arr = malloc(1 * sizeof(char *));
		str_arr[0] = NULL;
		return (str_arr);
	}
	str_arr = malloc((ft_word_amount(s, c, err) + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	if (!ft_split_logic(str_arr, s, c))
	{
		free(str_arr);
		return (NULL);
	}
	return (str_arr);
}

/*int	main(int argc, char *argv[])
{
	char	**array;
	int	i;

	array = ft_split_mini(argv[1], ' ');
	i = -1;
	while (array[++i])
		printf("ARRAY[%i]: %s\n",i , array[i]);
}*/
