#include "philosophers.h"

int	check_death(t_philosopher *philo)
{
	if (if_is_dead())
		return true;
	pthread_mutex_lock(&data()->death_lock);
	if (get_time() - (uint64_t)philo->last_meal >= (uint64_t)data()->time_to_die)
	{
		data()->dead = true;
		printf("%s%llu %d %s\n", RED, get_time() - data()->start_time, philo->id, "died");
		pthread_mutex_unlock(&data()->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&data()->death_lock);
	return (false);
}

void	waiting_process(t_philosopher *philo, uint64_t time)
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

void	go_sleep(t_philosopher *philo)
{
	messager(philo, "is sleeping", YELLOW);
	waiting_process(philo, data()->time_to_sleep);
}

void	think(t_philosopher *philo)
{
	messager(philo, "is thinking", PINK);
}