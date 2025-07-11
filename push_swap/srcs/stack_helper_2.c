/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:18:55 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/11 12:18:56 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Updates the cur_poses on the stack after every operation
void	ft_update_cur_pos(t_node **stack)
{
	int		cur_pos;
	t_node	*ref;

	if (!stack || !*stack)
		return ;
	ref = *stack;
	cur_pos = 0;
	while (ref)
	{
		ref->cur_pos = cur_pos;
		cur_pos++;
		ref = ref->next;
	}
}

//Updates the boolean is_above_middle value in all the nodes in the stack 
//The goal is that if it is below middle we calculate cost by reverse rotate
//and if it is above middle we calculate cost using rotate
void	ft_update_middle(t_node **stack)
{
	int		median;
	t_node	*ref;

	if (!stack || !*stack)
		return ;
	ref = *stack;
	median = (ft_nodelast(stack)->cur_pos) / 2;
	while (ref)
	{
		if (ref->cur_pos < median)
			ref->is_above_middle = 1;
		ref = ref->next;
	}
}

//Calculates and assigns the cost to move the b node to the desired spot in
//a stack
void	ft_update_cost(t_node **a, t_node **b)
{
	long	a_len;
	long	b_len;
	long	total;
	t_node	*a_ref;
	t_node	*b_ref;

	if (!a || !*a || !b || !*b)
		return ;
	a_ref = *a;
	b_ref = *b;
	a_len = ft_stack_len(a);
	b_len = ft_stack_len(b);
	total = a_len + b_len;
	while (b_ref)
	{
		if (b_ref->is_above_middle)
			b_ref->cost = b_ref->cur_pos + b_ref->target->cur_pos + 1;
		else
			b_ref->cost = total - b_ref->cur_pos - b_ref->target->cur_pos + 1;
		b_ref = b_ref->next;
	}
}

//Sets the desired node in which we want to place the b node above it
void	ft_set_target_node(t_node **b, t_node **a)
{
	t_node		*b_ref;
	t_node		*a_ref;
	long long	dist;

	if (!b || !*b || !a || !*a)
		return ;
	b_ref = *b;
	dist = 0;
	while (b_ref)
	{
		a_ref = *a;
		while (a_ref)
		{
			if (ft_abs_dist(a_ref->value, b_ref->value) < dist || dist == 0)
			{
				b_ref->target = a_ref;
				dist = ft_abs_dist(a_ref->value, b_ref->value);
			}
			a_ref = a_ref->next;
		}
		b_ref = b_ref->next;
	}
}

//Checks if the stack given as a n argument is sorted
int	ft_is_sorted(t_node **stack)
{
	t_node	*previous_node;
	t_node	*current_node;

	current_node = *stack;
	current_node = current_node->next;
	while (current_node)
	{
		previous_node = current_node->prev;
		if (current_node->value < previous_node->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}
