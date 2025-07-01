/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:16:39 by akonstan          #+#    #+#             */
/*   Updated: 2025/03/10 15:16:48 by akonstan         ###   ########.fr       */
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
		if (data->map->map_arr[0][y] != '1' ||
		data->map->map_arr[data->map->rows - 1][y] != '1')
			return (data->error->walls_error = 1);
		y++;
	}
	while (x < data->map->rows)
	{
		if (data->map->map_arr[x][0] != '1' ||
		data->map->map_arr[x][data->map->columns - 1] != '1')
			return (data->error->walls_error = 1);
		x++;
	}
	return (data->error->walls_error = 0);
}

int	ft_map_objects(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map->map_arr[x] != NULL)
	{
		y = 0;
		while (data->map->map_arr[x][y] != '\0')
		{
			if (data->map->map_arr[x][y] == 'P')
				data->map->starts += 1;
			if (data->map->map_arr[x][y] == 'E')
				data->map->exits += 1;
			if (data->map->map_arr[x][y] == 'C')
				data->map->clcts += 1;
			y++;
		}
		x++;
	}
	if (data->map->starts != 1 || data->map->exits != 1
		|| data->map->clcts < 1)
		return (data->error->objects_error = 1);
	return (data->error->objects_error = 0);
}

int	ft_valid_point(t_data *data, t_point point)
{
	if (point.x < 0 || point.y < 0 || point.x >= data->map->rows
		|| point.y >= data->map->columns)
		return (1);
	if (data->map->map_arr[point.x][point.y] == '1')
		return (1);
	return (0);
}

void	ft_update_queue(t_data data, t_point old, int	*back)
{
	t_point	next_pos;
	int		j;

	j = 0;
	while (j < 4)
	{
		if (j < 2)
		{
			next_pos.x = old.x + (int)pow(-1, j);
			next_pos.y = old.y;
		}
		else
		{
			next_pos.y = old.y + (int)pow(-1, j);
			next_pos.x = old.x;
		}
		if (ft_valid_point(data, next_pos) == 0
			&& data->visited[next_pos.x][next_pos.y] == 0)
		{
			data->map->queue[*back] = next_pos;
			(*back)++;
			data->visited[next_pos.x][next_pos.y] = 1;
		}
		j++;
	}
}

int	ft_check_valid_path(t_data *data)
{
	int		front;
	int		back;
	t_point	cur_pos;

	front = 0;
	back = 0;
	data->map->queue = ft_calloc(data->map->rows * data->map->columns,
			sizeof(t_point));
	data->map->queue[back++] = data->map->start_pos;
	data->visited[data->map->start_pos.x][data->map->start_pos.y] = 1;
	while (front < back)
	{
		cur_pos = data->map->queue[front++];
		if (ft_pos_tr(data, cur_pos) == 'E'
			&& data->map->clctd == data->map->clcts)
		{
			free(data->map->queue);
			return (1);
		}
		ft_update_queue(data, cur_pos, &back);
	}
	return (0);
}
