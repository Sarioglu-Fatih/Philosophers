/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:23:53 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/11 19:36:20 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleep_time(t_philo *philo)
{
	usleep((*philo).philo_no);
	pthread_mutex_lock(&(*philo).mutex_state);
	if ((*philo).state != DEAD && (*philo).state != STOP)
		print_state(philo, (*philo).philo_no, 1);
	if ((*philo).eat_nb >= (*philo).minimum_eat && (*philo).minimum_eat != -1
			&& (*philo).state != DEAD)
		(*philo).state = FINISH_EAT;
	pthread_mutex_unlock(&(*philo).mutex_state);
	(*philo).start_sleep = get_timestamp();
	while (1)
	{
		pthread_mutex_lock(&(*philo).mutex_last_eat);
		if (new_timestamp((*philo).start_sleep) >= (*philo).time_to_sleep
			|| (*philo).state == STOP || (*philo).state == DEAD)
		{
			pthread_mutex_unlock(&(*philo).mutex_last_eat);
			break;
		}
		pthread_mutex_unlock(&(*philo).mutex_last_eat);
		usleep(500);
	}
}
