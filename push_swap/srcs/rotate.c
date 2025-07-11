/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:32:54 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 16:32:56 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **head)
{
	t_node	*tail;

	if (!head || !*head)
		return ;
	tail = ft_nodelast(head);
	(*head)->prev = tail;
	(*head)->next->prev = NULL;
	tail->next = (*head);
	(*head) = (*head)->next;
	tail->next->next = NULL;
}

void	ra(t_node **a)
{
	if (ft_stack_len(a) <= 1)
		return ;
	ft_rotate(a);
	ft_update_cur_pos(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	if (ft_stack_len(b) <= 1)
		return ;
	ft_rotate(b);
	ft_update_cur_pos(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	if (ft_stack_len(a) <= 1 || ft_stack_len(b) <= 1)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_update_cur_pos(a);
	ft_update_cur_pos(b);
	write(1, "rr\n", 3);
}
