/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:25:21 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/11 17:25:23 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Set the cheapest node to move in stack b
void	ft_set_cheapest(t_node **b)
{
	t_node	*b_ref;
	t_node	*cheapest_node;

	if (!b || !*b)
		return ;
	b_ref = *b;
	cheapest_node = b_ref;
	cheapest_node->is_cheapest = 1;
	b_ref = b_ref->next;
	while (b_ref)
	{
		if (b_ref->cost < cheapest_node->cost)
		{
			cheapest_node->is_cheapest = 0;
			cheapest_node = b_ref;
			cheapest_node->is_cheapest = 1;
		}
		b_ref = b_ref->next;
	}
}

//Updates the data in both stacks
void	ft_update_stacks(t_node **a, t_node **b)
{
	ft_update_cur_pos(a);
	ft_update_cur_pos(b);
	ft_update_middle(a);
	ft_update_middle(b);
	ft_set_target_node(b, a);
	ft_update_cost(a, b);
	ft_set_cheapest(b);
}

//This is getting the node with the bool is_cheapest set to 1
t_node	*ft_get_cheapest(t_node **b)
{
	t_node	*b_ref;

	if (!b || !*b)
		return ;
	b_ref = *b;
	while (b_ref && !b_ref->is_cheapest)
		b_ref = b_ref->next;
	return (b_ref);
}
