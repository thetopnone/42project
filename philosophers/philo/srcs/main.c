/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:42:45 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/25 21:42:46 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	int				*input;
	t_philos		*philos;
	t_monitor		*monitor;
	pthread_mutex_t	print;
	pthread_t		monitor_thread;

	if (ft_check_input(argc, argv))
	{
		printf("Ivalid Input\n");
		return (1);
	}
	input = malloc(argc * sizeof(int));
	philos = NULL;
	if (!input)
		return (-1);
	ft_get_input(argv, input);
	pthread_mutex_init(&print, NULL);
	monitor = ft_allocate_monitor(input);
	philos = ft_create_philos(input, &print);
	monitor->philos = philos;
	ft_set_death_flag(monitor);
	ft_init_monitor(monitor, &monitor_thread);
	monitor->philo = ft_init_philos(philos, input[0]);
    pthread_join(monitor_thread, NULL);
	//ft_thread_join(monitor ,monitor_thread, input[0]);
	free(monitor->philo);
	free(monitor);
	ft_exit(&philos, &input);
	return (0);
}
