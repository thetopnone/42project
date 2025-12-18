/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:35:09 by akonstan          #+#    #+#             */
/*   Updated: 2025/12/18 20:35:11 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_safe_print(t_philos *philo, char *str)
{
	if (!philo || !str)
		return ;
	pthread_mutex_lock(philo->print);
	printf("%ld %d %s\n", ft_get_time_in_ms(), philo->id, str);
	pthread_mutex_unlock(philo->print);
}

void	ft_monitor_update_death_flag(t_monitor *monitor, t_philos *philo)
{
	pthread_mutex_lock(philo->death);
	monitor->death_flag = 1;
	pthread_mutex_unlock(philo->death);
}

void	ft_fork_unlock_on_death(t_philos *philo)
{
	if (philo->id == 1)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->prev->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->prev->fork);
		pthread_mutex_unlock(&philo->fork);
	}
}
