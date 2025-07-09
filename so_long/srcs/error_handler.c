/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:16:24 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/02 19:16:25 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_error_check(t_data *data)
{
	if (data->error->map_read_error)
		return (1);
	else if (data->error->map_size_error)
		return (1);
	else if (data->error->map_struct_error)
		return (1);
	else if (data->error->invalid_map)
		return (1);
	else if (data->error->queue_alloc_error)
		return (1);
	else if (data->error->visited_alloc_error)
		return (1);
	else if (data->error->image_get_error)
		return (1);
	return (0);
}

size_t	ft_final_error_check(t_data *data)
{
	if (data->error->map_read_error)
		return (ft_printf("Error\nMAP READ ERROR\n"));
	else if (data->error->map_size_error)
		return (ft_printf("Error\nMAP SIZE ERROR\n"));
	else if (data->error->map_struct_error)
		return (ft_printf("Error\nMAP STRUCTURE ERROR\n"));
	else if (data->error->invalid_map)
		return (ft_printf("Error\nIVALID MAP CHARACTERS\n"));
	else if (data->error->queue_alloc_error)
		return (ft_printf("Error\nQueue"));
	else if (data->error->visited_alloc_error)
		return (ft_printf("Error\nVisited"));
	else if (data->error->image_get_error)
		return (ft_printf("Error\nImage get error\n"));
	return (0);
}
