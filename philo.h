/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:06 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/22 16:20:38 by fsariogl         ###   ########.fr       */
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
	int				fork;
	int				philo_no;
	int				max_philo;
	int				eat_nb;
	int				minimum_eat;
	int				last_eat;	
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				dead;
	int				eated;
	unsigned int	time_stamp;
}					t_philo;

//parsing
int	parsing(int ac, char **av);

//exec
int		exec(int ac, char **av);
int		init(t_philo **philo, int ac, char **av);

//utils
char	*ft_itoa(int n);
int	    ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		free_struct(t_philo **philo, int snb, int ret);

#endif