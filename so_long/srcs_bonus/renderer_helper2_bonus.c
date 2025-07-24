/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_helper2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:20:32 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/08 20:20:34 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_player_images(t_mlx *mlx)
{
	mlx->img.idle[0] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Idle1.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.idle[1] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Idle2.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.ce_idle[0] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Ce_idle1.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.ce_idle[1] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Ce_idle2.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.walk[0] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Walk.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.walk[1] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Walk_ce.xpm", &mlx->img.w, &mlx->img.h);
}

void	ft_animate_walk(t_mlx *mlx, t_data *data, t_player *player)
{
	if (player->old_pos.x == data->map->exit.x
		&& player->old_pos.y == data->map->exit.y)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.walk[1],
			player->old_pos.y * 32, player->old_pos.x * 32);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.walk[0],
			player->old_pos.y * 32, player->old_pos.x * 32);
	player->timer++;
	if (player-> timer > 3000)
	{
		player->moving = 0;
		player->timer = 0;
	}
}

void	ft_animate_idle(t_mlx *mlx, t_data *data, t_player *player)
{
	unsigned int	k;

	k = data->frame / 8000;
	if (data->map->map_arr[player->new_pos.x][player->new_pos.y] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.ce_idle[k % 2],
			player->old_pos.y * 32, player->old_pos.x * 32);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.idle[k % 2],
			player->old_pos.y * 32, player->old_pos.x * 32);
}

int	ft_animate_player(t_data *data)
{
	if (data->player->moving == 1)
		ft_animate_walk(data->mlx, data, data->player);
	else
		ft_animate_idle(data->mlx, data, data->player);
	data->frame++;
	return (0);
}

void	ft_allocate_images(t_mlx *mlx)
{
	mlx->img.nums = ft_calloc(10, sizeof(void *));
	mlx->img.idle = ft_calloc(2, sizeof(void *));
	mlx->img.ce_idle = ft_calloc(2, sizeof(void *));
	mlx->img.walk = ft_calloc(2, sizeof(void *));
}
