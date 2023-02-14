/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:23:53 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/14 17:10:26 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleep_time(t_philo *philo)
{
	int	state_bis;

	pthread_mutex_lock(&(*philo).mutex_state);
	state_bis = (*philo).state;
	pthread_mutex_unlock(&(*philo).mutex_state);
	usleep((*philo).philo_no);
	if (state_bis != DEAD && state_bis != STOP)
		print_state(philo, (*philo).philo_no, 1);
	if ((*philo).eat_nb >= (*philo).minimum_eat && (*philo).minimum_eat != -1
			&& state_bis != DEAD)
	{
		pthread_mutex_lock(&(*philo).mutex_state);
		(*philo).state = FINISH_EAT;
		pthread_mutex_unlock(&(*philo).mutex_state);
	}
	(*philo).start_sleep = get_timestamp();
	while (1)
	{
		pthread_mutex_lock(&(*philo).mutex_state);
		state_bis = (*philo).state;
		pthread_mutex_unlock(&(*philo).mutex_state);
		if (new_timestamp((*philo).start_sleep) >= (*philo).time_to_sleep
			|| state_bis == STOP || state_bis == DEAD)
		{
			break;
		}
		usleep(200);
	}
}
