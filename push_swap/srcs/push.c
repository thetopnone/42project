/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:51:34 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 17:51:37 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **origin, t_node **target)
{
	t_node	*origin_head;

	if (!origin || !*origin)
		return ;
	origin_head = (*origin)->next;
	if ((*origin)->next)
		(*origin)->next->prev = NULL;
	if ((*target))
		(*target)->prev = (*origin);
	(*origin)->next = (*target);
	(*target) = (*origin);
	(*origin) = origin_head;
}

void	pa(t_node **b, t_node **a)
{
	if (!*b)
		return ;
	ft_push(b, a);
	ft_update_cur_pos(a);
	ft_update_cur_pos(b);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	if (!*a)
		return ;
	ft_push(a, b);
	ft_update_cur_pos(a);
	ft_update_cur_pos(b);
	write(1, "pb\n", 3);
}
