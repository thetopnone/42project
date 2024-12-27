/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:15:45 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/24 15:49:02 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*int_arr;
	int	*start_of_arr;
	int	array_size;

	if (min >= max)
		return (NULL);
	array_size = max - min;
	if (array_size < 0)
		array_size = -array_size;
	int_arr = malloc(array_size * sizeof(int));
	start_of_arr = int_arr;
	if (int_arr == NULL)
		return (NULL);
	while (min < max)
	{
		*int_arr = min;
		int_arr++;
		min++;
	}
	int_arr = start_of_arr;
	return (int_arr);
}
