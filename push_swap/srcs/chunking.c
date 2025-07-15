/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:44:05 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/14 13:44:06 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function that returns the first node in a on the set third
t_node	*ft_get_third(t_node **a, long index, long third)
{
	t_node	*a_ref;

	a_ref = *a;
	while (a_ref)
	{
		if (a_ref->sorted_pos >= index * third
			&& a_ref->sorted_pos <= (index + 1) * third)
			return (a_ref);
		a_ref = a_ref->next;
	}
	return (NULL);
}

//Function that returns the last third after staring seeing thirds
t_node	*ft_get_cheapest_third(t_node **a, long index, long third)
{
	t_node	*a_ref;
	t_node	*cheapest;

	a_ref = *a;
	cheapest = ft_get_third(a, index, third);
	while (a_ref && cheapest)
	{
		if (a_ref && ft_is_third(a, a_ref, index, third)
			&& a_ref->cost < cheapest->cost)
			cheapest = a_ref;
		a_ref = a_ref->next;
	}
	return (cheapest);
}

//Pushes all chunks of a stack but 3 to the b stack
void	ft_push_to_b(t_node **a, t_node **b, int chunks)
{
	long	last;

	if (!b || !a || !*a)
		return ;
	ft_set_sorted_pos(a);
	last = ft_stack_len(a) - 1;
	while (ft_stack_len(a) > 3)
		ft_send_to_b(a, b, last, chunks);
}

//Sends the node in a range of sorted positions to b
void	ft_send_to_b(t_node **a, t_node **b, long last, int chunks)
{
	long	third;
	int		low;
	int		high;

	if (!a || !*a || !b)
		return ;
	third = last / chunks;
	low = 0;
	high = chunks - 1;
	ft_update_middle(a);
	ft_set_cost_a(a);
	while (low <= high)
	{
		ft_send_third(a, b, third, &low);
		low++;
		if (low > high)
			break ;
		ft_send_third(a, b, third, &high);
		high--;
	}
	while (ft_stack_len(a) > 3)
		pb(a, b);
}

void	ft_send_third(t_node **a, t_node **b, long third, int *chunk)
{
	while (ft_get_third(a, *chunk, third) && ft_stack_len(a) > 3)
	{
		ft_move_to_top_a(a, ft_get_cheapest_third(a, *chunk, third));
		pb(a, b);
		ft_update_middle(a);
		ft_set_cost_a(a);
	}
}
