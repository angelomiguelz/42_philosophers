/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:30:12 by mzarichn          #+#    #+#             */
/*   Updated: 2023/09/23 16:06:34 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int main(int ac, char **av)
{
	t_data *data;

	data = NULL;
	(void)data;
	if (check_input(ac, av))
		printf("Input Error");
	_init(ac, av);
}