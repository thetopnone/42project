/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test22-23.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:36:20 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/25 15:26:14 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	basestr[] = "123456789";
	char	*str1;
	char	*str2;
	char	*result1;
	char	*result2;
	int		i;

	i = 0;
	str1 = calloc(10, sizeof(char));
	if (!str1)
		return (1);
	while (basestr[i])
	{
		str1[i] = basestr[i];
		i++;
	}
	printf("Testing calloc\n\nBase : %s\n", str1);
	i = 0;
	str2 = ft_calloc(10, sizeof(char));
	if (!str2)
		return (1);
	while (basestr[i])
	{
		str2[i] = basestr[i];
		i++;
	}
	printf("Replica : %s\n", str2);
	result1 = strdup(basestr);
	result2 = ft_strdup(basestr);
	printf("\nTesting strdup\n\nBase : %s\n", result1);
	printf("Replica : %s\n", result2);
	free(str1);
	free(str2);
	free(result1);
	free(result2);
	return (0);
}
