/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:30:12 by mzarichn          #+#    #+#             */
/*   Updated: 2023/08/08 11:13:10 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void philosophers()
{
    printf("TUA MAE\n");
}

long int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (res * 10 < -2147483648 || res * 10 > 2147483647)
			return (21474836473);
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * neg);
}

int	check_input(char **av)
{
	int i = 0;
	int j;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				if (av[i][j] != ' ')
					return (1);
			j++;
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	t_data *data;

    if (ac < 5 || ac > 6)
		printf("\n");
	if (check_input(av))
		printf("Erro");
	_init(ac, av, data);
}