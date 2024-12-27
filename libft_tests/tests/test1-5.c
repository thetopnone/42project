/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1-5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:37:17 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/19 18:32:37 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	main()
{
	//if(argc != 2)
	//	return (1);

	//char	*string1;
	char	*string = "";
	//string1 = argv[1];
	while (*string)
	{
		printf("%d ", ft_isalpha(*string));
		printf("%d\n", isalpha(*string));
		printf("%d ", ft_isdigit(*string));
		printf("%d\n", isdigit(*string));
		printf("%d ", ft_isalnum(*string));
		printf("%d\n", isalnum(*string));
		printf("%d ", ft_isascii(*string));
		printf("%d\n", isascii(*string ));
		printf("%d ", ft_isprint(*string));
		printf("%d\n", isprint(*string));
		printf("--------------- \n");
		string++;
	}
	return (0);
}
