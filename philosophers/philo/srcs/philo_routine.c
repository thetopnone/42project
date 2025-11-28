/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:13:29 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/27 15:13:30 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_thinking(t_philos *philo)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	pthread_mutex_lock(philo->print);
	printf("[%ld] Philo %d is thinking\n", ft_time_in_ms(time), philo->id);
	pthread_mutex_unlock(philo->print);
}

void	ft_philo_eating(t_philos *philo)
{
	if (philo->id == 1)
	{
		ft_grab_front_fork(philo);
		ft_grab_left_fork(philo);
		ft_eat_and_leave_forks(philo);
	}
	else
	{
		ft_grab_left_fork(philo);
		ft_grab_front_fork(philo);
		ft_eat_and_leave_forks(philo);
	}
}

void	ft_philo_sleeping(t_philos *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(philo->print);
	printf("[%ld] Philo %d is sleeping\n", ft_time_in_ms(time), philo->id);
	pthread_mutex_unlock(philo->print);
	usleep(1000 * philo->time_to_sleep);
}

//Remember to make philo 1 grab the fork in front of him first
//philo routine:
//start	death timer
//grab left fork if free and lock
//grab front fork if free and lock
//death timer = 0
//philo eats
//philo leaves fork left
//philo leaves fork front
//death_timer start;
//philo sleeps
//philo wakes up
//philos 
void	*ft_philo_routine(void *arg)
{
	t_philos		*philo;
	struct timeval	time;

	philo = (t_philos *)arg;
    usleep(200 * ((long)(1 / philo->id)));
	gettimeofday(&time, NULL);
	philo->last_meal = ft_time_in_ms(time);
	while (1)
	{
		ft_philo_thinking(philo);
		ft_philo_eating(philo);
		ft_philo_sleeping(philo);
	}
	return (NULL);
}

