/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:49:51 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/24 17:48:32 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*start_of_arr;
	int	array_size;

	if (min >= max)
	{
		*range = NULL;
		return (-1);
	}
	array_size = max - min;
	*range = malloc(array_size * sizeof(int));
	if (*range == NULL)
		return (-1);
	start_of_arr = *range;
	while (min < max)
	{
		*start_of_arr = min;
		min++;
		start_of_arr++;
	}
	return(array_size);
}
