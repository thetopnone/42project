/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test13-14.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:34:08 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/21 15:39:10 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	one;
	char	two;

	one = '1';
	two = 'A';
	printf("%c , %c\n", toupper(one), tolower(one));
	printf("%c , %c\n", toupper(two), tolower(two));
	return (0);
}
