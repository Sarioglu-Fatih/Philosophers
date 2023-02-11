/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:06 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/10 15:49:39 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define MUST_EAT 2
# define FINISH_EAT 3
# define DEAD -2
# define STOP -3

typedef struct		s_philo
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	mutex_state;
	pthread_mutex_t	*mutex_write;
	int				philo_no;
	int				max_philo;
	int				eat_nb;
	int				minimum_eat;
	long			last_eat;
	long			last_eat_bis;
	int				time_to_eat;
	int				time_to_sleep;
	long			time_to_die;
	int				dead;
	long			start_sleep;
	int				eated;
	int				state;
	long			time_stamp;
}					t_philo;

//parsing
int	parsing(int ac, char **av);

//exec
void	eat(t_philo *philo);
void	think(t_philo *philo);
int		exec(int ac, char **av);
void	sleep_time(t_philo *philo);
long	new_timestamp(long time_stamp);
int		check(t_philo **philo, int snb);
void	print_state(t_philo *philo, long time_stamp, int philo_no, int state);
int		init(t_philo **philo, int ac, char **av, pthread_mutex_t *mutex_write_main);

//utils
char	*ft_itoa(int n);
long	get_timestamp(void);
int	    ft_strlen(char *str);
void	get_usleep(long time);
int		ft_atoi(const char *str);
void	set_timestamp(t_philo **philo);
int		free_struct(t_philo **philo, int snb, int ret);

#endif