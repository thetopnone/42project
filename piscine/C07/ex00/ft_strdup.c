/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:45:49 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/24 15:14:47 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strsize(char *str)
{
	int		strsize;
	char	*refer_to_str;

	strsize = 0;
	refer_to_str = str;
	while (*refer_to_str)
	{
		strsize++;
		refer_to_str++;
	}
	return (strsize);
}

char	*ft_strdup(char *src)
{
	char	*duplicate;
	char	*refer_to_src;
	char	*start_of_duplicate;

	refer_to_src = src;
	duplicate = malloc(ft_strsize(src) * sizeof(char) + 1);
	if (duplicate == NULL)
		return (NULL);
	start_of_duplicate = duplicate;
	while (*refer_to_src)
	{
		*duplicate = *refer_to_src;
		duplicate++;
		refer_to_src++;
	}
	*duplicate = '\0';
	duplicate = start_of_duplicate;
	return (duplicate);
}
