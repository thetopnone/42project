/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:35:20 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 12:35:23 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

//NODE STRUCTURE
typedef struct s_node
{
	long	value;
	int		cur_pos;
	int		is_above_middle;
	int		is_cheapest;
	int		cost;
	t_node	*target;
	t_node	*next;
	t_node	*prev;
}	t_node;

//ERROR DATA STRUCTURE
typedef struct s_error
{
	int	initializing_error;
	int	invalid_input;
}	t_error;

//STACK INITIALIZATION FUNCTIONS
int			ft_initialize_stacks(t_node ***a, t_node ***b,
				int argc, char *argv[]);
//STACK HELPER 3 FUNCTIONS
void		ft_set_cheapest(t_node **b);
void		ft_update_stacks(t_node **a, t_node **b);
t_node		*ft_get_cheapest(t_node **b);
//STACK HELPER 2 FUNCTIONS
void		ft_update_cur_pos(t_node **stack);
void		ft_update_middle(t_node **stack);
void		ft_set_target_node(t_node **b, t_node **a);
void		ft_update_cost(t_node **a, t_node **b);
int			ft_is_sorted(t_node **stack);
//STACK HELPER FUNCTIONS
long		ft_stack_len(t_node **stack);
t_node		*ft_nodelast(t_node	**stack);
t_node		*ft_nodenew(long value, int index);
void		ft_nodeadd_back(t_node **stack, t_node *node);
void		ft_stack_clear(t_node **stack);
//HELPER FUNCTIONS
long		ft_atol(const char *nptr, t_error *error);
long long	ft_abs_dist(long value1, long value2);
//SWAP FUNCTIONS
void		ft_swap(t_node **head);
void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node	**b);
//ROTATE FUNCTIONS
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);
//REVERSE ROTATE FUNCTIONS
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);
//PUSH FUNCTIONS
void		ft_push(t_node **origin, t_node **target);
void		pa(t_node **b, t_node **a);
void		pb(t_node **a, t_node **b);
//SORTER HELPER 2 FUNCTIONS
void		ft_move_both(t_node **a, t_node **b,
				t_node *node_a, t_node *node_b);
void		ft_move_to_top_b(t_node **b, t_node *node);
void		ft_move_to_top_a(t_node **a, t_node *node);
//SORTER HELPER FUNCTIONS
void		ft_push_to_b(t_node **a, t_node **b);
void		ft_send_cheapest(t_node **a, t_node **b);
void		ft_move_nodes_to_top(t_node **a, t_node **b);
//SORTER FUNCTIONS
void		ft_mini_sort(t_node **a);
#endif
