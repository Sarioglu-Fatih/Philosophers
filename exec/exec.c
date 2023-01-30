/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:12:58 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/30 15:53:11 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



void	get_usleep(long time)
{
	struct timeval	tv;
	long			fixe_time;
	long			mobile_time;

	gettimeofday(&tv, NULL);
	fixe_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	mobile_time = fixe_time;
	while (mobile_time - fixe_time < time)
	{
		gettimeofday(&tv, NULL);
		mobile_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		usleep(300);
	}
}

void	think(t_philo *philo)
{
	if ((*philo).dead == FALSE)
	{
		printf("%8ld ms  -  Philo No %4d  is thinking\n", new_timestamp((*philo).time_stamp), (*philo).philo_no);
	}
	if (get_timestamp() - (*philo).last_eat >= (*philo).time_to_die)
		philo_is_dead(philo);
}

void	sleep_time(t_philo *philo)
{
	if ((*philo).dead == FALSE)
	{
		printf("%8ld ms  -  Philo No %4d  is sleeping\n", new_timestamp((*philo).time_stamp), (*philo).philo_no);
	}
	if ((*philo).eat_nb >= (*philo).minimum_eat && (*philo).minimum_eat != -1)
		(*philo).eated = TRUE;
	usleep((*philo).time_to_sleep * 1000);
	if (get_timestamp() - (*philo).last_eat >= (*philo).time_to_die)
		philo_is_dead(philo);
}

void	print_eat(t_philo *philo)
{
	printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
	new_timestamp((*philo).time_stamp), (*philo).philo_no);
	printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
	new_timestamp((*philo).time_stamp), (*philo).philo_no);
	printf("%8ld ms  -  Philo No %4d  is eating\n",
	new_timestamp((*philo).time_stamp), (*philo).philo_no);
	
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(*philo).mutex);
	pthread_mutex_lock((*philo).mutex_left);
	if ((*philo).dead == FALSE)
		print_eat(philo);
	(*philo).start_eating = get_timestamp();
	while ((get_timestamp() - (*philo).start_eating < (*philo).time_to_eat))
	{
		if (get_timestamp() - (*philo).last_eat >= (*philo).time_to_die)
			philo_is_dead(philo);
		usleep(1000);
	}
	pthread_mutex_unlock(&(*philo).mutex);
	pthread_mutex_unlock((*philo).mutex_left);
	(*philo).eat_nb += 1;
	(*philo).last_eat = get_timestamp();
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((*philo).philo_no % 2)
		get_usleep(100);
	while ((*philo).dead == FALSE && ((*philo).eat_nb <= (*philo).minimum_eat || (*philo).minimum_eat == -1))
	{
		eat(philo);
		sleep_time(philo);
		think(philo);
	}
	return (NULL);
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

int	get_all_dead(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)[0].max_philo)
	{
		(*philo)[i].dead = TRUE;
		i++;
	}
	return (-1);
}

int	check(t_philo **philo)
{
	int	i;
	int	eated;

	i = 0;
	while (1)
	{
		i = 0;
		eated = 0;
		while (i < (*philo)[0].max_philo)
		{
			if ((*philo)[i].dead == TRUE)
				return (get_all_dead(philo));
			if ((*philo)[i].eated == 0)
				eated = -1;
			i++;
		}
		if (eated == 0)
			return (get_all_dead(philo));
	}
	return (0);
}

int	exec(int ac, char **av)
{
	int		i;
	int		stop;
	// t_write	write;
	t_philo	*philo;
	
	i = -1;
	if (init(&philo, ac, av) == ERROR)
		return (free_struct(&philo, ft_atoi(av[1]), ERROR));
	set_timestamp(&philo);
	while (++i < philo[0].max_philo)
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
	i = 0;
	stop = 0;
	while (stop == 0)
		stop = check(&philo);
	i = -1;
	while (++i < philo[0].max_philo)
		pthread_detach(philo[i].thread);
	i = -1;
	while (++i < philo[0].max_philo)
		pthread_join(philo[i].thread, NULL);
	return (0);
}
