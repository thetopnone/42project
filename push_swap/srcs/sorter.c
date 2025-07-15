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
	t_node	*biggest;

	if (!a || !*a || ft_is_sorted(a))
		return ;
	ft_update_cur_pos(a);
	ft_update_middle(a);
	biggest = ft_get_smallest(a);
	while (!ft_is_sorted(a))
	{
		ft_update_cur_pos(a);
		ft_update_middle(a);
		biggest = ft_get_biggest(a);
		if (biggest->cur_pos != 2)
			ra(a);
		else if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}

//Base sorting function
void	ft_push_swap(t_node **a, t_node **b, int chunks)
{
	t_node	*smallest;

	if (!a || ft_is_sorted(a))
		return ;
	ft_push_to_b(a, b, chunks);
	ft_mini_sort(a);
	while (*b)
	{
		ft_update_stacks(a, b);
		ft_move_nodes_to_top(a, b);
		pa(b, a);
	}
	ft_update_cur_pos(a);
	ft_update_middle(a);
	smallest = ft_get_smallest(a);
	while (ft_is_sorted(a) != 1)
	{
		smallest = ft_get_smallest(a);
		if (smallest->is_above_middle)
			ra(a);
		else
			rra(a);
	}
}
