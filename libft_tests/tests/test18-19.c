/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test18-19.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:47:07 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/23 17:00:26 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*str1 = NULL;
	char	*str2 = NULL;

	printf("Testing memchr\n\nstr1\n\nBase : %s\n", (char *)memchr(str1, '5', 49));
	printf("Replica : %s\n\n", (char *)ft_memchr(str1, '5', 49));
	printf("Testing memcmp\n\nstr1 && str2 \n\nBase : %d\n", memcmp(str1, str2, 280));
	printf("Replica : %d", ft_memcmp(str1, str2, 280));
	return (0);
}
