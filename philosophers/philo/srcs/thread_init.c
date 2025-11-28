/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:47:49 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/26 19:07:40 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_monitor	*ft_allocate_monitor(t_philos *philos, int *input)
{
	t_monitor	*monitor_struct;

	monitor_struct = malloc(1 * sizeof(t_monitor));
	if (!monitor_struct)
		return (NULL);
	monitor_struct->philos = philos;
	monitor_struct->input = input;
	monitor_struct->time_to_die = input[1];
	monitor_struct->time_to_eat = input[2];
	monitor_struct->time_to_sleep = input[3];
	if (input[4])
		monitor_struct->target_times_to_eat = input[4];
	else
		monitor_struct->target_times_to_eat = -1;
	return (monitor_struct);
}

int	ft_init_monitor(t_monitor *monitor, pthread_t *monitor_thread)
{
	usleep(10);
	pthread_create(monitor_thread, NULL, ft_monitor_routine, monitor);
	return (0);
}

int	ft_init_philos(t_philos *philos, int philo_amount)
{
	pthread_t	philo[philo_amount];

	int		i;

	i = 0;
	while(i < philo_amount)
	{
		pthread_create(&philo[i], NULL, ft_philo_routine, &(*philos));
		pthread_detach(philo[i]);
		philos = philos->next;
		i++;
	}
	return (0);
}
