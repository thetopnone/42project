/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:32:02 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/04 17:32:04 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_valid_move(t_data *data, t_vector new_pos)
{
	if (data->map->map_arr[new_pos.x][new_pos.y] == '1')
		return (0);
	data->player->moves++;
	data->player->moving = 1;
	ft_printf("MOVES : %d\n", data->player->moves);
	if (data->map->map_arr[new_pos.x][new_pos.y] == 'E'
		&& data->player->pocket == data->map->collectibles)
		ft_close_program(data);
	if (data->map->map_arr[new_pos.x][new_pos.y] == 'X')
		ft_close_program(data);
	return (1);
}

static void	ft_update_position(t_data *data, char axis, int modifer)
{
	if (axis == 'x')
	{
		data->player->new_pos.x = data->player->old_pos.x + modifer;
		data->player->new_pos.y = data->player->old_pos.y;
	}
	else
	{
		data->player->new_pos.x = data->player->old_pos.x;
		data->player->new_pos.y = data->player->old_pos.y + modifer;
	}
	if (ft_valid_move(data, data->player->new_pos))
		ft_update_map(data);
	return ;
}

int	ft_key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_close_program(data);
	if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
		ft_update_position(data, 'x', -1);
	else if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		ft_update_position(data, 'x', 1);
	else if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		ft_update_position(data, 'y', -1);
	else if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		ft_update_position(data, 'y', 1);
	return (0);
}
