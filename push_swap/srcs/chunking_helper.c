/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:50:02 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/14 13:50:03 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This function calculates how much it costs to send each node in a to the
//b stack
void	ft_set_cost_a(t_node **a)
{
	t_node	*a_ref;

	if (!a)
		return ;
	a_ref = *a;
	ft_update_cur_pos(a);
	ft_update_middle(a);
	while (a_ref)
	{
		if (a_ref->is_above_middle)
			a_ref->cost = a_ref->cur_pos + 1;
		else
			a_ref->cost = ft_stack_len(a) - a_ref->cur_pos + 1;
		a_ref = a_ref->next;
	}
}

//Checks if the node is in the index specifies third of the array
int	ft_is_third(t_node **a, t_node *node, long index, long third)
{
	t_node	*smallest;
	t_node	*biggest;

	smallest = ft_get_smallest(a);
	biggest = ft_get_biggest(a);
	if (node->sorted_pos >= index * third
		&& node->sorted_pos <= (index + 1) * third
		&& node->value != smallest->value && node->value != biggest->value)
		return (1);
	return (0);
}

//Will find where the final position in the array should be
void	ft_set_sorted_pos(t_node **a)
{
	t_node	*a_ref;
	t_node	*biggest;
	long	counter;

	a_ref = (*a);
	ft_get_smallest(a)->sorted_pos = 0;
	biggest = ft_get_biggest(a);
	counter = ft_stack_len(a) - 1;
	biggest->sorted_pos = counter--;
	while (counter > 0)
	{
		a_ref = *a;
		while (a_ref)
		{
			if (ft_get_closest_smaller(a, biggest) == NULL)
				return ;
			if (a_ref->value == ft_get_closest_smaller(a, biggest)->value)
			{
				a_ref->sorted_pos = counter--;
				biggest = ft_get_closest_smaller(a, biggest);
			}
			a_ref = a_ref->next;
		}
	}
}

long	ft_set_chunk_amount(char **arguments)
{
	long	amount;

	amount = ft_get_arg_count(arguments);
	if (amount <= 10)
		return (1);
	else if (amount <= 200)
		return (2);
	else if (amount <= 600)
		return (5);
	else
		return (amount / 100);
}

//Finds the node in stack with the closest larger value to node value
t_node	*ft_get_closest_smaller(t_node **stack, t_node *node)
{
	t_node		*ref;
	t_node		*closest_small;
	long long	dist;

	if (!stack || !*stack)
		return (NULL);
	ref = *stack;
	dist = -4294967296;
	closest_small = NULL;
	while (ref)
	{
		if (ft_dist(ref->value, node->value) < 0
			&& ft_dist(ref->value, node->value) > dist)
		{
			closest_small = ref;
			dist = ft_dist(ref->value, node->value);
		}
		ref = ref->next;
	}
	return (closest_small);
}
