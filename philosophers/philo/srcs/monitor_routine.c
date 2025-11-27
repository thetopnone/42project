/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:04:13 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/27 17:04:14 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_philo_death(t_monitor *monitor)
{
	t_philos		*philo;
	int				philo_amount;
	int				i;
	struct	timeval	time;

	philo = monitor->philos;
	philo_amount = philo->prev->id;
	i = 0;
	gettimeofday(&time, NULL);
	while (i < philo_amount)
	{
		pthread_mutex_lock(&philo->eating);
		//printf("time: %ld\n", ft_time_in_ms(time) - philo->last_meal);
		if (!philo->is_eating && ft_time_in_ms(time) - philo->last_meal >= monitor->time_to_die)
		{
			pthread_mutex_lock(philo->print);
			printf("Philo %d has died\n", philo->id);
			pthread_mutex_unlock(philo->print);
			return (1);
		}
		pthread_mutex_unlock(&philo->eating);
		philo = philo->next;
		i++;
	}
	return (0);
}

//Monitor will be checking if any philosopher has died or if the times
//fed condition has been satisfied
//if philospher is supposed to die, we will lock the is_eating mutex so he
//cannot "revive" hismelf
void	*ft_monitor_routine(void *arg)
{
	t_monitor		*monitor;

	monitor = (t_monitor *)arg;
	while (1)
	{
		if (ft_check_philo_death(monitor) == 1)
			return (NULL);
		ft_usleep(1);
	}
}
