#include "philosophers.h"

// create error handler
int	error(char *str)
{
	printf("%s\n", str);
	return (1);
}

void	messager(t_philosopher *philo, char *msg, char *color)
{
	pthread_mutex_lock(&data()->write);
	printf("%s%llu %d %s\n", color, get_time() - data()->start_time, philo->id, msg);
	pthread_mutex_unlock(&data()->write);
}

int	cleaning(t_philosopher *philos, t_fork *forks)
{
	int	i;

	i = -1;
	if (philos)
	{
		pthread_mutex_destroy(&data()->write);
		pthread_mutex_destroy(&data()->death_lock);
		free(philos);
	}
	i = -1;
	if (forks)
	{
		while (++i < data()->n_philos)
			pthread_mutex_destroy(&forks[i].lock);
		free(forks);
	}
	return (0);
}