/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:11:53 by mzarichn          #+#    #+#             */
/*   Updated: 2023/09/23 16:15:46 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_data(int ac, char **av)
{
	data()->n_philos = ft_atoi(av[1]);
	data()->time_to_die = ft_atoi(av[2]);
	data()->time_to_eat = ft_atoi(av[3]);
	data()->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data()->must_eat = ft_atoi(av[5]);
	else
		data()->must_eat = INT_MAX;
	if (data()->n_philos <= 0 || data()->n_philos > 200 || (int)data()->time_to_die < 0 \
		|| (int)data()->time_to_eat < 0 || (int)data()->time_to_sleep < 0)
		return (error("Input Error Limits"));
	data()->start_time = get_time();
	data()->dead = 0;
	pthread_mutex_init(&data()->death_lock, NULL);
	pthread_mutex_init(&data()->write, NULL);
	return (0);
}

int	fill_allocation(t_philosopher **philos, t_fork *forks)
{
	int i = -1;

	while (++i < data()->n_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eaten_meals = 0;
		(*philos)[i].last_meal = get_time();
		(*philos)[i].forks = forks;
	}
	i = -1;
	while (++i < data()->n_philos)
	{
		forks[i].taken = false;
		if (pthread_mutex_init(&forks[i].lock, NULL))
			return (1);
	}
	return (0);
}

int	alloc(t_philosopher **philos)
{
	t_fork *forks;

	forks = NULL;
	(*philos) = (t_philosopher *)malloc(sizeof(t_philosopher) * data()->n_philos);
	if (!(*philos))
	{
		cleaning(*philos, forks);
		return (1);
	}
	forks = (t_fork *)malloc(sizeof(t_fork) * data()->n_philos);
	if (!forks)
	{
		cleaning(NULL, forks);
		return (1);
	}
	if (fill_allocation(philos, forks))
		return (1);
	return (0);
}

int	thread_starter(t_philosopher *philos)
{
	int i = -1;
	while (++i < data()->n_philos)
	{
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]))
			return (1);
	}
	i = -1;
	while (++i < data()->n_philos)
		if (pthread_join(philos[i].philo, NULL))
			return (1);
	cleaning(data()->philo, data()->philo->forks);
	return (0);
}