/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:42:39 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/10 15:49:27 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	mutex_init(t_philo **philo, int snb, pthread_mutex_t *mutex_write_main)
{
	int	i;

	i = -1;
	pthread_mutex_init(&(*mutex_write_main), NULL);
	while (++i < snb)
	{
		(*philo)[i].dead = FALSE;
		(*philo)[i].mutex_write = &(*mutex_write_main);
		pthread_mutex_init(&(*philo)[i].mutex, NULL);
		pthread_mutex_init(&(*philo)[i].mutex_state, NULL);
	}
	i = 0;
	if (snb > 1)
	{
		(*philo)[0].mutex_left = &(*philo)[snb - 1].mutex;
		while (++i < snb)
			(*philo)[i].mutex_left = &(*philo)[i - 1].mutex;
	}
}

int	init(t_philo **philo, int ac, char **av, pthread_mutex_t *mutex_write_main)
{
	int	i;

	(*philo) = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (ERROR);
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		(*philo)[i].eat_nb = 0;
		(*philo)[i].philo_no = i;
		(*philo)[i].state = MUST_EAT;
		(*philo)[i].max_philo = ft_atoi(av[1]);
		(*philo)[i].time_to_die = ft_atoi(av[2]);
		(*philo)[i].time_to_eat = ft_atoi(av[3]);
		(*philo)[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			(*philo)[i].minimum_eat = ft_atoi(av[5]);
		else
			(*philo)[i].minimum_eat = -1;
		i++;
	}
	mutex_init(philo, ft_atoi(av[1]), mutex_write_main);
	return (0);
}