/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:12:58 by fsariogl          #+#    #+#             */
/*   Updated: 2023/01/22 18:33:52 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(*philo).mutex);
	pthread_mutex_lock((*philo).mutex_left);
	printf("eat - %d, %d\n", (*philo).philo_no, (*philo).eat_nb);
	usleep((*philo).time_to_eat * 1000);
	pthread_mutex_unlock(&(*philo).mutex);
	pthread_mutex_unlock((*philo).mutex_left);
	(*philo).eat_nb += 1;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (((*philo).dead == FALSE || (*philo).eated == FALSE) && (*philo).eat_nb <= (*philo).minimum_eat)
	{
		printf("bonjour\n");
		eat(philo);
		// sleep;
		// think;
	}
	return ("bon");
}

// int	exit_routine(pthread_t th)
// {
// 	// while (thread[i])
// 	// {
// 	// 	pthread_mutex_destroy();
// 	// 	pthread_join();
// 	// }
// 	pthread_join(th, NULL);
// 	return (0);
// }

int	exec(int ac, char **av)
{
	int		i;
	t_philo	*philo;

	i = 0;
	if (init(&philo, ac, av) == ERROR)
		return (free_struct(&philo, ft_atoi(av[1]), ERROR));
	while (i < philo[0].max_philo)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo[0].max_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	// pthread_mutex_t fork;
	// pthread_mutex_t fork_left;
	// pthread_mutex_t	*forks;
	// pthread_t	thread;
	// t_philo		philo;
	// t_philo		*philos;

	// while (i < max_philo)
	// {
	// 	pthread_mutex_init(&forks[i], NULL);
	// }
	// while (i < max_philo)
	// {
	// 	philos[i].mutex = forks[i];
	// 	philos[i].mutex_left = forks[i + 1];
	// }
	// pthread_create(&thread, NULL, &routine, NULL);
	// pthread_mutex_init(&fork_left, NULL);
	// pthread_mutex_lock(&fork);
	// pthread_mutex_unlock(&fork);
	//pthread_detach(thread);
	//exit_routine(thread);
	// pthread_join(thread, NULL);
	// printf("bah\n");
	// sleep(1);
	// sleep(6);
	// while (1)
	// {
	// 	if (is_philo_dead == 1 || everyone_eat_enough == 1)
	// 	{
	// 		exit_routine();
	// 	}
	// }
	return (0);
}




// int main(void)
// {
//     int        ar[1000000];
//     pthread_t  th1, th2;
//     subarray   sb1, sb2;


//     sb1.ar = &ar[0];
//     sb1.n  = 500000;
//     (void) pthread_create(&th1, NULL, routine, &sb1);


//     sb2.ar = &ar[500000];
//     sb2.n  = 500000;
//     (void) pthread_create(&th2, NULL, routine, &sb2);


//     (void) pthread_join(th1, NULL);
//     (void) pthread_join(th2, NULL);
//     return 0;
// }