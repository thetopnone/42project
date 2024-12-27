/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:15:05 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/10 16:20:42 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_ultimate_div_mod(int *a, int *b)
{
	int	div_res;
	int	mod_res;

	div_res = *a / *b;
	mod_res = *a % *b;
	*a = div_res;
	*b = mod_res;
}
