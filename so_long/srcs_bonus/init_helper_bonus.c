/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:19:02 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/08 15:19:05 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//This calls the validity check functions
void	ft_check_map_validity(t_data *data)
{
	ft_valid_char(data, data->map);
	ft_valid_border(data);
	ft_check_valid_path(data, 0, 0);
}
