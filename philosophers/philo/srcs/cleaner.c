/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:24:02 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/27 17:24:03 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//Function to clear the philo chain form memory
int	ft_del_philo_chain(t_philos **head, int philo_amount)
{
	t_philos	*target;

	target = NULL;
	if (!*head)
		return (0);
	pthread_mutex_destroy((*head)->print);
	while (philo_amount > 0)
	{
		target = ft_get_philo(*head, philo_amount);
		//pthread_mutex_destroy(&target->fork);
		//pthread_mutex_destroy(&target->eating);
		free(target);
		philo_amount--;
	}
	*head = NULL;
	return (0);
}
//Function to exit the program
int	ft_exit(t_philos **head, int **input)
{
	ft_del_philo_chain(head, (*input)[0]);
	free(*input);
	exit(0);
}
