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
	printf("%s%lu %d %s\n", color, get_time() - data()->start_time, philo->id, msg);
	pthread_mutex_unlock(&data()->write);
}