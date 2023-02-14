/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:12:58 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/14 16:53:13 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	int	state_bis;
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((*philo).philo_no % 2)
		get_usleep(80);
	while (1)
	{
		pthread_mutex_lock(&(*philo).mutex_state);
		state_bis = (*philo).state;
		pthread_mutex_unlock(&(*philo).mutex_state);
		if (state_bis == DEAD || state_bis == STOP)
		{
			usleep(50000);
			return (NULL);
		}
		eat(philo);
		sleep_time(philo);
		think(philo);
	}
	return (NULL);
}

int	exec(int ac, char **av)
{
	int				i;
	int				snb;
	t_philo			*philo;
	
	i = -1;
	snb = ft_atoi(av[1]);
	if (init(&philo, ac, av) == ERROR)
		return (free_struct(&philo, ft_atoi(av[1]), ERROR));
	set_timestamp(&philo);
	if (ft_atoi(av[1]) == 1)
	{
		usleep(ft_atoi(av[2]) * 1000);
		printf("%8ld ms  -  Philo No %4d  diedddddddd\n\n\n",
		new_timestamp((*philo).time_stamp), 0);
		return (0);
	}
	while (++i < snb)
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
	i = 0;
	while (check(&philo, snb) == 0)
		;
	usleep(1000);
	i = -1;
	while (++i < snb)
		pthread_detach(philo[i].thread);
	i = -1;
	while (++i < snb)
	{
		pthread_join(philo[i].thread, NULL);
	}
	// free_struct(&philo, ft_atoi(av[1]), 0);
	return (0);
}

// int	exit_routine(pthread_t th)
// {
// 	// while (thread[i])
// 	// {
// 	// 	pthread_mutex_destroy();
// 	// 	pthread_join();
// 	// }
// 	pthread_join(th, NULL);
// 	return (0);
// }
