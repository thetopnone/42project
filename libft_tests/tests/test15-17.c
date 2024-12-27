/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test15-17.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:09:02 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/23 16:44:38 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "Testing for \n special characters";
	char	*str2 = "Testing foqs what is Gonna HApPen Now?";

	printf("Testing strchr\nstr1\nBase : %s\n", strchr(str1, 'W' ));
	printf("Replica : %s\n", ft_strchr(str1, 'W'));
	printf("str2\nBase : %s\n", strchr(str2, '\0'));
	printf("Replica : %s\n", ft_strchr(str2, '\0'));
	printf("Testing strrchr\nstr1\nBase : %s\n", strrchr(str1, 'W'));
	printf("Replica : %s\n\n", ft_strrchr(str1, 'W'));
	printf("str2\nBase : %s\n", strrchr(str2, 'T'));
	printf("Replica : %s\n\n", ft_strrchr(str2, 'T'));
	printf("Testing strncmp\n\nBase : %d\n",strncmp(str1, str2, 90));
	printf("Replica : %d\n", ft_strncmp(str1, str2, 90));
	return (0);
}
