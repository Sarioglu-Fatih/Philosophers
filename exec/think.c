/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:27:59 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/11 19:26:04 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	think(t_philo *philo)
{
	pthread_mutex_lock(&(*philo).mutex_state);
	if ((*philo).state != DEAD && (*philo).state != STOP)
		print_state(philo, (*philo).philo_no, 2);
	pthread_mutex_unlock(&(*philo).mutex_state);
	usleep(500);
}
