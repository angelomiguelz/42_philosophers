/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:30:12 by mzarichn          #+#    #+#             */
/*   Updated: 2023/09/19 09:59:33 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void philosophers()
{
    printf("TUA MAE\n");
}

void	_allocation(void)
{
	int i;

	i = -1;
}

void	_create_philos(void)
{
	
}

int main(int ac, char **av)
{
	t_data *data;

	data = NULL;
    if (ac < 5 || ac > 6)
	{
		printf("Input Error\n");
		return (1);
	}
	if (check_input(av))
		printf("Input Error");
	_init(ac, av);
	_create_philos();
}