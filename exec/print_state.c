/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:12:47 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/10 17:58:04 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void print_state_next(long time_s, int ph_no, int state)
{
    if (state == 1)
	{
		printf("%8ld ms  -  Philo No %4d  is sleeping\n",
		time_s, ph_no);
	}
	else if (state == 2)
	{
		printf("%8ld ms  -  Philo No %4d  is thinking\n",
		time_s, ph_no);
	}
}

void	print_state(t_philo *philo, long time_stamp, int philo_no, int state)
{

	if (state == -1)
	{
		pthread_mutex_lock((*philo).mutex_write);
		pthread_mutex_lock(&(*philo).mutex_state);
		if ((*philo).state != DEAD)
		{
			(*philo).state = DEAD;
			usleep(200000);
			printf("%8ld ms  -  Philo No %4d  diedddddddd\n\n\n",
			time_stamp, philo_no);
		}
		pthread_mutex_unlock(&(*philo).mutex_state);
	}
	if (state == 0 )
	{
		printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		time_stamp, philo_no);
		printf("%8ld ms  -  Philo No %4d  has taken a fork\n",
		time_stamp, philo_no);
		printf("%8ld ms  -  Philo No %4d  is eating\n",
		time_stamp, philo_no);
	}
	else
        print_state_next(time_stamp, philo_no, state);
	// pthread_mutex_unlock((*philo).mutex_write);
}