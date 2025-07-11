/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:35:36 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 12:35:39 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_initialize_stacks(t_node ***a, t_node ***b, int argc, char *argv[])
{
	int		j;

	j = 1;
	*a = NULL;
	*b = NULL;
	while (j < argc)
	{
		ft_nodeadd_back(a, ft_nodenew(ft_atol(argv[j]), j - 1));
		j++;
	}
	return (0);
}
