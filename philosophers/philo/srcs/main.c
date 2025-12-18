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

static void	ft_main_input_error(int argc, char **argv)
{
	if (ft_check_input(argc, argv))
	{
		printf("Ivalid Input\n");
		exit(1);
	}
}

//mutex[0] == print mutex
//mutex[1] == death mutex
int	main(int argc, char **argv)
{
	int				*input;
	t_philos		*philos;
	t_monitor		*monitor;
	pthread_mutex_t	mutexes[2];
	pthread_t		monitor_thread;

	ft_main_input_error(argc, argv);
	input = malloc(argc * sizeof(int));
	philos = NULL;
	if (!input)
		return (-1);
	ft_get_input(argv, input);
	pthread_mutex_init(&mutexes[0], NULL);
	pthread_mutex_init(&mutexes[1], NULL);
	monitor = ft_allocate_monitor(input);
	philos = ft_create_philos(input, mutexes);
	monitor->philos = philos;
	ft_set_death_flag(monitor);
	ft_init_monitor(monitor, &monitor_thread);
	monitor->philo = ft_init_philos(philos, input[0]);
	ft_thread_join(monitor, monitor_thread, input[0]);
	free(monitor->philo);
	free(monitor);
	ft_exit(&philos, &input);
	return (0);
}
