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
	data()->time_to_die = (u_int64_t)ft_atoi(av[2]);
	data()->time_to_eat = (u_int64_t)ft_atoi(av[3]);
	data()->time_to_sleep = (u_int64_t)ft_atoi(av[4]);
	if (ac == 6)
		data()->must_eat = ft_atoi(av[5]);
	else
		data()->must_eat = INT_MAX;
	if (data()->n_philos <= 0 || data()->n_philos > 200 || data()->time_to_die < 0
		|| data()->time_to_eat < 0 || data()->time_to_sleep < 0)
		return (error("Input Error Limits"));
	data()->start_time = get_time();
	data()->dead = 0;
	pthread_mutex_init(&data()->death_lock, NULL);
	pthread_mutex_init(&data()->write, NULL);
	return (0);
}