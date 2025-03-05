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

int	ft_check_walls(char **map_copy, int	row_size, int row_amount )
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < row_amount)
	{
		if (map_copy[y][0] != '1' || map_copy[y][row_size - 1] != '1')
			return (1);
		y++;
	}
	while (x < row_size)
	{
		if (map_copy[0][x] != '1' || map_copy[row_amount - 1][x] != '1')
			return (1);
		x++;
	}
}

int	ft_check_minimum_rows(char **map)
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
