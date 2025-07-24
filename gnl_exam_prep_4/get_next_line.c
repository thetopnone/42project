/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:41:03 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/23 19:41:04 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	res;

	if (!s || !(*s))
		return (0);
	res = 0;
	while (*s)
	{
		res++;
		s++;
	}
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

void	ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	counter;

	if(!dest || !src || n == 0)
		return ;
	counter = 0;
	while (counter < n)
	{
		((char*)dest)[counter] = ((char *)src)[counter];
		counter++;
	}
}

void	ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest || !src || n == 0)
		return ;
	if (src < dest && src + n > dest)
	{
		while (n > 0)
		{
			((char *)dest)[n] = ((char *)src)[n];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
}

int	ft_str_append_mem(char **s1, char *s2, size_t size_s2)
{
	char	*tmp;
	size_t	size_s1;

	size_s1 = ft_strlen(*s1);
	tmp = malloc(size_s1 + size_s2 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size_s1);
	ft_memcpy(tmp + size_s1, s2, size_s2);
	tmp[size_s1 + size_s2] = 0;
	free (*s1);
	*s1 = tmp;
	return (1);
}

char	*get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";
	char		*line;
	char		*newline;
	int			read_res;

	line = malloc(1);
	if (!line)
		return (NULL);
	*line = 0;
	if (*b)
		ft_str_append_mem(&line, b, ft_strlen(b));
	newline = NULL;
	while (!newline)
	{
		read_res = read(fd, b, BUFFER_SIZE);
		if (read_res <= 0 && !(*b))
		{
			if (*line)
				return (line);
			free (line);
			return (NULL);
		}
		b[read_res] = 0;
		newline = ft_strchr(b, '\n');
		if (!newline)
			ft_str_append_mem(&line, b, ft_strlen(b));
		else
			ft_str_append_mem(&line, b, newline - b + 1);
	}
	if (newline)
		ft_memmove(b, newline + 1, ft_strlen(newline + 1) + 1);
	return(line);
}
