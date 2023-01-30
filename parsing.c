/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:00:52 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/23 14:29:17 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	arg_size(char *av)
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	while (av[i])
	{
		nb = (nb * 10) + av[i] - '0';
		i++;
	}
	return (nb);
}

static int	lenght(char **av)
{
	int	l;

	l = 1;
	while (av[l])
	{
		if (ft_strlen(av[l]) > 10)
		{
			printf("Put less than 2,000,000,000.\n");
			return (ERROR);
		}
		l++;
	}
	l = 1;
	while (av[l])
	{
		if (arg_size(av[l]) >= 2000000000 || arg_size(av[l]) <= 0)
		{
			printf("Put more than 0 and less than 2,000,000,000.\n");
			return (ERROR);
		}
		l++;
	}
	return (0);
}

int	parsing(int ac, char **av)
{
	int	l;
	int	c;

	l = 1;
	c = 0;
	if (ac < 5 || ac > 6)
	{
		printf("Put 4 or 5 arguments.\n");
		return (ERROR);
	}
	while (av[l])
	{
		c = 0;
		while (av[l][c])
		{
			if (av[l][c] < '0' || av[l][c] > '9')
			{
				printf("Put positif numbers only.\n");
				return (ERROR);
			}
			c++;
		}
		l++;
	}
	return (lenght(av));
}