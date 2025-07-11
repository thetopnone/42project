/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:35:47 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 12:35:49 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	**a;
	t_node	**b;

	if (argc <= 2)
		return (1);
	ft_initialize_stacks(&a, &b, argc, **argv);
	ft_push_swap(a, b);
	return (0);
}
