/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:04:21 by akonstan          #+#    #+#             */
/*   Updated: 2025/06/30 18:04:25 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <fctrl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

//VECTOR STRUCTURE
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;
//MAP DATA STRUCTURE
typedef struct s_map
{
	const char	*mapfile;
	const char	**map_arr;
	int			rows;
	int			columns;
	int			spawn_count;
	int			exit_count;
	t_vector	spawn;
	t_vector	exit;
	int			collectibles;
	int			collected;
}	t_map;

//ERROR DATA STRUCTURE
typedef struct s_error
{
	int	map_read_error;
	int	map_size_error;
	int	invalid_map;
}	t_error;

//BASE DATA STRUCTURE
typedef struct s_data
{
	t_vector	*queue;//Needs initialization with rows*cols
	int			**visited;//Needs initialization with rows*cols
	t_map		*map;
	t_error		*error;
}	t_data;

#endif