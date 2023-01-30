/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:07:45 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/27 15:45:17 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_is_dead(t_philo *philo)
{
	static int	is_print = 0;

	if (is_print == 0)
	{	
		is_print = 1;
		printf("%8ld ms  -  Philo No %4d  died\n\n\n", new_timestamp((*philo).time_stamp), (*philo).philo_no);
	}
	(*philo).dead = TRUE;
}