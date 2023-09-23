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

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_death *death(void)
{
	static t_death death;

	return (&death);
}

t_philo	*philo(void)
{
	static t_philo	philo;

	return (&philo);
}

int main(int ac, char **av)
{
	(void)data;
	if (check_input(ac, av))
		printf("Input Error");
	_init(ac, av);
}