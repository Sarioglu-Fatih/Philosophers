/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:12:47 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/16 18:06:55 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	print_state_next(t_philo *philo, int ph_no, int state)
{
	if (state == 1)
	{
		pthread_mutex_lock(&(*philo).mutex_time_stamp);
		printf("%8ld ms  -  Philo No %4d  is sleeping\n",
			new_timestamp((*philo).time_stamp), ph_no);
		pthread_mutex_unlock(&(*philo).mutex_time_stamp);
	}
	else if (state == 2)
	{
		pthread_mutex_lock(&(*philo).mutex_time_stamp);
		printf("%8ld ms  -  Philo No %4d  is thinking\n",
			new_timestamp((*philo).time_stamp), ph_no);
		pthread_mutex_unlock(&(*philo).mutex_time_stamp);
	}
}

void	print_state(t_philo *philo, int philo_no, int state)
{
	if (state == -1)
	{
		usleep(4000);
		pthread_mutex_lock(&(*philo).mutex_time_stamp);
		printf("%8ld ms  -  Philo No %4d  diedddddddd\n\n\n",
			new_timestamp((*philo).time_stamp), philo_no);
		pthread_mutex_unlock(&(*philo).mutex_time_stamp);
	}
	if (state == 0)
	{
		pthread_mutex_lock(&(*philo).mutex_time_stamp);
		printf("%8ld ms  -  Philo No %4d  is eating\n",
			new_timestamp((*philo).time_stamp), philo_no + 1);
		pthread_mutex_unlock(&(*philo).mutex_time_stamp);
	}
	else
		print_state_next(philo, philo_no, state);
}
