/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:18:29 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/25 18:18:44 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	new_timestamp(long time_stamp)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time - time_stamp);
}
