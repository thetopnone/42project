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

long	ft_time_in_ms(struct timeval time)
{
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}
/*
void	ft_usleep(long ms)
{
	long	i;

	if (ms <= 0)
		return ;
	i = 0;
	while (i <= ms * 1000)
	{
		usleep(1);
		i++;
	}
    printf("Finished usleep\n");
}*/

//Makes current philo attempt to grab the fork in front of him
void	ft_grab_front_fork(t_philos *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&philo->fork);
	gettimeofday(&time, NULL);
	pthread_mutex_lock(philo->print);
	printf("[%ld] Philo %d grabbed a fork\n", ft_time_in_ms(time), philo->id);
	pthread_mutex_unlock(philo->print);
}

//Makes current philo attemp to grab the fork of the philo to his left
void	ft_grab_left_fork(t_philos *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&philo->prev->fork);
	gettimeofday(&time, NULL);
	pthread_mutex_lock(philo->print);
	printf("[%ld] Philo %d grabbed a fork\n", ft_time_in_ms(time), philo->id);
	pthread_mutex_unlock(philo->print);
}

//Philo eats, sets flag to pause death timer, resets last_meal time and 
//releases all forks that have been taken
//is eating mutex is to block the death if the philosopher manages to start
//eating in time
void	ft_eat_and_leave_forks(t_philos *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&philo->eating);
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_lock(philo->print);
	printf("[%ld] Philo %d is eating\n", ft_time_in_ms(time), philo->id);
	pthread_mutex_unlock(philo->print);
	//printf("Time to eat: %d\n", philo->time_to_eat);
	usleep(1000 * philo->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->prev->fork);
	philo->times_fed++;
    pthread_mutex_lock(&philo->eating);
	philo->is_eating = 0;
    pthread_mutex_unlock(&philo->eating);
	gettimeofday(&time, NULL);
	philo->last_meal = ft_time_in_ms(time);
}
