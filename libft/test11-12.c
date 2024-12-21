/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11-12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:17:35 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/21 15:32:05 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*dest1;
	char	*dest2;
	char	src[] = "This is the source";

	dest1 = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest1)
		return (1);
	dest2 = malloc((2 * ft_strlen(src) + 1) * sizeof(char));
	if (!dest2)
	{
		free(dest1);
		return (1);
	}
	ft_strlcpy(dest1, src, ft_strlen(src) + 1);
	ft_strlcpy(dest2, dest1, ft_strlen(dest1) + 1);
	ft_strlcat(dest2, src, 2 * ft_strlen(src) + 1);
	printf("%s\n", dest1);
	printf("%s\n", dest2);
	free(dest1);
	free(dest2);
	return (0);
}
