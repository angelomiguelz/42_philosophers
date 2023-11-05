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

void	messager(t_philosopher *philo, char *msg)
{
	pthread_mutex_lock(&data()->write);
	printf("%llu %d %s\n", get_time() - data()->start_time, philo->id, msg);
	pthread_mutex_unlock(&data()->write);
}

int	check_death(t_philosopher *philo)
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

void	sleeping_process(t_philosopher *philo, uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (check_death(philo))
			return ;
		usleep(time / 10); //qual melhor valor?
	}
	check_death(philo);
}
bool	if_is_dead()
{
	pthread_mutex_lock(&data()->death_lock);
	if (data()->dead == true)
	{
		pthread_mutex_unlock(&data()->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&data()->death_lock);
	return (false);
}

int	alloc(t_philosopher **philos, t_fork **fork)
{
	int i = -1;
	(*philos) = (t_philosopher *)malloc(sizeof(t_philosopher) * data()->n_philos);
	if (!philos)
		return (1);
	(*fork) = (t_fork *)malloc(sizeof(t_fork) * data()->n_philos);
	if (!(*fork))
		return (1);
	while (++i < data()->n_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eaten_meals = 0;
		(*philos)[i].last_meal = get_time();
		(*philos)[i].forks = (*fork);
	}
	i = -1;
	while (++i < data()->n_philos)
	{
		(*fork)->taken = false;
		if (pthread_mutex_init(&(*fork)[i].lock, NULL))
			return (1);
	}
	if (philos == NULL)
		printf("SECOND NULL\n");
	return (0);
}



void	think(t_philosopher *philo)
{
	messager(philo, "is thinking");
}



void	unlock_fork(t_fork *fork)
{
	while (if_is_dead() == false)
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->taken == true)
		{
			fork->taken = false;
			pthread_mutex_unlock(&fork->lock);
			break ;
		}
		else
			pthread_mutex_unlock(&fork->lock);
	}
}

void	lock_fork(t_fork *fork, t_philosopher *philo)
{
	while (if_is_dead() == false)
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->taken == false)
		{
			fork->taken = true;
			pthread_mutex_unlock(&fork->lock);
			messager(philo, "has taken a fork");
			break ;
		}
		else
			pthread_mutex_unlock(&fork->lock);
	}
}

void	eat(t_philosopher *philo)
{
	int r_fork;
	int l_fork;

	r_fork = ((philo->id == 1) * (data()->n_philos - 1) + \
	((philo->id != 1) * (philo->id - 1)));
	l_fork = (philo->id - 1 - (philo->id != 1));
	lock_fork(&philo->forks[r_fork], philo);
	lock_fork(&philo->forks[l_fork], philo);
	messager(philo, "is eating");
	philo->last_meal = get_time();
	sleeping_process(philo, data()->time_to_eat);
	philo->eaten_meals += 1;
	unlock_fork(&philo->forks[r_fork]);
	unlock_fork(&philo->forks[l_fork]);
}




void	go_sleep(t_philosopher *philo)
{
	messager(philo, "is sleeping");
	sleeping_process(philo, data()->time_to_sleep);
}

void	*routine(void *philos)
{
	t_philosopher *philo = philos;
	if (philo->id % 2 != 0)
	{
		think(philo);
	}
	while (philo->eaten_meals < data()->must_eat && check_death(philo) == false)
	{
		eat(philo);
		if (if_is_dead() == true)
			return (NULL);
		go_sleep(philo);
		if (if_is_dead() == true)
			return (NULL);
		think(philo);
	}
	return (NULL);
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
	return (0);
}

int main(int ac, char **av)
{
	t_philosopher *philos = NULL;
	t_fork		*forks = NULL;

	if (check_input(ac, av))
	{
		return (1);
	}
	if (init_data(ac, av))
	{
		return (1);
	}
	if (alloc(&philos, &forks))
	{ 
		printf("RETURNED\n");
		return (1);
	}
	if (thread_starter(philos))
	{
		return (1);
	}
	return (0);
}