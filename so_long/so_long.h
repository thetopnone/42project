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
# include <fctl.h>

//----------Macros-------------//

# define IMG_WIDTH 32
# define IMG_HEIGHT 32


//----------Map-Data-Struct-------------//

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		collectibles;
	int		exit;
	int		player_start;
	char	**copy;
}	t_map;

//----------Player-Data-Struct---------//

typedef struct s_player
{
	int		position_x;
	int		position_y;
}	t_player;

//---------Main-Data-Struct---------//

typedef struct s_data
{
	int		move_count;
	int		collected_items;
	int		win_size_x;
	int		win_size_y;
	t_player	*player;
	t_map		*map;

}	t_data;

#endif
