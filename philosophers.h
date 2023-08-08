/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:35:08 by mzarichn          #+#    #+#             */
/*   Updated: 2023/08/08 11:17:55 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_data
{
	int	num_philosophers;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	numb_must_eat;
	int ndead;
	int nfinished;
}				t_data;

typedef struct s_philo
{
	int	idx;
}				t_philo;

long int	ft_atoi(const char *str);
int _init(int ac, char **av, t_data *data);

#endif