/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:12:47 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/11 19:26:25 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void print_state_next(t_philo *philo, int ph_no, int state)
{
    if (state == 1)
	{
		printf("%8ld ms  -  Philo No %4d  is sleeping\n",
		new_timestamp((*philo).time_stamp), ph_no);
	}
	else if (state == 2)
	{
		printf("%8ld ms  -  Philo No %4d  is thinking\n",
		new_timestamp((*philo).time_stamp), ph_no);
	}
}

void	print_state(t_philo *philo, int philo_no, int state)
{

	if (state == -1)
	{
		pthread_mutex_lock(&(*philo).mutex_state);
		if ((*philo).state == DEAD)
		{
			pthread_mutex_unlock(&(*philo).mutex_state);
			usleep(4000);
			printf("%8ld ms  -  Philo No %4d  diedddddddd\n\n\n",
			new_timestamp((*philo).time_stamp), philo_no);
		}
		else
			pthread_mutex_unlock(&(*philo).mutex_state);
	}
	if (state == 0 )
	{
		printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		new_timestamp((*philo).time_stamp), philo_no);
		printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		new_timestamp((*philo).time_stamp), philo_no);
		printf("%8ld ms  -  Philo No %4d  is eating\n",
		new_timestamp((*philo).time_stamp), philo_no);
	}
	else
        print_state_next(philo, philo_no, state);
	// pthread_mutex_unlock((*philo).mutex_write);
}