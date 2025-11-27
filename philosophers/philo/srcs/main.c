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
	philos = ft_create_philos(input, &print);
	//ft_print_philo_chain(philos, input[0]);
	monitor = ft_allocate_monitor(philos, input);
	ft_init_philos(philos, input[0]);
	ft_init_monitor(monitor, &monitor_thread);
	pthread_join(monitor_thread, NULL);
	ft_exit(&philos, &input);
	return (0);
}
