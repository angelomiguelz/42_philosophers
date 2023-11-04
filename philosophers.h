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
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <stdint.h>
# include <unistd.h>
# include <stddef.h>
#include <stdbool.h>

/*
** Routines messages
*/
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

/*
** Colors
*/
# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

typedef struct s_fork
{
	int				taken;
	pthread_mutex_t lock;
}				t_fork;

typedef struct s_philosopher
{
	t_fork			*forks;
	pthread_t		philo;
	int				id;
	int				eaten_meals;
	int				last_meal;
}	t_philosopher;

typedef struct s_info
{
	long			n_philos;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	long			must_eat;
	u_int64_t		start_time;
	int				dead;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	write;
	t_philosopher	*philo;
}	t_info;




t_info	*data(void);
t_philosopher	*philo(void);

int init_data(int ac, char **av);

//utils
int			error(char *str);
int			check_input(int ac, char **av);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t nitems, size_t size);

//time functions
u_int64_t get_time(void);


int	start();


#endif