/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:43:04 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/16 16:40:51 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap_val(int *x, int *y)
{
	int	temp_val;

	temp_val = *x;
	*x = *y;
	*y = temp_val;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	swaps;

	swaps = 0;
	while (swaps < (size / 2))
	{
		swap_val(tab + swaps, (tab + (size - swaps -1)));
		swaps++;
	}
}
