/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:55:12 by akonstan          #+#    #+#             */
/*   Updated: 2025/02/26 16:12:06 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_map_size(char *mapfile)
{
	char	*line;
	int		rows;
	int		*size;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	size = ft_calloc(2, sizeof(int));
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	size[1] = ft_strlen(line);
	rows = 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		rows++;
		free(line);
	}
	size[0] = rows;
	close(fd);
	return (size);
}

char	**ft_read_map(char *mapfile)
{
	char	**map;
	char	*line;
	int		*size;
	int		cur_row;
	int		fd;

	cur_row = 0;
	size = ft_map_size(mapfile);
	map = ft_calloc((size[0] + 1), sizeof(char *));
	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[size[1] - 1] == '\n')
			line[size[1] - 1] = '\0';
		map[cur_row] = line;
		cur_row++;
	}
	map[cur_row] = NULL;
	close(fd);
	free (size);
	return (map);
}

/*int	main(void)
{
	char	**map;
	int	i = 0;
	
	map = ft_read_map("map1.ber");
	while (i < 5)
	{
		ft_printf("%s\n", *(map + i));
		free(*(map + i));
		i++;
	}
	free(map);
	return (0);
}*/
