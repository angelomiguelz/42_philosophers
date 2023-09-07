/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:35:08 by mzarichn          #+#    #+#             */
/*   Updated: 2023/09/07 16:12:29 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

struct	s_data;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t fork;
}				t_fork;

typedef struct s_philo
{
	pthread_t		thread1;
	int				id;
	int				eat_cont;
	int				eating;
	long			time_to_die;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	long			philo_num;
	long				meals_nb;
	long			death_time;
	long			eat_time;
	long			sleep_time;
	long			start_time;
	pthread_mutex_t	dead;
	pthread_mutex_t	write;
}	t_data;

t_data	*data(void);

int _init(int ac, char **av);

//utils
int	error(char *str);
int	check_input(char **av);
long int	ft_atoi(const char *str);
void	ft_calloc(size_t nitems, size_t size);

//

#endif