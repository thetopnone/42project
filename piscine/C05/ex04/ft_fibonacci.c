/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:33:31 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/23 12:46:41 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_fibonacci(int index)
{
	int	result;

	result = -1;
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index > 1)
		result = ft_fibonacci(index - 2) + ft_fibonacci(index -1);
	return (result);
}
/*
int	main(void)
{
	printf("%d", ft_fibonacci(7));
	return (0);
}*/
