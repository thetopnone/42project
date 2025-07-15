/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:00:59 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/11 17:01:01 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Returns the NODE with the BIGGEST value
t_node	*ft_get_biggest(t_node **stack)
{
	t_node	*stack_ref;
	t_node	*biggest;

	if (!stack || !(*stack))
		return (NULL);
	stack_ref = (*stack);
	biggest = stack_ref;
	if (stack_ref->next)
		stack_ref = stack_ref->next;
	while (stack_ref)
	{
		if (stack_ref->value > biggest->value)
			biggest = stack_ref;
		stack_ref = stack_ref->next;
	}
	return (biggest);
}

//Returns the NODE with the SMALLEST value
t_node	*ft_get_smallest(t_node **stack)
{
	t_node	*stack_ref;
	t_node	*smallest;

	if (!stack || !(*stack))
		return (NULL);
	stack_ref = (*stack);
	smallest = stack_ref;
	if (stack_ref->next)
		stack_ref = stack_ref->next;
	while (stack_ref)
	{
		if (stack_ref->value < smallest->value)
			smallest = stack_ref;
		stack_ref = stack_ref->next;
	}
	return (smallest);
}

//This is getting the NODE with the bool IS_CHEAPEST set to 1
t_node	*ft_get_cheapest(t_node **b)
{
	t_node	*b_ref;

	if (!b || !*b)
		return (NULL);
	b_ref = *b;
	while (b_ref && !b_ref->is_cheapest)
		b_ref = b_ref->next;
	return (b_ref);
}
