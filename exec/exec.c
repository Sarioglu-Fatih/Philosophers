/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:12:58 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/16 17:33:12 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	alone(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)[0].mutex);
	printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		new_timestamp((*philo)[0].time_stamp), (*philo)[0].philo_no);
	usleep((*philo)[0].time_to_die * 1000);
	printf("%8ld ms  -  Philo No %4d  diedddddddd\n\n\n",
		new_timestamp((*philo)[0].time_stamp), 0);
	pthread_mutex_unlock(&(*philo)[0].mutex);
	free_struct(philo, 1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		state_bis;

	philo = (t_philo *)arg;
	if ((*philo).philo_no % 2)
	{
		think(philo);
		usleep(20000);
	}
	while (1)
	{
		pthread_mutex_lock(&(*philo).mutex_state);
		state_bis = (*philo).state;
		pthread_mutex_unlock(&(*philo).mutex_state);
		if (state_bis == DEAD || state_bis == STOP)
		{
			usleep(100000);
			return (NULL);
		}
		eat(philo);
		sleep_time(philo);
		think(philo);
	}
	return (NULL);
}

static void	stop_all_thread(t_philo **philo, int i, int snb)
{
	int	temp;

	temp = i;
	while (--i >= 0)
	{
		pthread_mutex_lock(&(*philo)[i].mutex_state);
		(*philo)[i].state = STOP;
		pthread_mutex_unlock(&(*philo)[i].mutex_state);
	}
	i = temp;
	while (i < 0)
		pthread_join((*philo)[i].thread, NULL);
	free_struct(philo, snb);
}

static int	creat_all_thread(t_philo **philo, int snb)
{
	int	i;

	i = 0;
	while (i < snb)
	{
		if (pthread_create(&(*philo)[i].thread, NULL, &routine, &(*philo)[i]) != 0)
		{
			stop_all_thread(philo, i, snb);
			return (ERROR);
		}
		i++;
	}
	return (0);
}

int	exec(int ac, char **av)
{
	int				i;
	int				snb;
	t_philo			*philo;

	i = -1;
	snb = ft_atoi(av[1]);
	if (init(&philo, ac, av) == ERROR)
		return (ERROR);
	set_timestamp(&philo);
	if (ft_atoi(av[1]) == 1)
		return (alone(&philo));
	if (creat_all_thread(&philo, snb) != 0)
		return (ERROR);
	while (check(&philo, snb) == 0)
		;
	usleep(1000);
	i = -1;
	while (++i < snb)
		pthread_join(philo[i].thread, NULL);
	free_struct(&philo, ft_atoi(av[1]));
	return (0);
}
