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

#include "so_long_bonus.h"

//Grabs the number images and initialized the nums array
static int	ft_get_num_images(t_mlx *mlx, t_data *data)
{
	mlx->img.nums[0] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n0.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[1] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n1.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[2] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n2.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[3] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n3.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[4] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n4.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[5] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n5.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[6] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n6.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[7] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n7.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[8] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n8.xpm", &mlx->img.n_w, &mlx->img.n_h);
	mlx->img.nums[9] = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/n9.xpm", &mlx->img.n_w, &mlx->img.n_h);
	return (data->error->image_get_error = 0);
}

//This function grabs all the needed images for the game
//ADD FT_CHECK_IMAGES_VALID FUNCTION
int	ft_get_images(t_mlx *mlx, t_data *data)
{
	ft_allocate_images(mlx);
	ft_get_player_images(mlx);
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
	mlx->img.enemy = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Enemy1.xpm", &mlx->img.w, &mlx->img.h);
	ft_get_num_images(mlx, data);
	return (data->error->image_get_error = 0);
}

//This will render the map
void	ft_put_map_to_win(t_mlx *mlx, t_data *data, int i, int j)
{
	i = 0;
	while (i < data->map->rows)
	{
		j = 0;
		while (j < data->map->columns - 1)
		{
			ft_put_node_to_win(mlx, data, i, j);
			j++;
		}
		i++;
	}
}

//UPDATES THE IMAGE ACCORDINGLY
int	ft_update_map(t_data *data)
{
	ft_update_floor_and_exits(data->mlx, data, data->player);
	ft_update_collectibles(data, data->player);
	ft_update_numbers(data->mlx, data->player);
	if (data->player->pocket == data->map->collectibles)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->window,
			data->mlx->img.exit, data->map->exit.y * 32,
			data->map->exit.x * 32);
	data->player->old_pos.x = data->player->new_pos.x;
	data->player->old_pos.y = data->player->new_pos.y;
	return (0);
}
