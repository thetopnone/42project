/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:16:45 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/11 15:16:46 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Sorts a for 3 elements
void	ft_mini_sort(t_node **a)
{
	t_node	*a_ref;

	if (!a || !*a || ft_is_sorted(a))
		return ;
	while (!ft_is_sorted(a))
	{
		if ((*a)->value == 2 && (*a)->next->value == 1)
		{
			sa(a);
			continue ;
		}
		if ((*a)->value != 1)
		{
			ra(a);
			continue ;
		}
		else
			rra(a);
	}
}

void	ft_push_swap(t_node **a, t_node **b)
{
	if (!a || !b || !*a || ft_is_sorted(a))
		return ;
	ft_push_to_b(a, b);
	ft_mini_sort(a);
	while (*b)
	{
		ft_update_stacks(a, b);
		ft_move_nodes_to_top(a, b);
		pa(b, a);
	}
	while (!ft_is_sorted(a))
		ra(a);
}

