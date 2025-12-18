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
	pthread_mutex_lock(philo->death);
	if (*philo->death_flag == 0)
	{
		pthread_mutex_unlock(philo->death);
		ft_safe_print(philo, "is thinking");
	}
	else
		pthread_mutex_unlock(philo->death);
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
	pthread_mutex_lock(philo->death);
	if (*philo->death_flag == 0)
	{
		pthread_mutex_unlock(philo->death);
		ft_safe_print(philo, "is sleeping");
		ft_usleep(philo->time_to_sleep);
	}
	else
		pthread_mutex_unlock(philo->death);
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

static void	ft_single_philo(t_philos *philo)
{
	ft_grab_front_fork(philo);
	pthread_mutex_unlock(&philo->fork);
	ft_usleep(philo->time_to_die + 1);
}

void	*ft_philo_routine(void *arg)
{
	t_philos		*philo;

	philo = (t_philos *)arg;
	pthread_mutex_lock(&philo->eating);
	philo->last_meal = ft_get_time_in_ms();
	pthread_mutex_unlock(&philo->eating);
	if (!philo->prev)
		ft_single_philo(philo);
	else
	{
		while (1)
		{
			ft_philo_thinking(philo);
			ft_philo_eating(philo);
			ft_philo_sleeping(philo);
			pthread_mutex_lock(philo->death);
			if (*philo->death_flag == 1)
			{
				pthread_mutex_unlock(philo->death);
				break ;
			}
			pthread_mutex_unlock(philo->death);
		}
	}
	return (NULL);
}
