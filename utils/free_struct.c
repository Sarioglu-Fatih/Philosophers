/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:53:15 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/07 16:28:30 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	free_struct(t_philo **philo, int snb, int ret)
{
	int		i;

	i = 0;
	while (i < snb)
	{
		if (philo[i])
			free(philo[i]);
		i++;
	}
	return (ret);
}