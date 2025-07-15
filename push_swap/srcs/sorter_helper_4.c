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
	median = ((ft_nodelast(stack)->cur_pos) / 2) + 1;
	while (ref)
	{
		if (ref->cur_pos < median)
			ref->is_above_middle = 1;
		else
			ref->is_above_middle = 0;
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
			ft_set_cost_above(b_ref, a_len);
		else
			ft_set_cost_below(b_ref, a_len, b_len);
		b_ref = b_ref->next;
	}
}

//Checks if the stack given as a n argument is sorted
int	ft_is_sorted(t_node **stack)
{
	t_node	*previous_node;
	t_node	*current_node;

	if (!stack || !*stack)
		return (1);
	current_node = *stack;
	current_node = current_node->next;
	while (current_node)
	{
		previous_node = current_node->prev;
		if (!previous_node)
			break ;
		if (current_node->value < previous_node->value)
		{
			return (0);
		}
		current_node = current_node->next;
	}
	return (1);
}
