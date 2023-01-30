/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:07:45 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/30 17:00:38 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_is_dead(t_philo *philo)
{
	static int	is_print = 0;

	(*philo).dead = TRUE;
	if (is_print == 0)
	{	
		is_print = 1;
	}
}