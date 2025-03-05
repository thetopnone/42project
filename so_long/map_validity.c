/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:16:39 by akonstan          #+#    #+#             */
/*   Updated: 2025/03/05 12:24:59 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_and_close(int fd, char *row)
{
	free(row);
	close(fd);
}

int	ft_check_walls(char **map)
{

}

int	ft_check_minimum_size(char **map)
{
	char	*row;
	int		counter;

	row = *map;
	if (row == NULL)
		return (1);
	counter = 1;
	while (1)
	{
		row = *(map + counter);
		if (row == NULL)
			break ;
		counter++;
	}
	if (counter < 3)
		return (1);
	return (0);
}

int	ft_check_shape(char *mapfile)
{
	int		fd;
	char	*row;
	int		len;

	fd = open(mapfile, O_RDONLY);
	row = get_next_line(fd);
	if (row != NULL)
		len = ft_strlen(row);
	free(row);
	while (1)
	{
		row = get_next_line(fd);
		if (row != NULL && (ft_strlen(row) != len))
		{
			ft_free_and_close(fd, row);
			return (1);
		}
		if (row == NULL)
		{
			close(fd);
			break ;
		}
		free(row);
	}
	return (0);
}

int	ft_map_validity(char *mapfile)
{

}
