/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:42:40 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/25 21:42:41 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				id;
	int				is_eating;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_fed;
	int				*death_flag;
	long			last_meal;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death;
	pthread_mutex_t	eating;
	pthread_mutex_t	fork;
	struct s_philos	*prev;
	struct s_philos	*next;
}	t_philos;

typedef struct s_monitor
{
	t_philos		*philos;
	pthread_t		*philo;
	int				*input;
	int				death_flag;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				target_times_to_eat;
}	t_monitor;

//-----------------------------------------------------------------------------
// CLEANER (2)
//-----------------------------------------------------------------------------
int			ft_del_philo_chain(t_philos **head, int philo_amount);
int			ft_exit(t_philos **head, int **input);
//-----------------------------------------------------------------------------
// MONITOR ROUTINE (2)
//-----------------------------------------------------------------------------
int			ft_check_philo_death(t_monitor *monitor);
void		*ft_monitor_routine(void *arg);
//-----------------------------------------------------------------------------
// PHILO ROUTINE (5)
//-----------------------------------------------------------------------------
long		ft_get_time_in_ms(void);
void		ft_philo_thinking(t_philos *philo);
void		ft_philo_eating(t_philos *philo);
void		ft_philo_sleeping(t_philos *philo);
void		*ft_philo_routine(void *arg);
//-----------------------------------------------------------------------------
// PHILO ROUTINE HELPER (4)
//-----------------------------------------------------------------------------
void		ft_usleep(long ms);
void		ft_grab_front_fork(t_philos *philo);
void		ft_grab_left_fork(t_philos *philo);
void		ft_eat_and_leave_forks(t_philos *philo);
//-----------------------------------------------------------------------------
// THREAD INIT (2)
//-----------------------------------------------------------------------------
t_monitor	*ft_allocate_monitor(int *input);
int			ft_init_monitor(t_monitor *monitor, pthread_t *monitor_thread);
pthread_t	*ft_init_philos(t_philos *philos, int philo_amount);
void		ft_thread_join(t_monitor *monitor, pthread_t thread,
				int philo_amount);
//-----------------------------------------------------------------------------
// INPUT HELPER (4)
//-----------------------------------------------------------------------------
int			ft_check_input(int argc, char **argv);
void		ft_get_input(char **argv, int *input);
//-----------------------------------------------------------------------------
// PHILO LIST HELPER (5)
//-----------------------------------------------------------------------------
void		ft_set_death_flag(t_monitor *monitor);
t_philos	*ft_new_philo(int id, int *input, pthread_mutex_t *print);
t_philos	*ft_get_philo(t_philos *head, int id);
int			ft_add_philo(t_philos **head, int id, int *input,
				pthread_mutex_t *print);
t_philos	*ft_create_philos(int *input, pthread_mutex_t *print);
int			ft_print_philo_chain(t_philos *head, int philo_amount);
//-----------------------------------------------------------------------------
// ROUTINE UTILS (3)
//-----------------------------------------------------------------------------
void		ft_safe_print(t_philos *philo, char *str);
void		ft_monitor_update_death_flag(t_monitor *monitor, t_philos *philo);
void		ft_fork_unlock_on_death(t_philos *philo);
#endif