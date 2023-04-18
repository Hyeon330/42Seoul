/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:36:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/18 09:54:25 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_num(int *var, char *agmt)
{
	*var = 0;
	if (*agmt == '-')
		return (1);
	if (*agmt == '+')
		agmt++;
	while (*agmt >= '0' && *agmt <= '9')
		*var = *var * 10 + (*agmt++ - '0');
	return (*agmt);
}

int	set_vars(t_vars *vars, char **av)
{
	vars->notepme = 0;
	return (set_num(&vars->nop, av[1]) || set_num(&vars->ttd, av[2]) || \
			set_num(&vars->tte, av[3]) || set_num(&vars->tts, av[4]) || \
			(av[5] && set_num(&vars->notepme, av[5])));
}

int	set_philo_fork(t_vars *vars)
{
	int	i;
	
	vars->philo = (pthread_t *)malloc(sizeof(pthread_t) * vars->nop);
	if (!vars->philo)
		return (0);
	vars->fork = (int *)malloc(sizeof(int) * vars->nop);
	if (!vars->fork)
	{
		i = -1;
		while (++i < vars->nop)
			free(vars->philo[i]);
		return (0);
	}
	memset(vars->philo, 0, sizeof(pthread_t) * vars->nop);
	memset(vars->fork, 0, sizeof(int) * vars->nop);
	return (1);
}

void	*philo(void *arg)
{
	t_vars	*vars;

	vars = (t_vars *)arg;
	printf("tid: %x, nop: %d, tts: %d\n", (unsigned int)pthread_self(), vars->nop, vars->tts);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_vars			vars;
	int				i;

	if (ac < 5 || ac > 6 || set_vars(&vars, av) || !set_philo_fork(&vars))
		return (0);
	pthread_mutex_init(&vars.mutex, NULL);
	i = -1;
	while (++i < vars.nop)
		pthread_create(&vars.philo[i], NULL, philo, (void *)&vars);
	i = -1;
	while (++i < vars.nop)
		pthread_join(vars.philo[i], NULL);
	pthread_mutex_destroy(&vars.mutex);
	printf("%d\n", vars.notepme);
}