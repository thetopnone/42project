/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:50:50 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/02 16:50:51 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Sets base values to error data struct
static void	ft_initialize_error(t_data *data)
{
	data->error = ft_calloc(1, sizeof(t_error));
	data->error->map_read_error = 0;
	data->error->map_size_error = 0;
	data->error->invalid_map = 0;
	data->error->queue_alloc_error = 0;
	data->error->visited_alloc_error = 0;
	data->error->image_get_error = 0;
	return ;
}

//Sets base values to map data struct
static void	ft_initialize_map(t_data *data, char *argv)
{
	data->map = ft_calloc(1, sizeof(t_map));
	data->map->mapfile = argv;
	data->map->map_arr = NULL;
	data->map->rows = 0;
	data->map->columns = 0;
	data->map->spawn_am = 0;
	data->map->exit_am = 0;
	data->map->spawn.x = 0;
	data->map->spawn.y = 0;
	data->map->exit.x = 0;
	data->map->exit.y = 0;
	data->map->collectibles = 0;
	data->map->collected = 0;
	return ;
}

//Initialize queue and visited arrays
static void	ft_initialize_queue_visited(t_data *data)
{
	int	rows;
	int	columns;
	int	i;

	i = 0;
	rows = data->map->rows;
	columns = data->map->columns;
	data->queue = ft_calloc(rows * columns, sizeof(t_vector));
	if (!data->queue)
		data->error->queue_alloc_error = 1;
	data->visited = ft_calloc(rows, sizeof(int *));
	if (!data->visited)
		data->error->visited_alloc_error = 1;
	while (i < rows)
		data->visited[i++] = ft_calloc(columns, sizeof(int));
}

//Initialize player data variable
static void	ft_initialize_player(t_data *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	data->player->old_pos.x = data->map->spawn.x;
	data->player->old_pos.y = data->map->spawn.y;
	data->player->new_pos.x = 0;
	data->player->new_pos.y = 0;
	data->player->pocket = 0;
	data->player->moves = 0;
}

//Initializes queue, visited, sets rows and cols, assigns the map
//and runs the above initializers
void	ft_initialize_data(t_data *data, char *argv)
{
	data->queue = NULL;
	data->visited = NULL;
	data->mlx = ft_calloc(1, sizeof(t_mlx));
	ft_initialize_error(data);
	if (!data->error)
		return ;
	ft_initialize_map(data, argv);
	if (!data->map)
		return ;
	ft_get_map_size(data);
	ft_check_window_size(data);
	if (ft_error_check(data) != 0)
		return ;
	ft_read_mapfile(data, 0);
	ft_map_dup(data);
	ft_initialize_queue_visited(data);
	ft_get_spawn_and_exit(data->map);
	ft_valid_char(data, data->map);
	ft_valid_border(data);
	ft_check_valid_path(data, 0, 0);
	if (ft_error_check(data) == 0)
		ft_initialize_player(data);
}
