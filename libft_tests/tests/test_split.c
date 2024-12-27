/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:50:12 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/26 15:07:58 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	str[] = " ";
	char	delim = 'z';
	char	**result;
	
	result = ft_split(str, delim);
	if (!result[0])
	{
		printf("(null)");
		return (0);
	}
	while (*result)
	{
		printf("%s\n", *result);
		result++;
	}
	//free(result);
	return (0);
}
