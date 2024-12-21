/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test9-10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:33:57 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/21 14:31:20 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char	*dest1;
	char	*dest2;
	char	*src = "This is the original";

	printf("%li size of source\n", ft_strlen(src));
	printf("%s\n", src);
	dest1 = malloc((strlen(src) + 1) * sizeof(char));
	if (!dest1)
		return (1);
	dest2 = malloc((strlen(src) + 1) * sizeof(char));
	if (!dest2)
	{
		free(dest1);
		return (1);
	}
	ft_memcpy(dest1, src, strlen(src) + 1);
	memcpy(dest2, src, strlen(src) + 1);
	printf("%s\n", dest1);
	printf("%s\n", dest2);
	free(dest1);
	free(dest2);
	return (0);
}
