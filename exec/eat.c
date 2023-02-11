/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:49 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/09 18:59:07 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(*philo).mutex);
	pthread_mutex_lock((*philo).mutex_left);
	pthread_mutex_lock(&(*philo).mutex_state);
	if ((*philo).state != DEAD && (*philo).state != STOP)
		print_state(philo, new_timestamp((*philo).time_stamp), (*philo).philo_no, 0);
	pthread_mutex_unlock(&(*philo).mutex_state);
	(*philo).last_eat = get_timestamp();
	while (get_timestamp() - (*philo).last_eat <= (*philo).time_to_eat)
	{
		if (get_timestamp() - (*philo).last_eat >= (*philo).time_to_die)
		{
			print_state(philo, new_timestamp((*philo).time_stamp), (*philo).philo_no, -1);
			pthread_mutex_lock(&(*philo).mutex_state);
			(*philo).state = DEAD;
			pthread_mutex_unlock(&(*philo).mutex_state);
		}
		pthread_mutex_lock(&(*philo).mutex_state);
		if ((*philo).state == DEAD || (*philo).state == STOP)
		{
			pthread_mutex_unlock(&(*philo).mutex_state);
			break;
		}
		pthread_mutex_unlock(&(*philo).mutex_state);
		usleep(200);
	}
	pthread_mutex_unlock((*philo).mutex_left);
	pthread_mutex_unlock(&(*philo).mutex);
	(*philo).eat_nb += 1;
}