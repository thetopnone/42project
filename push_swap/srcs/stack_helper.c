/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:26:06 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 14:26:07 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Calculates the stack size
long	ft_stack_len(t_node **stack)
{
	long	len;
	t_node	*ref_node;

	if (!stack || !*stack)
		return (0);
	len = 0;
	ref_node = *stack;
	while (ref_node)
	{
		len++;
		ref_node = ref_node->next;
	}
	return (len);
}

//This returns a pointer to the last node on the stack
t_node	*ft_nodelast(t_node	**stack)
{
	t_node	*ref;

	if (!stack || !*stack)
		return (NULL);
	ref = *stack;
	while (ref->next != NULL)
		ref = ref->next;
	return (ref);
}

//Creates a new node with the content
t_node	*ft_nodenew(long value, int index)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->cur_pos = index;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

//Appends a node at the end of the stack
void	ft_nodeadd_back(t_node **stack, t_node *node)
{
	t_node	*last_node;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_nodelast(stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

//Clears the stack
void	ft_stack_clear(t_node **stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
}
