/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:49 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/13 20:54:49 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	int		state_bis;

	pthread_mutex_lock(&(*philo).mutex_state);
	state_bis = (*philo).state;
	pthread_mutex_unlock(&(*philo).mutex_state);
	pthread_mutex_lock(&(*philo).mutex);
	pthread_mutex_lock((*philo).mutex_left);
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
		if (state_bis == STOP || state_bis == DEAD)
		{
			break;
		}
		usleep(500);
	}
	pthread_mutex_unlock(&(*philo).mutex);
	pthread_mutex_unlock((*philo).mutex_left);
	(*philo).eat_nb += 1;
}
