/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 21:25:38 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/05 21:25:47 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//This function destroys all image instances
void	ft_kill_images(t_mlx *mlx)
{
	if (mlx->img.idle1)
		mlx_destroy_image(mlx->mlx, mlx->img.idle1);
	if (mlx->img.floor)
		mlx_destroy_image(mlx->mlx, mlx->img.floor);
	if (mlx->img.c_exit)
		mlx_destroy_image(mlx->mlx, mlx->img.c_exit);
	if (mlx->img.exit)
		mlx_destroy_image(mlx->mlx, mlx->img.exit);
	if (mlx->img.wall)
		mlx_destroy_image(mlx->mlx, mlx->img.wall);
	if (mlx->img.coll)
		mlx_destroy_image(mlx->mlx, mlx->img.coll);
	if (mlx->img.ce_idle1)
		mlx_destroy_image(mlx->mlx, mlx->img.ce_idle1);
	return ;
}

//CLOSES THE WINDOW AND EXIT THE PROGRAM BY CALLING ALL NECESSARY FUNCTIONS
int	ft_close_program(t_data *data)
{
	if (data->mlx)
	{
		ft_kill_images(data->mlx);
		mlx_destroy_window(data->mlx->mlx, data->mlx->window);
		mlx_destroy_display(data->mlx->mlx);
	}
	ft_clear(data);
	exit(0);
	return (0);
}

//Frees the queue and visited array after usage
void	ft_free_queue_and_visited(t_data *data)
{
	int	i;

	i = 0;
	if (data->queue)
		free(data->queue);
	if (data->visited)
	{
		while (i < data->map->rows)
			free(data->visited[i++]);
		free(data->visited);
	}
	return ;
}

//Called when program needs to exit to close all memory allocs
int	ft_clear(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map_arr)
	{
		while (i < data->map->rows)
			free(data->map->map_arr[i++]);
		free(data->map->map_arr);
	}
	i = 0;
	if (data->map_dup)
	{
		while (i < data->map->rows)
			free(data->map_dup[i++]);
		free(data->map_dup);
	}
	if (data->queue || data->visited)
		ft_free_queue_and_visited(data);
	ft_free_data(data);
	return (0);
}

void	ft_free_data(t_data *data)
{
	if (data->player)
		free(data->player);
	if (data->map)
		free(data->map);
	if (data->error)
		free(data->error);
	if (data->mlx->mlx)
		free(data->mlx->mlx);
	if (data->mlx)
		free(data->mlx);
	return ;
}
