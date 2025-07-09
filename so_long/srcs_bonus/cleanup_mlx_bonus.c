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

#include "so_long_bonus.h"

//Helper function to kill the animations
static void	ft_kill_animation(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.idle[i]);
		mlx_destroy_image(mlx->mlx, mlx->img.ce_idle[i]);
		mlx_destroy_image(mlx->mlx, mlx->img.walk[i]);
		i++;
	}
}

//Helper function to kill number images
static void	ft_kill_num_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (mlx->img.nums[i])
		{
			mlx_destroy_image(mlx->mlx, mlx->img.nums[i]);
			i++;
		}
	}
	return ;
}

//This function destroys all image instances
void	ft_kill_images(t_mlx *mlx)
{
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
	if (mlx->img.enemy)
		mlx_destroy_image(mlx->mlx, mlx->img.enemy);
	ft_kill_num_images(mlx);
	ft_kill_animation(mlx);
	return ;
}
