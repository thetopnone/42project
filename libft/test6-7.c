/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6-7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:39:34 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/19 18:59:51 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	size_t	size;
	char	*buffer;
	size_t	i;

	i = 0;
	size = 50;
	buffer = malloc(size);
	if (!buffer)
		return (1);

	ft_memset((void *)buffer, 'k', size);
	while (i < size)
	{
		if (buffer[i] != 'k')
		{
			printf("memset error \n");
			return (1);
		}
		i++;
	}
	i = 0;
	ft_bzero((void *)buffer, size);
	while (i < size)
	{
		if (buffer[i] != 0)
		{
			printf("Bzero error \n");
			return (1);
		}
		i++;
	}
	free(buffer);
	printf("All ok\n");
	return (0);
}
