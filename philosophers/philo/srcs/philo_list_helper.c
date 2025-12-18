/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:54:37 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/26 15:54:39 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_set_death_flag(t_monitor *monitor)
{
	t_philos	*philo;
	int			philo_amount;
	int			i;

	philo = monitor->philos;
	philo_amount = 1;
	if (philo->prev)
		philo_amount = philo->prev->id;
	i = 0;
	while (i < philo_amount)
	{
		philo->death_flag = &monitor->death_flag;
		philo = philo->next;
		i++;
	}
}

t_philos	*ft_new_philo(int id, int *input, pthread_mutex_t *mutexes)
{
	t_philos	*new_philo;

	if (id <= 0)
		return (NULL);
	new_philo = malloc(1 * sizeof(t_philos));
	if (!new_philo)
		return (NULL);
	new_philo->id = id;
	new_philo->is_eating = 0;
	new_philo->time_to_die = input[1];
	new_philo->time_to_eat = input[2];
	new_philo->time_to_sleep = input[3];
	new_philo->death_flag = NULL;
	new_philo->times_fed = 0;
	new_philo->last_meal = 0;
	new_philo->print = &mutexes[0];
	new_philo->death = &mutexes[1];
	pthread_mutex_init(&new_philo->eating, NULL);
	pthread_mutex_init(&new_philo->fork, NULL);
	new_philo->prev = NULL;
	new_philo->next = NULL;
	return (new_philo);
}

//Function will look for the philosopher with the corresponding ID number
t_philos	*ft_get_philo(t_philos *head, int id)
{
	if (id <= 0)
		return (NULL);
	if (id == 1)
		return (head);
	while (head->id != id)
		head = head->next;
	return (head);
}

//a function that add a philo after the id - 1 position
//the structure will be of a circular double linked list
//the stopping point is the amount of philosophers
int	ft_add_philo(t_philos **head, int id, int *input, pthread_mutex_t *mutexes)
{
	t_philos	*first_philo;
	t_philos	*last_philo;
	t_philos	*new_philo;

	if (id <= 0 || !head)
		return (1);
	first_philo = NULL;
	last_philo = NULL;
	new_philo = ft_new_philo(id, input, mutexes);
	if (id == 1)
		*head = new_philo;
	else
	{
		first_philo = ft_get_philo(*head, 1);
		last_philo = ft_get_philo(*head, id - 1);
		last_philo->next = new_philo;
		first_philo->prev = new_philo;
		new_philo->prev = last_philo;
		new_philo->next = first_philo;
	}
	return (0);
}

//Main function that creates the philosophers chain
t_philos	*ft_create_philos(int *input, pthread_mutex_t *mutexes)
{
	t_philos	*head;
	int			id;

	if (input[0] <= 0)
		return (NULL);
	id = 1;
	while (id <= input[0])
	{
		ft_add_philo(&head, id, input, mutexes);
		id++;
	}
	return (head);
}

//debugging function to print the philo chain
/*
int	ft_print_philo_chain(t_philos *head, int philo_amount)
{
	int			id;
	t_philos	*philo;

	id = 1;
	philo = NULL;
	while (id <= philo_amount)
	{
		philo = ft_get_philo(head, id);
		printf("PHILO NUMBER %d------\n", id);
		printf("ADDRESS: %p\n", philo);
		printf("ID: %d\n", philo->id);
		printf("IS EATING: %d\n", philo->is_eating);
		printf("TIME TO EAT: %d\n", philo->time_to_eat);
		printf("TIME TO SLEEP: %d\n", philo->time_to_sleep);
		printf("TIMES FED: %u\n", philo->times_fed);
		printf("LAST MEAL: %ld\n", philo->last_meal);
		printf("PREV PHILO: %p\n", philo->prev);
		printf("NEXT PHILO: %p\n", philo->next);
		printf("---------------------\n");
		id++;
	}
	return (0);
}*/
