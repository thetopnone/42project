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

#include "so_long.h"

static void	ft_free_and_close(void *memory, int fd)
{
	free(memory);
	close(fd);
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
		if (ft_strlen(line) != data->map->columns)
		{
			ft_free_and_close(line, fd);
			return (data->error->map_size_error = 1);
		}
		data->map->rows++;
		free(line);
	}
	close(fd);
	return (data->error->map_size_error = 0);
}

int	ft_read_mapfile(t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->map->map_arr = ft_calloc(data->map->rows + 1, sizeof(char *));
	if (!data->map->map_arr)
		return (data->error->map_read_error = 1);
	fd = open(data->map->mapfile, O_RDONLY);
	if (fd < 0)
	{
		free_and_close(data->map->map_arr, fd);
		return (data->error->map_read_error = 1);
	}
	while (i < data->map->rows)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map->map_arr[i++] = line;
		free(line);
	}
	data->map->map_arr[i] = NULL;
	close(fd);
	return (data->error->map_read_error = 0);
}
