/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:11:53 by mzarichn          #+#    #+#             */
/*   Updated: 2023/08/08 11:17:46 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int _init(int ac, char **av, t_data *data)
{
	data->num_philosophers = (int) ft_atoi(av[1]);
	data->t_die = (int) ft_atoi(av[2]);
	data->t_eat = (int) ft_atoi(av[3]);
	data->t_sleep = (int) ft_atoi(av[4]);
	if (ac == 6)
		data->numb_must_eat = (int) ft_atoi(av[5]);
	else
		data->numb_must_eat = -1;
	if (data->num_philosophers <= 0 || data->num_philosophers > 200 || data->t_die < 0
		|| data->t_eat < 0 || data->t_sleep < 0)
		return (1);
	data->ndead = 0;
	data->nfinished = 0;
}