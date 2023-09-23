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

uint64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((uint64_t)(tv.tv_sec * 1000) + (uint64_t)(tv.tv_usec / 1000));
}

int _init(int ac, char **av)
{
	//data
	data()->philo_num = ft_atoi(av[1]);
	data()->death_time = ft_atoi(av[2]);
	data()->eat_time = ft_atoi(av[3]);
	data()->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data()->meals_nb = ft_atoi(av[5]);
	else
		data()->meals_nb = INT_MAX;
	if (data()->philo_num <= 0 || data()->philo_num > 200 || data()->death_time < 0
		|| data()->eat_time < 0 || data()->sleep_time < 0)
		return (error("Input Error Limits"));

	data()->start_time = get_time();

	death()->dead = 0;
	pthread_mutex_init(&death()->lock, NULL);

	pthread_mutex_init(&data()->write, NULL);
	
	return (0);
}