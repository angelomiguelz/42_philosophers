/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:35:08 by mzarichn          #+#    #+#             */
/*   Updated: 2023/09/23 16:14:13 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

struct	s_data;

typedef struct s_death
{
	int				dead;
	pthread_mutex_t	lock;
}				t_death;

typedef struct s_fork
{
	int				taken;
	pthread_mutex_t fork;
}				t_fork;

typedef struct s_data
{
	long			philo_num;
	long			death_time;
	long			eat_time;
	long			sleep_time;
	long			start_time;
	long			meals_nb;
	t_death			death;
	pthread_mutex_t	write;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	t_fork			*forks;
	pthread_t		philo;
	int				id;
	int				eat_cont;
	int				last_meal;
}	t_philo;


t_data	*data(void);
t_death *death(void);
t_philo	*philo(void);

int _init(int ac, char **av);

//utils
int	error(char *str);
int	check_input(int ac, char **av);
long int	ft_atoi(const char *str);
void	*ft_calloc(size_t nitems, size_t size);

//

#endif