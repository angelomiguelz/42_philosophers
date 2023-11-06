/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:49:44 by mzarichn          #+#    #+#             */
/*   Updated: 2023/09/23 16:07:07 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int	check_input(int ac, char **av)
{
	int i = 0;
	int j;

	if (ac < 5 || ac > 6)
	{
		printf("Input Error");
		return (1);
	}
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				if (av[i][j] != ' ')
				{
					printf("Input Error");
					return (1);
				}
			j++;
		}
	}
	return (0);
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

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	i;
	unsigned char	*tmp;

	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	i = 0;
	tmp = (void *)ptr;
	while (i < nitems * size)
		tmp[i++] = 0;
	return (ptr);
}