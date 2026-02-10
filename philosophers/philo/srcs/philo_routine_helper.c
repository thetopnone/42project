/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:03:15 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/27 16:03:18 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	ft_usleep(long ms)
{
	long	start;

	if (ms <= 0)
		return ;
	start = ft_get_time_in_ms();
	while (ft_get_time_in_ms() - start < ms)
		usleep(500);
}

//Makes current philo attempt to grab the fork in front of him
void	ft_grab_front_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->death);
	if (*philo->death_flag == 0)
	{
		pthread_mutex_unlock(philo->death);
		ft_safe_print(philo, "has taken a fork");
	}
	else
		pthread_mutex_unlock(philo->death);
}

//Makes current philo attemp to grab the fork of the philo to his left
void	ft_grab_left_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->prev->fork);
	pthread_mutex_lock(philo->death);
	if (*philo->death_flag == 0)
	{
		pthread_mutex_unlock(philo->death);
		ft_safe_print(philo, "has taken a fork");
	}
	else
		pthread_mutex_unlock(philo->death);
}

//Philo eats, sets flag to pause death timer, resets last_meal time and 
//releases all forks that have been taken
//is eating mutex is to block the death if the philosopher manages to start
//eating in time
void	ft_eat_and_leave_forks(t_philos *philo)
{
	pthread_mutex_lock(philo->death);
	if (*philo->death_flag == 0)
	{
		pthread_mutex_unlock(philo->death);
		pthread_mutex_lock(&philo->eating);
		philo->is_eating = 1;
		philo->last_meal = ft_get_time_in_ms();
		philo->times_fed++;
		pthread_mutex_unlock(&philo->eating);
		ft_safe_print(philo, "is eating");
		ft_usleep(philo->time_to_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->prev->fork);
		pthread_mutex_lock(&philo->eating);
		philo->is_eating = 0;
		pthread_mutex_unlock(&philo->eating);
	}
	else
	{
		pthread_mutex_unlock(philo->death);
		ft_fork_unlock_on_death(philo);
	}
}
