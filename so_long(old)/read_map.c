/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:55:12 by akonstan          #+#    #+#             */
/*   Updated: 2025/03/06 14:28:21 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_and_close(char *mem, int fd)
{
	free(mem);
	close(fd);
}

int	ft_map_size(t_data *data)
{
	char	*line;
	int		fd;

	fd = open(data->map->mapfile, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (data->error->rows_error = 1);
	data->map->columns = ft_strlen(line);
	data->map->rows = 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) != data->map->columns)
		{
			ft_free_and_close(line, fd);
			return (data->error->columns_error = 1);
		}
		data->map->rows += 1;
		free(line);
	}
	close(fd);
	return (data->error->columns_error = 0);
}

int	ft_check_minimum_rows(t_data *data)
{
	if (data->map->rows < 3)
		return (data->error->rows_error = 1);
	return (data->error->rows_error = 0);
}

int	ft_read_map(t_data *data)
{
	char	*line;
	int		fd;

	data->map->x = 0;
	data->map->map_arr = ft_calloc((data->map->rows) + 1, sizeof(char *));
	fd = open(data->map->mapfile, O_RDONLY);
	if (fd < 0 || data->map->map_arr == NULL)
	{
		ft_free_and_close(data->map->map_arr, fd);
		return (data->error->map_read_error = 1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[(data->map->columns) - 1] == '\n')
			line[(data->map->columns) - 1] = '\0';
		data->map->map_arr[data->map->x] = line;
		data->map->x += 1;
	}
	data->map->map_arr[data->map->x] = NULL;
	close(fd);
	return (data->error->map_read_error = 0);
}

int	ft_duplicate_map(t_data *data)
{
	int	x;

	data->map->map_copy = ft_calloc(data->map->rows + 1, sizeof(char *));
	if (data->map->map_copy == NULL)
		return (data->error->map_copy_error = 1);
	x = 0;
	while (data->map->map_arr[x] != NULL)
	{
		data->map->map_copy[x] = ft_strdup(data->map->map_arr[x]);
		x++;
	}
	data->map->map_copy[x] = NULL;
	return (data->error->map_copy_error = 0);
}

/*int	main(void)
{
	char	**map;
	int	i = 0;
	
	map = ft_read_map("map1.ber");
	while (i < 5)
	{
		ft_printf("%s\n", *(map + i));
		free(*(map + i));
		i++;
	}
	free(map);
	return (0);
}*/
