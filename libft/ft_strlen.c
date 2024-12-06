/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:11:22 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/06 18:42:51 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	counter;
	const char	*refer;

	refer = s;
	counter = 0;
	while(*refer)
	{
		counter++;
		refer++;	
	}
	return (counter);
}
