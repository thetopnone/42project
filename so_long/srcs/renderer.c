/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:21:52 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/06 20:21:55 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//This function grabs all the needed images for the game
//ADD FT_CHECK_IMAGES_VALID FUNCTION
int	ft_get_images(t_mlx *mlx, t_data *data)
{
	mlx->img.idle1 = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Idle1.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.wall = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Wall.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.floor = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Floor.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.c_exit = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Closed_exit.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.exit = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Exit.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.coll = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Collectible.xpm", &mlx->img.w, &mlx->img.h);
	mlx->img.ce_idle1 = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Ce_idle1.xpm", &mlx->img.w, &mlx->img.h);
	return (data->error->image_get_error = 0);
}

//This will render the map
void	ft_put_map_to_win(t_mlx *mlx, t_data *data, int i, int j)
{
	i = 0;
	while (i < data->map->rows)
	{
		j = 0;
		while (j < data->map->columns)
		{
			if (data->map->map_arr[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx,
					mlx->window, mlx->img.wall, j * 32, i * 32);
			if (data->map->map_arr[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx,
					mlx->window, mlx->img.floor, j * 32, i * 32);
			if (data->map->map_arr[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx,
					mlx->window, mlx->img.c_exit, j * 32, i * 32);
			if (data->map->map_arr[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx,
					mlx->window, mlx->img.idle1, j * 32, i * 32);
			if (data->map->map_arr[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx,
					mlx->window, mlx->img.coll, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

//UPDATES THE IMAGE ACCORDINGLY
void	ft_update_map(t_mlx *mlx, t_data *data, t_player *player)
{
	if (data->map->map_arr[player->old_pos.x][player->old_pos.y] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.c_exit,
			player->old_pos.y * 32, player->old_pos.x * 32);
	else
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.floor,
			player->old_pos.y * 32, player->old_pos.x * 32);
	}
	if (data->map->map_arr[player->new_pos.x][player->new_pos.y] == 'C')
	{
		player->pocket++;
		data->map->map_arr[player->new_pos.x][player->new_pos.y] = '0';
	}
	if (data->map->map_arr[player->new_pos.x][player->new_pos.y] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.ce_idle1,
			player->new_pos.y * 32, player->new_pos.x * 32);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.idle1,
			player->new_pos.y * 32, player->new_pos.x * 32);
	if (player->pocket == data->map->collectibles)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.exit,
			data->map->exit.y * 32, data->map->exit.x * 32);
	player->old_pos.x = player->new_pos.x;
	player->old_pos.y = player->new_pos.y;
}
