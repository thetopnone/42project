/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trackers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:11:56 by akonstan          #+#    #+#             */
/*   Updated: 2025/03/07 15:33:08 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_pos_tr(t_data *data, t_point cur_pos)
{
	if (data->map->map_arr[cur_pos.y][cur_pos.x] == 'C')
	{
		data->map->clctd++;
		return ('C');
	}
	if (data->map->map_arr[cur_pos.y][cur_pos.x] == '1')
		return ('1');
	if (data->map->map_arr[cur_pos.y][cur_pos.x] == '0')
		return ('0');
	if (data->map->map_arr[cur_pos.y][cur_pos.x] == 'E')
		return ('E');
	data->error->map_input_error = 1;
	return (1);
}
