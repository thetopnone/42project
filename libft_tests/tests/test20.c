/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test20.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:08:06 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/23 17:19:33 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "suqowhtqpodkjlkqieruqoi";
	char	str2[] = "s";

	//printf("Testing strnstr\n\n str1 && str2\n\nBase : %s\n", strnstr(str1, str2, 0));
	printf("Replica : %s\n", ft_strnstr(str1, str2, ft_strlen(str1)));
	return (0);
}
