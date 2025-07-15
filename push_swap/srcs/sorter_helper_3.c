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

//Sets the desired node in which we want to place the b node above it
void	ft_set_target_node(t_node **b, t_node **a)
{
	t_node		*b_ref;
	t_node		*a_ref;
	long long	dist;

	if (!b || !*b || !a || !*a)
		return ;
	b_ref = *b;
	a_ref = *a;
	dist = 0;
	ft_set_closest_bigger(b_ref, a_ref, a, &dist);
}

//If the target node and the b_node are on the same side of the stacks
//we have less cost because of operations rr and rrr which act on both
//stacks but count as one operation. Both next functions assign the correct
//cost according to the position of the nodes
void	ft_set_cost_above(t_node *b_ref, long a_len)
{
	if (b_ref->target->is_above_middle)
	{
		if (b_ref->cur_pos > b_ref->target->cur_pos)
			b_ref->cost = b_ref->cur_pos + 1;
		else
			b_ref->cost = b_ref->target->cur_pos + 1;
	}
	else
		b_ref->cost = a_len - b_ref->target->cur_pos + b_ref->cur_pos + 1;
}

void	ft_set_cost_below(t_node *b_ref, long a_len, long b_len)
{
	if (!(b_ref->target->is_above_middle))
	{
		if (b_len - b_ref->cur_pos > a_len - b_ref->target->cur_pos)
			b_ref->cost = b_len - b_ref->cur_pos + 1;
		else
			b_ref->cost = a_len - b_ref->target->cur_pos + 1;
	}
	else
		b_ref->cost = b_len - b_ref->cur_pos + b_ref->target->cur_pos + 1;
}

void	ft_set_closest_bigger(t_node *b_ref, t_node *a_ref,
			t_node **a, long long *dist)
{
	while (b_ref)
	{
		*dist = 4294967296;
		a_ref = *a;
		if (b_ref->value > ft_get_biggest(a)->value)
		{
			b_ref->target = ft_get_smallest(a);
			b_ref = b_ref->next;
			continue ;
		}
		b_ref->target = a_ref;
		while (a_ref)
		{
			if (ft_dist(a_ref->value, b_ref->value) > 0
				&& ft_dist(a_ref->value, b_ref->value) < *dist)
			{
				b_ref->target = a_ref;
				*dist = ft_dist(a_ref->value, b_ref->value);
			}
			a_ref = a_ref->next;
		}
		b_ref = b_ref->next;
	}
}

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
