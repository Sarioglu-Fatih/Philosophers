/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:35 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/22 17:35:30 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	// int					t1;
	// int					t2;
	// struct timeval		tv;

	// t1 = gettimeofday(&tv, NULL);
	// printf("%d,  %ld,  %d\n", t1, tv.tv_sec, tv.tv_usec);
	// ft_putnbr_fd(tv.tv_usec, 1);
	// ft_putchar_fd('\n', 1);
	// t2 = gettimeofday(&tv, NULL);
	// printf("%d,  %ld,  %d\n", t2, tv.tv_sec, tv.tv_usec);
	// ft_putnbr_fd(tv.tv_usec, 1);
	// ft_putchar_fd('\n', 1);

// void	*routine(void *arg)
// {
// 	t_philo *philo;

// 	philo = (t_philo *)arg;
// 	pthread_mutex_lock(&philo->mutex);
// 	pthread_mutex_lock(philo->mutex_left);
// 	int	i = 0;
// 	while (i < 3)
// 	{
// 		printf("hello, i=%d -- %d\n", i, getpid());
// 		sleep(1);
// 		i++;
// 	}
// 	pthread_mutex_unlock(&philo->mutex);
// 	pthread_mutex_unlock(philo->mutex_left);
// 	return ("asd");
// }

// void	test(void)
// {
// 	t_philo		philo[2];

// 	pthread_mutex_init(&philo[1].mutex, NULL);
// 	pthread_mutex_init(&philo[0].mutex, NULL);
// 	philo[0].mutex_left = &philo[1].mutex;
// 	philo[1].mutex_left = &philo[0].mutex;
// 	pthread_create(&philo[0].thread, NULL, &routine, &philo[0]);
// 	pthread_create(&philo[1].thread, NULL, &routine, &philo[1]);
// 	printf("bonjour\n");
// 	pthread_join(philo[1].thread, NULL);
// 	printf("bonsoir\n");
// 	pthread_join(philo[0].thread, NULL);
// 	printf("allo\n");
// }

int	main(int ac, char **av)
{
	if (parsing(ac, av) == ERROR)
		return (-1);
	if (exec(ac, av) == ERROR)
		return (-1);
//	test();
	return (0);
}
