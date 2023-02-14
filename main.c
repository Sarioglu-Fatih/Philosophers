/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:35 by fsariogl          #+#    #+#             */
/*   Updated: 2023/02/14 15:35:19 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (parsing(ac, av) == ERROR)
		return (-1);
	if (exec(ac, av) == ERROR)
		return (-1);
	return (0);
}
