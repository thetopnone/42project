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

//Pushes all nodes of a stack but 3 to the b stack
void	ft_push_to_b(t_node **a, t_node **b)
{
	if (!b || !a || !*a)
		return ;
	while (ft_stack_len(a) > 3)
		pb(a, b);
}

void	ft_move_nodes_to_top(t_node **a, t_node **b)
{
	t_node	*b_node;

	if (!a || !*b)
		return ;
	b_node = ft_get_cheapest(b);
	if (b_node->target->is_above_middle && b_node->is_above_middle ||
		!b_node->target->is_above_middle && !b_node->is_above_middle)
		ft_move_both(a, b, b_node->target, b_node);
	ft_move_to_top_b(b);
	ft_move_to_top_a(a);
}
