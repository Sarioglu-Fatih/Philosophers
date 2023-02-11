/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_dead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:39:49 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/09 18:27:44 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	get_stop(t_philo **philo, int state, int snb)
{
	int	i;

	i = 0;
	while (i < snb)
	{
		pthread_mutex_lock(&(*philo)[i].mutex_state);
		(*philo)[i].state = state;
		pthread_mutex_unlock(&(*philo)[i].mutex_state);
		i++;
	}
	return (-1);
}

int	check(t_philo **philo, int snb)
{
	int	i;
	int	eated;

	i = 0;
	while (1)
	{
		i = 0;
		eated = TRUE;
		while (i < snb)
		{
			pthread_mutex_lock(&(*philo)[i].mutex_state);
			if ((*philo)[i].state == DEAD)
			{
				pthread_mutex_unlock(&(*philo)[i].mutex_state);
				return (get_stop(philo, DEAD, snb));
			}
			if ((*philo)[i].state != 3)
				eated = FALSE;
			pthread_mutex_unlock(&(*philo)[i].mutex_state);
			i++;
		}
		if (eated == TRUE)
			return (get_stop(philo, STOP, snb));
	}
	return (0);
}
