/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:27:28 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/25 18:22:58 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_timestamp(t_philo **philo)
{
	struct timeval	tv;
	int				i;
	long			time;

	i = 0;
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	while (i < (*philo)[0].max_philo)
	{
		(*philo)[i].time_stamp = time;
		(*philo)[i].last_eat = time;
		i++;
	}
}