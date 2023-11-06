#include "philosophers.h"

void	unlock_fork(t_fork *fork)
{
    pthread_mutex_lock(&fork->lock);
    if (fork->taken == true)
    {
        fork->taken = false;
        pthread_mutex_unlock(&fork->lock);
        return ;
    }
    else
        pthread_mutex_unlock(&fork->lock);
}

void	lock_fork(t_fork *fork, t_philosopher *philo)
{
	while (check_death(philo) == false)
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->taken == false)
		{
			fork->taken = true;
			pthread_mutex_unlock(&fork->lock);
			messager(philo, "has taken a fork", B_BLUE);
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
	if (if_is_dead())
		return ;
	messager(philo, "is eating", GREEN);
	philo->last_meal = get_time();
	waiting_process(philo, data()->time_to_eat); //pode trocar?
	philo->eaten_meals += 1;
	unlock_fork(&philo->forks[r_fork]);
	unlock_fork(&philo->forks[l_fork]);
}

void	*routine(void *philos)
{
	t_philosopher *philo = philos;

    if (data()->n_philos % 2 != 0 && philo->id == data()->n_philos)
		messager(philo, "is thinking", GREEN);
	if (philo->id % 2 == 0)
	{
		think(philo);
		waiting_process(philo, data()->time_to_eat); //nao e time to think
	}
	while (philo->eaten_meals < data()->must_eat && !check_death(philo))
	{
		eat(philo);
		if (if_is_dead() == true)
			return (NULL);
		go_sleep(philo);
		if ((data()->n_philos % 2) != 0)
        	waiting_process(philo, 100);
		if (if_is_dead() == true)
			return (NULL);
		think(philo);
	}
	return (NULL);
}