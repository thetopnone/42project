/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:16:39 by akonstan          #+#    #+#             */
/*   Updated: 2025/03/06 15:55:41 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map->columns)
	{
		if (data->map->map_arr[y][0] != '1' ||
		data->map->map_arr[y][data->map->rows - 1] != '1')
			return (data->error->walls_error = 1);
		y++;
	}
	while (x < data->map->rows)
	{
		if (data->map->map_arr[0][x] != '1' ||
		data->map->map_arr[data->map->columns - 1][x] != '1')
			return (data->error->walls_error = 1);
		x++;
	}
	return (data->error->walls_error = 0);
}

int	ft_check_minimum_rows(t_data *data)
{
	if (data->map->rows < 3)
		return (data->error->rows_error = 1);
	return (data->error->rows_error = 0);
}

int	ft_map_objects(t_data *data)
{
	int x;
	int	y;

	x = 0;
	while (data->map->map_arr[x] != NULL)
	{
		y = 0;
		while (data->map->map_arr[y][x] != '\0')
		{
			if (data->map->map_arr[y][x] == 'P')
				data->map->starts += 1;
			if (data->map->map_arr[y][x] == 'E')
				data->map->exits += 1;
			if (data->map->map_arr[y][x] == 'C')
				data->map->collectibles += 1;
			y++;
		}
		x++;
	}
	if (data->map->starts != 1 || data->map->exits != 1 ||
	data->map->collectibles < 1)
		return (data->error->objects_error = 1);
	return (data->error->objects_error = 0);
}

int	ft_check_valid_path(t_data *data)
{
	int	start;
	int	end;
	int	*visited;

	visited = ft_calloc(data->map->rows, sizeof(int *));
	start = 0;
	end = 0;
	data->map->queue = ft_calloc(data->map->rows * data->map->columns, 
	sizeof(t_point));
	data->map->queue[0] = data->

}
