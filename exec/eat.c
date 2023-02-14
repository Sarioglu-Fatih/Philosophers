/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:49 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/14 17:01:33 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	lock_fork(t_philo *philo)
{
	if ((*philo).philo_no % 2)
	{
		pthread_mutex_lock(&(*philo).mutex);
		pthread_mutex_lock(&(*philo).mutex_time_stamp);
		printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		new_timestamp((*philo).time_stamp), (*philo).philo_no);
		pthread_mutex_unlock(&(*philo).mutex_time_stamp);
		pthread_mutex_lock((*philo).mutex_left);
		pthread_mutex_lock(&(*philo).mutex_time_stamp);
		printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		new_timestamp((*philo).time_stamp), (*philo).philo_no);
		pthread_mutex_unlock(&(*philo).mutex_time_stamp);
	}
	else
	{
		pthread_mutex_lock((*philo).mutex_left);
		pthread_mutex_lock(&(*philo).mutex_time_stamp);
		printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		new_timestamp((*philo).time_stamp), (*philo).philo_no);
		pthread_mutex_unlock(&(*philo).mutex_time_stamp);
		pthread_mutex_lock(&(*philo).mutex);
		pthread_mutex_lock(&(*philo).mutex_time_stamp);
		printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		new_timestamp((*philo).time_stamp), (*philo).philo_no);
		pthread_mutex_unlock(&(*philo).mutex_time_stamp);
	}
}

void	eat(t_philo *philo)
{
	int		state_bis;

	pthread_mutex_lock(&(*philo).mutex_state);
	state_bis = (*philo).state;
	pthread_mutex_unlock(&(*philo).mutex_state);
	lock_fork(philo);
	if (state_bis != DEAD && state_bis != STOP)
		print_state(philo, (*philo).philo_no, 0);
	pthread_mutex_lock(&(*philo).mutex_last_eat);
	(*philo).last_eat = get_timestamp();
	pthread_mutex_unlock(&(*philo).mutex_last_eat);
	while (1)
	{
		pthread_mutex_lock(&(*philo).mutex_state);
		state_bis = (*philo).state;
		pthread_mutex_unlock(&(*philo).mutex_state);
		if (state_bis == STOP || state_bis == DEAD
			|| new_timestamp((*philo).last_eat) >= (*philo).time_to_eat)
		{
			break;
		}
		usleep(200);
	}
	pthread_mutex_unlock(&(*philo).mutex);
	pthread_mutex_unlock((*philo).mutex_left);
	(*philo).eat_nb += 1;
}
