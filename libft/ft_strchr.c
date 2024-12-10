/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:57:31 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/10 18:48:30 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*strrf;

	strrf = (char *)s;
	while (*strrf)
	{
		if (c == (unsigned char)*strrf)
			return (strrf);
		strrf++;
	}
	if (c == '\0')
		return (strrf);
	else
		return (NULL);
}
