/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:22:59 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 17:23:02 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_node **head)
{
	t_node	*tail;

	if (!head || !*head)
		return ;
	tail = ft_nodelast(head);
	(*head)->prev = tail;
	tail->next = (*head);
	tail->prev->next = NULL;
	tail->prev = NULL;
	(*head) = tail;
	ft_nodelast(head)->next = NULL;
}

void	rra(t_node **a)
{
	if (ft_stack_len(a) <= 1)
		return ;
	ft_reverse_rotate(a);
	ft_update_cur_pos(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	if (ft_stack_len(b) <= 1)
		return ;
	ft_reverse_rotate(b);
	ft_update_cur_pos(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	if (ft_stack_len(a) <= 1 || ft_stack_len(b) <= 1)
		return ;
	if (ft_stack_len(a) == 2)
		ft_swap(a);
	else
		ft_reverse_rotate(a);
	if (ft_stack_len(b) == 2)
		ft_swap(b);
	else
		ft_reverse_rotate(b);
	ft_update_cur_pos(a);
	ft_update_cur_pos(b);
	write(1, "rrr\n", 4);
}
