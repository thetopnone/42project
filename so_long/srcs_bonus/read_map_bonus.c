/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:53 by akonstan          #+#    #+#             */
/*   Updated: 2025/06/30 18:29:55 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_free_and_close(void *memory, int fd)
{
	free(memory);
	close(fd);
	get_next_line(-1);
}

//calculates rows and columns in data
int	ft_get_map_size(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->map->mapfile, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (data->error->map_read_error = 1);
	data->map->rows = 1;
	data->map->columns = ft_strlen(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) != data->map->columns)
		{
			ft_free_and_close(line, fd);
			return (data->error->map_size_error = 1);
		}
		data->map->rows++;
		free(line);
	}
	ft_free_and_close(line, fd);
	return (data->error->map_size_error = 0);
}

int	ft_check_window_size(t_data *data)
{
	if ((data->map->columns - 1) * 32 > MAX_WIN_WIDTH
		|| data->map->rows * 32 > MAX_WIN_HEIGHT)
		return (data->error->map_size_error = 1);
	return (data->error->map_size_error = 0);
}

int	ft_read_mapfile(t_data *data, int i)
{
	int		fd;
	char	*line;

	data->map->map_arr = ft_calloc(data->map->rows + 1, sizeof(char *));
	fd = open(data->map->mapfile, O_RDONLY);
	if (fd < 0)
	{
		ft_free_and_close(data->map->map_arr, fd);
		return (data->error->map_read_error = 1);
	}
	while (i < data->map->rows)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map->map_arr[i] = line;
		data->map->map_arr[i++][data->map->columns - 1] = '\0';
	}
	data->map->map_arr[i] = NULL;
	close(fd);
	get_next_line(-1);
	return (data->error->map_read_error = 0);
}

//Get the span position and the exit position
void	ft_get_spawn_and_exit(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns - 1)
		{
			if (map->map_arr[x][y] == 'P')
			{
				map->spawn.x = x;
				map->spawn.y = y;
			}
			if (map->map_arr[x][y] == 'E')
			{
				map->exit.x = x;
				map->exit.y = y;
			}
			y++;
		}
		x++;
	}
}
