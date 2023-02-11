/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:12:58 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/10 16:45:33 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((*philo).philo_no % 2)
		get_usleep(80);
	while (1)
	{
		pthread_mutex_lock(&(*philo).mutex_state);
		if ((*philo).state == DEAD || (*philo).state == STOP)
		{
			pthread_mutex_unlock(&(*philo).mutex_state);
			usleep(50000);
			break;
		}
		pthread_mutex_unlock(&(*philo).mutex_state);
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
	pthread_mutex_t	mutex_write_main;
	
	i = -1;
	snb = ft_atoi(av[1]);
	if (init(&philo, ac, av, &mutex_write_main) == ERROR)
		return (free_struct(&philo, ft_atoi(av[1]), ERROR));
	set_timestamp(&philo);
	while (++i < snb)
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
	i = 0;
	while (check(&philo, snb) == 0)
		;
	usleep(2000);
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
