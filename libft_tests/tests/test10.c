/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:32:35 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/21 15:10:59 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	*destref;
	char	*destmove;
	char	*src = "This is the full source";
	char	overlapstr[] = "0123456789";

	destmove = malloc(25 * sizeof(char));
	destref = malloc(25 * sizeof(char));
	if (!destref)
		return (1);
	//memmove(&overlapstr[6], &overlapstr[0], 4);
	ft_memmove(&overlapstr[6], &overlapstr[0], 4);
	printf("%s\n", overlapstr);
	memmove(destref, src, 5);
	ft_memmove(destmove, src, 5);
	destref[5] = '\0';
	destmove[5] = '\0';
	printf("%s\n", destref);
	printf("%s\n", destmove);
	free(destref);
	free(destmove);
	return (0);
}
