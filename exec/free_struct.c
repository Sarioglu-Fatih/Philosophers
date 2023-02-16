/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:19:41 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/16 14:03:34 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_struct(t_philo **philo, int snb)
{
	int	i;

	i = 0;
	while (i < snb)
	{
		pthread_mutex_destroy(&(*philo)[i].mutex);
		pthread_mutex_destroy(&(*philo)[i].mutex_state);
		pthread_mutex_destroy(&(*philo)[i].mutex_last_eat);
		pthread_mutex_destroy(&(*philo)[i].mutex_time_stamp);
		i++;
	}
	free(*philo);
	(*philo) = NULL;
}
