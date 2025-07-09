/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_helper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:36:08 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/08 15:36:10 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_update_floor_and_exits(t_mlx *mlx, t_data *data, t_player *player)
{
	if (data->map->map_arr[player->old_pos.x][player->old_pos.y] == 'E'
				&& player->pocket != data->map->collectibles)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.c_exit,
			player->old_pos.y * 32, player->old_pos.x * 32);
	else
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.floor,
			player->old_pos.y * 32, player->old_pos.x * 32);
	}
}

void	ft_update_collectibles(t_data *data, t_player *player)
{
	if (data->map->map_arr[player->new_pos.x][player->new_pos.y] == 'C')
	{
		player->pocket++;
		data->map->map_arr[player->new_pos.x][player->new_pos.y] = '0';
	}
}

void	ft_update_numbers(t_mlx *mlx, t_player *player)
{
	int	index;
	int	ref;
	int	i;

	i = 0;
	ref = player->moves;
	while (ref > 0 && i < 4)
	{
		index = ref % 10;
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.nums[index],
			24 - (i * 8), 0);
		ref /= 10;
		i++;
	}
}

void	ft_put_node_to_win(t_mlx *mlx, t_data *data, int i, int j)
{
	if (data->map->map_arr[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->img.wall, j * 32, i * 32);
	if (data->map->map_arr[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->img.floor, j * 32, i * 32);
	if (data->map->map_arr[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->img.c_exit, j * 32, i * 32);
	if (data->map->map_arr[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->img.idle[0], j * 32, i * 32);
	if (data->map->map_arr[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->img.coll, j * 32, i * 32);
	if (data->map->map_arr[i][j] == 'X')
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->img.enemy, j * 32, i * 32);
}
