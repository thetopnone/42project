/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:35:29 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 12:35:30 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **head)
{
	if (head == NULL || *head == NULL || !(*head)->next)
		return ;
	(*head) = (*head)->next;
	if (((*head)->next))
		(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	(*head)->next = (*head)->prev;
	(*head)->next->prev = (*head);
	(*head)->prev = NULL;
}

void	sa(t_node **a)
{
	if (ft_stack_len(a) <= 1)
		return ;
	ft_swap(a);
	ft_update_cur_pos(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	if (ft_stack_len(b) <= 1)
		return ;
	ft_swap(b);
	ft_update_cur_pos(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node	**b)
{
	if (ft_stack_len(a) <= 1 || ft_stack_len(b) <= 1)
		return ;
	ft_swap(a);
	ft_swap(b);
	ft_update_cur_pos(a);
	ft_update_cur_pos(b);
	write(1, "ss\n", 3);
}
