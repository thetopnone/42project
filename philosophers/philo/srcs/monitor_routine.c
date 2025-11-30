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

	philo = monitor->philos;
	philo_amount = 1;
	if (philo->prev)
		philo_amount = philo->prev->id;
	i = 0;
	while (i < philo_amount)
	{
		pthread_mutex_lock(&philo->eating);
		if (!philo->is_eating && ft_get_time_in_ms() - philo->last_meal > monitor->time_to_die)
		{
			pthread_mutex_lock(philo->print);
			monitor->death_flag = 1;
			printf("%ld %d has died\n", ft_get_time_in_ms(), philo->id);
			pthread_mutex_unlock(&philo->eating);
			return (1);
		}
		pthread_mutex_unlock(&philo->eating);
		philo = philo->next;
		i++;
	}
	return (0);
}

int	ft_check_philo_meals(t_monitor *monitor)
{
	t_philos	*philo;
	int			philo_amount;
	int			i;

	if (monitor->target_times_to_eat == -1)
		return (0);
	philo = monitor->philos;
	philo_amount = 1;
	if (philo->prev)
		philo_amount = philo->prev->id;
	i = 0;
	while (i < philo_amount)
	{
		pthread_mutex_lock(&philo->eating);
		if (philo->times_fed < monitor->target_times_to_eat)
		{
			pthread_mutex_unlock(&philo->eating);
			return (0);
		}
		pthread_mutex_unlock(&philo->eating);
		philo = philo->next;
		i++;
	}
	return (1);
}

//Monitor will be checking if any philosopher has died or if the times
//fed condition has been satisfied
//if philospher is supposed to die, we will lock the is_eating mutex so he
//cannot "revive" hismelf
void	*ft_monitor_routine(void *arg)
{
	t_monitor		*monitor;

	monitor = (t_monitor *)arg;
	ft_usleep(20);
	while (1)
	{
		if (ft_check_philo_death(monitor) == 1)
		{
			pthread_mutex_unlock(monitor->philos->print);
			pthread_mutex_destroy(monitor->philos->print);
			return (NULL);
		}
		if (ft_check_philo_meals(monitor) == 1)
		{
			pthread_mutex_unlock(monitor->philos->print);
			pthread_mutex_destroy(monitor->philos->print);
			return (NULL);
		}
		usleep(100);
	}
}
