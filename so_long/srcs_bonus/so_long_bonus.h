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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include "mlx.h"

//MACROS
# define MAX_WIN_WIDTH 1920
# define MAX_WIN_HEIGHT 1024
# define UP 1
# define DOWN -1
# define RIGHT 2
# define LEFT -2

//VECTOR STRUCTURE
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

//PLAYER DATA STRUCTURE
typedef struct s_player
{
	t_vector		old_pos;
	t_vector		new_pos;
	int				moves;
	int				pocket;
	int				moving;
	unsigned int	timer;
}	t_player;

//IMAGE DATA STRUCTURE
typedef struct s_image
{
	void	**idle;//NEEDS INITIALIZATION
	void	*wall;
	void	*floor;
	void	*c_exit;
	void	*exit;
	void	*coll;
	void	**walk;//NEEDS INITIALIZATION
	void	**ce_idle;//NEEDS INITIALIZATION
	void	*enemy;
	void	**nums;//NEEDS INITIALIZATION
	int		w;
	int		h;
	int		n_w;//8
	int		n_h;//16
}	t_image;

//MLX STRUCTURE
typedef struct s_mlx
{
	void	*mlx;
	t_image	img;
	void	*window;
}	t_mlx;

//MAP DATA STRUCTURE
typedef struct s_map
{
	char		*mapfile;
	char		**map_arr;
	int			rows;
	int			columns;
	int			spawn_am;
	int			exit_am;
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
	int	map_struct_error;
	int	invalid_map;
	int	queue_alloc_error;
	int	visited_alloc_error;
	int	image_get_error;
}	t_error;

//BASE DATA STRUCTURE
typedef struct s_data
{
	unsigned int	frame;
	t_player		*player;//Needs Initialization
	t_mlx			*mlx;//Needs initialization
	t_vector		*queue;//Needs initialization with rows*cols
	int				**visited;//Needs initialization with rows*cols
	t_map			*map;//Needs allocation
	t_error			*error;//Needs allocation
	char			**map_dup;
}	t_data;

//ERROR HANDLER FUNCTIONS
size_t	ft_error_check(t_data *data);
size_t	ft_final_error_check(t_data *data);
//void	ft_free_and_close(void *memory, int fd);
//INITIALIZER FUNCTIONS
void	ft_initialize_data(t_data *data, char *argv);
//INIT HELPER FUNCTIONS
void	ft_check_map_validity(t_data *data);
//READ MAP FUNCTIONS
int		ft_get_map_size(t_data *data);
int		ft_check_window_size(t_data *data);
int		ft_read_mapfile(t_data *data, int index);
void	ft_get_spawn_and_exit(t_map *map);
//INPUT HANDLING FUNCTIONS
int		ft_key_handler(int keycode, t_data *data);
//CLEANUP MLX FUNCTIONS
void	ft_kill_images(t_mlx *mlx);
//CLOSE PROGRAM FUNCTIONS
int		ft_close_program(t_data *data);
int		ft_clear(t_data *data);
//RENDERER FUNCTIONS
int		ft_get_images(t_mlx *mlx, t_data *data);
void	ft_put_map_to_win(t_mlx *mlx, t_data *data, int i, int j);
int		ft_update_map(t_data *data);
//RENDERER HELPER FUNCTIONS
void	ft_update_floor_and_exits(t_mlx *mlx, t_data *data, t_player *player);
void	ft_update_collectibles(t_data *data, t_player *player);
void	ft_update_numbers(t_mlx *mlx, t_player *player);
void	ft_put_node_to_win(t_mlx *mlx, t_data *data, int i, int j);
//RENDERER HELPER 2 FUNCTIONS
void	ft_get_player_images(t_mlx *mlx);
void	ft_animate_walk(t_mlx *mlx, t_data *data, t_player *player);
int		ft_animate_player(t_data *data);//CALLED BY MLX_LOOP_HOOK
void	ft_allocate_images(t_mlx *mlx);
//VALIDATE MAP FUNCTIONS
int		ft_valid_char(t_data *data, t_map *map);
int		ft_valid_border(t_data *data);
int		ft_check_valid_path(t_data *data, int front, int back);
//MAIN FUNCTIONS
void	ft_map_dup(t_data *data);
#endif
