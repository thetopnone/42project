/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_helper_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:07:23 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/11 18:07:25 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This moves the CHEAPEST and its TARGET to the TOP OF THE STACKS
void	ft_move_nodes_to_top(t_node **a, t_node **b)
{
	t_node	*b_node;

	if (!a || !*b)
		return ;
	b_node = ft_get_cheapest(b);
	if ((b_node->target->is_above_middle && b_node->is_above_middle)
		|| (!b_node->target->is_above_middle && !b_node->is_above_middle))
		ft_move_both(a, b, b_node->target, b_node);
	ft_move_to_top_b(b, b_node);
	ft_move_to_top_a(a, b_node->target);
}

//This function is called to move both nodes at the same time to
//save operations
void	ft_move_both(t_node **a, t_node **b, t_node *a_node, t_node *b_node)
{
	if (!a || !b || !a_node || !b_node)
		return ;
	if (a_node->is_above_middle && b_node->is_above_middle)
	{
		while (b_node->cur_pos != (*b)->cur_pos
			&& a_node->cur_pos != (*a)->cur_pos)
			rr(a, b);
	}
	if (!a_node->is_above_middle && !b_node->is_above_middle)
	{
		while (b_node->cur_pos != (*b)->cur_pos
			&& a_node->cur_pos != (*a)->cur_pos)
			rrr(a, b);
	}
	ft_update_middle(a);
	ft_update_middle(b);
}

//Moves the desired node in stack b to top
void	ft_move_to_top_b(t_node **b, t_node *node)
{
	if (!b || !node || !*b)
		return ;
	if (node->is_above_middle)
	{
		while (node->cur_pos != (*b)->cur_pos)
			rb(b);
	}
	else
	{
		while (node->cur_pos != (*b)->cur_pos)
			rrb(b);
	}
}

//moves the desired node from a to the top
void	ft_move_to_top_a(t_node **a, t_node *node)
{
	if (!a || !node || !*a)
		return ;
	if (node->is_above_middle)
	{
		while (node->cur_pos != (*a)->cur_pos)
			ra(a);
	}
	else
	{
		while (node->cur_pos != (*a)->cur_pos)
			rra(a);
	}
}
