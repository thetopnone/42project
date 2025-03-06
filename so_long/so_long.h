/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:02:43 by akonstan          #+#    #+#             */
/*   Updated: 2025/03/05 13:39:32 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

//----------Macros-------------//

# define IMG_WIDTH 32
# define IMG_HEIGHT 32


//----------Map-Data-Struct-------------//

typedef struct s_map
{
	char	*mapfile;
	char	**map_arr;
	char	*queue;
	int		x;//cur_row
	int		y;//cur_col
	int		rows;
	int		columns;
	int		collectibles;
	int		exits;
	int		starts;
	int		exit_pos_x;
	int		exit_pos_y;
	int		start_pos_x;
	int		start_pos_y;
	char	**map_copy;
}	t_map;

//----------Player-Data-Struct---------//

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

//---------Error-Data-Struct--------//
typedef struct s_error
{
	int	columns_error;
	int	rows_error;
	int	walls_error;
	int	path_error;
	int	objects_error;
	int	map_read_error;
	int	map_copy_error;
}	t_error;
//---------Main-Data-Struct---------//

typedef struct s_data
{
	int		move_count;
	int		collected_items;
	int		win_size_x;
	int		win_size_y;
	t_player	*player;
	t_map		*map;
	t_error		*error;

}	t_data;

#endif
