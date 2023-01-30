/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:06 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/30 15:43:43 by fsariogl         ###   ########.fr       */
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

typedef struct		s_philo
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*writing;
	int				philo_no;
	int				max_philo;
	int				eat_nb;
	long			start_eating;
	int				minimum_eat;
	long			last_eat;	
	int				time_to_eat;
	int				time_to_sleep;
	long			time_to_die;
	int				dead;
	int				eated;
	long			time_stamp;
}					t_philo;

typedef struct		s_write
{
	pthread_mutex_t	writing;
}					t_write;

//parsing
int	parsing(int ac, char **av);

//exec
int		exec(int ac, char **av);
void	philo_is_dead(t_philo *philo);
long	new_timestamp(long time_stamp);
int		init(t_philo **philo, int ac, char **av);

//utils
char	*ft_itoa(int n);
long	get_timestamp(void);
int	    ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	set_timestamp(t_philo **philo);
int		free_struct(t_philo **philo, int snb, int ret);

#endif