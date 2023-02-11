/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:49 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/11 19:36:23 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(*philo).mutex);
	pthread_mutex_lock((*philo).mutex_left);
	pthread_mutex_lock(&(*philo).mutex_state);
	if ((*philo).state != DEAD && (*philo).state != STOP)
		print_state(philo, (*philo).philo_no, 0);
	pthread_mutex_unlock(&(*philo).mutex_state);
	pthread_mutex_lock(&(*philo).mutex_last_eat);
	(*philo).last_eat = get_timestamp();
	pthread_mutex_unlock(&(*philo).mutex_last_eat);
	while (1)
	{
		pthread_mutex_lock(&(*philo).mutex_last_eat);
		if (new_timestamp((*philo).last_eat) >= (*philo).time_to_eat
			|| (*philo).state == STOP || (*philo).state == DEAD)
		{
			pthread_mutex_unlock(&(*philo).mutex_last_eat);
			break;
		}
		pthread_mutex_unlock(&(*philo).mutex_last_eat);
		usleep(500);
	}
	pthread_mutex_unlock((*philo).mutex_left);
	pthread_mutex_unlock(&(*philo).mutex);
	(*philo).eat_nb += 1;
}