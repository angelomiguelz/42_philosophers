/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:30:12 by mzarichn          #+#    #+#             */
/*   Updated: 2023/09/23 16:09:47 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info	*data(void)
{
	static t_info	data;

	return (&data);
}

int	ft_exit(void)
{
	return (1);
}

int	alloc(t_philosopher *philos, t_fork *fork)
{
	int i = -1;
	philos = (t_philosopher *)malloc(sizeof(t_philosopher) * data()->n_philos);
	if (!philos)
		return (false);
	while (++i < data()->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].eaten_meals = 0;
		philos[i].last_meal = get_time();
		philos[i].forks = fork;
	}
	fork = (t_fork *)malloc(sizeof(t_fork) * data()->n_philos);
	if (!fork)
		return (false);
	i = -1;
	while (++i < data()->n_philos)
	{
		fork->taken = false;
		if (pthread_mutex_init(&fork[i].lock, NULL))
			return (false);
	}
	return (true);
}

void	messager(t_philosopher *philo, char *msg)
{
	pthread_mutex_lock(&data()->write);
	printf("%llu %d %s\n", get_time() - data()->start_time, philo->id, msg);
	pthread_mutex_unlock(&data()->write);
}

void	think(void)
{
	messager(philo, "is thinking");
}

int	kill_switch(t_philosopher *philo)
{
	pthread_mutex_lock(&data()->death_lock);
	if (get_time() - philo->last_meal >= data()->time_to_die)
	{
		messager(philo, "died");
		data()->dead = true;
		pthread_mutex_unlock(&data()->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&data()->death_lock);
	return (false);
}

void	*routine(void *philos)
{
	t_philosopher *philo = philos;
	if (philo->id % 2 != 0)
	{
		think();
	}
	return (NULL);
}

int	thread_starter(t_philosopher *philos)
{
	int i = -1;
	while (++i < data()->n_philos)
	{
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]))
			return (false);
	}
	i = -1;
	while (++i < data()->n_philos)
		if (pthread_join(philos[i].philo, NULL))
			return (false);
	return (true);
}

int main(int ac, char **av)
{
	t_philosopher *philos = NULL;
	t_fork		*forks = NULL;

	if (check_input(ac, av))
		return (1);
	if (init_data(ac, av))
		return (1);
	if (alloc(philos, forks))
		return (1);
	if (thread_starter(philos))
		return (1);
	return (0);
}