/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:19:56 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/10 18:48:49 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*cur_char;
	char	*last_occ;

	cur_char = (char *)s;
	last_occ = NULL;
	while (*cur_char)
	{
		if (c == (unsigned char)*cur_char)
			last_occ = cur_char;
		cur_char++;
	}
	if (c == '\0')
		return (cur_char);
	return (last_occ);
}
