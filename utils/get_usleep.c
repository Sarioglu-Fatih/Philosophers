/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_usleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:00:19 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/06 15:01:25 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_usleep(long time)
{
	struct timeval	tv;
	long			fixe_time;
	long			mobile_time;

	gettimeofday(&tv, NULL);
	fixe_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	mobile_time = fixe_time;
	while (mobile_time - fixe_time < time)
	{
		gettimeofday(&tv, NULL);
		mobile_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		usleep(300);
	}
}
