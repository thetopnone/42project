/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:01:36 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/02 18:01:38 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_file(char *filename)
{
	size_t	filename_len;
	char	*ref;

	ref = filename;
	filename_len = ft_strlen(ref);
	if (filename_len < 5)
		return (1);
	ref = ref + (filename_len - 4);
	if (ft_strncmp(ref, ".ber", 4) != 0)
		return (1);
	return (0);
}

void	ft_map_dup(t_data *data)
{
	int	i;

	i = 0;
	data->map_dup = ft_calloc(data->map->rows + 1, sizeof(char *));
	while (i < data->map->rows)
	{
		data->map_dup[i] = ft_strdup(data->map->map_arr[i]);
		i++;
	}
	data->map_dup[i] = NULL;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Error\nIVALID ARGUMENT COUNT\n"));
	if (ft_check_file(argv[1]) == 1)
		return (ft_printf("Error\nINVALID FILE FORMAT\n"));
	ft_bzero(&data, sizeof(t_data));
	ft_initialize_data(&data, argv[1]);
	if (ft_final_error_check((&data)) != 0)
		return (ft_clear(&data));
	data.mlx->mlx = mlx_init();
	data.mlx->window = mlx_new_window(data.mlx->mlx,
			(data.map->columns - 1) * 32, data.map->rows * 32, "Game Window");
	ft_get_images(data.mlx, &data);
	ft_put_map_to_win(data.mlx, &data, 0, 0);
	mlx_key_hook(data.mlx->window, ft_key_handler, &data);
	mlx_hook(data.mlx->window, 17, 0, ft_close_program, &data);
	mlx_loop_hook(data.mlx->mlx, ft_animate_player, &data);
	mlx_loop(data.mlx->mlx);
	return (0);
}
