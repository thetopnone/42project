/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:18:49 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/08 15:18:51 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Frees the queue and visited array after usage
static void	ft_free_queue_and_visited(t_data *data)
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

static void	ft_free_data(t_data *data)
{
	if (data->player)
		free(data->player);
	if (data->map)
		free(data->map);
	if (data->error)
		free(data->error);
	if (data->mlx->img.idle)
		free(data->mlx->img.idle);
	if (data->mlx->img.ce_idle)
		free(data->mlx->img.ce_idle);
	if (data->mlx->img.nums)
		free(data->mlx->img.nums);
	if (data->mlx->img.walk)
		free(data->mlx->img.walk);
	if (data->mlx->mlx)
		free(data->mlx->mlx);
	if (data->mlx)
		free(data->mlx);
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
