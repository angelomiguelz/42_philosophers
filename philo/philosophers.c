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



int main(int ac, char **av)
{
	if (check_input(ac, av))
		return (1);
	if (init_data(ac, av))
		return (1);
	if (alloc(&data()->philo))
	{ 
		return (1);
	}
	if (thread_starter(data()->philo))
	{
		cleaning(data()->philo, data()->philo->forks);
		return (1);
	}
	return (0);
}