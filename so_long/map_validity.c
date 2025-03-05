/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:16:39 by akonstan          #+#    #+#             */
/*   Updated: 2025/03/05 12:24:59 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls(char **map)
{

}

int	ft_check_minimum_size(char **map)
{
	char	*row;
	int		counter;

	row = *map;
	if (row == NULL)
		return (1);
	counter = 1;
	while (1)
	{
		row = *(map + counter);
		if (row == NULL)
			break ;
		counter++;
	}
	if (counter < 3)
		return (1);
	return (0);
}

int	ft_check_shape(char **map)
{
	int		fd;
	char	*row;
	int		len;
	int		counter;

	row = *map;
	if (row != NULL)
		return (1);
	len = ft_strlen(row);
	counter = 1;
	while (1)
	{
		row = *(map + counter);
		if (row != NULL && (ft_strlen(row) != len))
		{
			free(row);
			return (1);
		}
		if (row == NULL)
			break ;
		counter++;
		free(row);
	}
	return (0);
}

int	ft_map_validity(char *mapfile)
{

}
