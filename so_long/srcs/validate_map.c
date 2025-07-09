/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:23:13 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/01 13:23:15 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_valid_vector(t_data *data, t_vector vector)
{
	if (vector.x < 0 || vector.y < 0 || vector.x >= data->map->rows
		|| vector.y >= data->map->columns)
		return (1);
	if (data->map_dup[vector.x][vector.y] == '1')
		return (1);
	return (0);
}

//Checks if the map characters are valid and have the correct count
int	ft_valid_char(t_data *data, t_map *map)
{
	t_vector	v;
	char		c;

	v.x = 0;
	while (v.x < data->map->rows)
	{
		v.y = 0;
		while (v.y < data->map->columns - 1)
		{
			c = data->map->map_arr[v.x][v.y];
			if (!(c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C'))
				return (data->error->invalid_map = 1);
			if (c == 'P')
				data->map->spawn_am += 1;
			else if (c == 'E')
				data->map->exit_am += 1;
			else if (c == 'C')
				data->map->collectibles += 1;
			v.y++;
		}
		v.x++;
	}
	if (map->collectibles == 0 || map->spawn_am != 1 || map->exit_am != 1)
		return (data->error->invalid_map = 1);
	return (data->error->invalid_map = 0);
}

//Checks if the Walls are '1's (Valid Border Has columns - 1 reduced to
//check the right index of the map_arr
int	ft_valid_border(t_data *data)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y < data->map->columns - 1)
	{
		if (data->map->map_arr[0][pos.y] != '1'
			|| data->map->map_arr[data->map->rows - 1][pos.y] != '1')
			return (data->error->map_struct_error = 1);
		pos.y++;
	}
	pos.x = 0;
	while (pos.x < data->map->rows - 1)
	{
		if (data->map->map_arr[pos.x][0] != '1'
			|| data->map->map_arr[pos.x][data->map->columns - 2] != '1')
			return (data->error->map_struct_error = 1);
		pos.x++;
	}
	return (data->error->map_struct_error = 0);
}

//Updates the queue in the data base
static void	ft_update_queue(t_data *data, t_vector old_pos, int *back)
{
	int			j;
	t_vector	next_pos;

	j = 0;
	while (j < 4)
	{
		if (j < 2)
		{
			next_pos.x = old_pos.x + (int)pow(-1, j);
			next_pos.y = old_pos.y;
		}
		else
		{
			next_pos.x = old_pos.x;
			next_pos.y = old_pos.y + (int)pow(-1, j);
		}
		if (ft_valid_vector(data, next_pos) == 0
			&& data->visited[next_pos.x][next_pos.y] == 0)
		{
			data->queue[(*back)++] = next_pos;
			data->visited[next_pos.x][next_pos.y] = 1;
		}
		j++;
	}
}

//Checks for valid path. On succes rsets error to 0 else sets to 1
int	ft_check_valid_path(t_data *data, int front, int back)
{
	t_vector	cur_pos;
	int			exit_visited;

	exit_visited = 0;
	data->queue[back++] = data->map->spawn;
	data->visited[data->map->spawn.x][data->map->spawn.y] = 1;
	while (front < back)
	{
		cur_pos = data->queue[front];
		if (data->map_dup[cur_pos.x][cur_pos.y] == 'C')
		{
			data->map_dup[cur_pos.x][cur_pos.y] = '0';
			data->map->collected++;
		}
		if (data->map_dup[cur_pos.x][cur_pos.y] == 'E')
			exit_visited = 1;
		ft_update_queue(data, cur_pos, &back);
		front++;
	}
	if (exit_visited && data->map->collected == data->map->collectibles)
		return (data->error->map_struct_error = 0);
	return (data->error->map_struct_error = 1);
}
