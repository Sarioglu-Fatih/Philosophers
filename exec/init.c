/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:42:39 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/22 17:39:30 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	left_mutex_pointer(t_philo **philo, int snb)
{
	int	i;

	i = 1;
	if (snb > 1)
	{
		(*philo)[0].mutex_left = &(*philo)[snb - 1].mutex;
		while (i < snb)
		{
			(*philo)[i].mutex_left = &(*philo)[i - 1].mutex;
			i++;
		}
	}
}

static void	set_time_stamp(t_philo **philo, int snb)
{
	struct timeval	tv;
	int				i;
	int				time;

	i = -1;
	gettimeofday(&tv, NULL);
	time = tv.tv_sec % 1000000;
	time = (time * 1000) + (tv.tv_usec / 1000);
	while (++i < snb)
	{
		(*philo)[i].dead = FALSE;
		(*philo)[i].eated = FALSE;
		(*philo)[i].time_stamp = time;
		pthread_mutex_init(&(*philo)[i].mutex, NULL);
	}
	left_mutex_pointer(philo, snb);
}

int	init(t_philo **philo, int ac, char **av)
{
	int	i;

	(*philo) = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (ERROR);
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		(*philo)[i].eat_nb = 0;
		(*philo)[i].fork = TRUE;
		(*philo)[i].philo_no = i;
		(*philo)[i].max_philo = ft_atoi(av[1]);
		(*philo)[i].time_to_die = ft_atoi(av[2]);
		(*philo)[i].time_to_eat = ft_atoi(av[3]);
		(*philo)[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			(*philo)[i].minimum_eat = ft_atoi(av[5]);
		else
			(*philo)[i].minimum_eat = 2000000000;
		i++;
	}
	set_time_stamp(philo, ft_atoi(av[1]));
	return (0);
}