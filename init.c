/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:11:53 by mzarichn          #+#    #+#             */
/*   Updated: 2023/09/19 10:04:11 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void allocation(void)
{
}

int _init(int ac, char **av)
{
	int res = 0;
	data()->philo_num = ft_atoi(av[1]);
	data()->death_time = ft_atoi(av[2]);
	data()->eat_time = ft_atoi(av[3]);
	data()->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data()->meals_nb = ft_atoi(av[5]);
	else
		data()->meals_nb = -1;
	if (data()->philo_num <= 0 || data()->philo_num > 200 || data()->death_time < 0
		|| data()->eat_time < 0 || data()->sleep_time < 0)
		return (error("Input Error Limits"));
	pthread_mutex_init(&data()->write, NULL);
	
	allocation();
	
	return (0);
}