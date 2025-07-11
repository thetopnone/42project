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

//This functions is to set the right counter for rotating for functions
//at the same time
static int	ft_set_counter(t_node **a, t_node **b,
	t_node *node_a, t_node *node_b)
{
	if (!a || !b || !node_a || !node_b)
		return (-1);
	if (node_a->is_above_middle)
	{
		if (node_a->cur_pos < node_b->cur_pos)
			return (node_a->cur_pos);
		return (node_b->cur_pos);
	}
	else
	{
		if (node_a->cur_pos > node_b->cur_pos)
			return (ft_stack_len(a) - node_a->cur_pos);
		return (ft_stack_len(b) - node_b->cur_pos);
	}
}

//This function is called to move both nodes at the same time to
//save operations
void	ft_move_both(t_node **a, t_node **b, t_node *node_a, t_node *node_b)
{
	int	counter;

	if (!a || !b || !node_a || !node_b)
		return ;
	counter = ft_set_counter(a, b, node_a, node_b);
	if (node_a->is_above_middle && node_b->is_above_middle)
	{
		while (counter > 0)
		{
			rr(a, b);
			counter--;
		}
	}
	if (!node_a->is_above_middle && !node_b->is_above_middle)
	{
		while (counter > 0)
		{
			rrr(a, b);
			counter--;
		}
	}
	ft_update_cur_pos(a);
	ft_update_cur_pos(b);
}

//Moves the desired node in stack b to top
void	ft_move_to_top_b(t_node **b, t_node *node)
{
	if (!b || !node || !*b)
		return ;
	if (node->is_above_middle)
	{
		while (0 < node->cur_pos)
		{
			rb(b);
			node->cur_pos--;
		}
	}
	else
	{
		while (0 < ft_stack_len(b) - node->cur_pos)
		{
			rrb(b);
			node->cur_pos++;
		}
	}
}

//moves the desired node from a to the top
void	ft_move_to_top_a(t_node **a, t_node *node)
{
	if (!a || !node || !*a)
		return ;
	if (node->is_above_middle)
	{
		while (0 < node->cur_pos)
		{
			ra(a);
			node->cur_pos--;
		}
	}
	else
	{
		while (counter < ft_stack_len(a) - node->cur_pos)
		{
			rra(a);
			node->cur_pos++;
		}
	}
}
