/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:46:29 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/20 10:46:58 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static char	*ft_itoas(int n, char *str, long long int nb, int count)
{
	if (n < 0)
		str[0] = '-';
	str[count] = '\0';
	nb = n;
	if (nb < 0)
		nb = nb * -1;
	count--;
	if (n == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[count] = (nb % 10) + '0';
		nb = nb / 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	long long int	nb;
	int				count;

	count = 0;
	nb = (long long int)n;
	if (n == 0)
		count++;
	if (n < 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	return (ft_itoas(n, str, nb, count));
}
