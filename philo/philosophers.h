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
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long			must_eat;
	u_int64_t		start_time;
	int				dead;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	write;
	t_philosopher	*philo;
}	t_info;

//# define DEFAULT "\033[0;39m"
# define RED "\033[0;91m"
//# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"

int init_data(int ac, char **av);
int	alloc(t_philosopher **philos);
int	cleaning(t_philosopher *philos, t_fork *forks);
t_info	*data(void);

//utils
int			error(char *str);
int			check_input(int ac, char **av);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t nitems, size_t size);

//time functions
int	get_time(void);

int	start();

bool	if_is_dead();
void	*routine(void *philos);
void	messager(t_philosopher *philo, char *msg, char *color);
int	check_death(t_philosopher *philo);
bool	if_is_dead();
void	waiting_process(t_philosopher *philo, uint64_t time);
int	thread_starter(t_philosopher *philos);
void	think(t_philosopher *philo);
void	go_sleep(t_philosopher *philo);

#endif