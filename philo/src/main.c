/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:36:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/22 09:31:11 by hyeonsul         ###   ########.fr       */
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

int	set_philo_fork(t_vars *vars, t_philo *philo)
{
	int	i;
	
	philo = (t_philo *)malloc(sizeof(t_philo) * vars->nop);
	if (!philo)
		return (0);
	vars->fork = (int *)malloc(sizeof(int) * vars->nop);
	if (!vars->fork)
	{
		free(philo);
		return (0);
	}
	memset(philo, 0, sizeof(t_philo) * vars->nop);
	memset(vars->fork, 0, sizeof(int) * vars->nop);
	return (1);
}

void	*philo(void *arg)
{
	t_philo	*philo;
	t_vars	*vars;

	philo = (t_philo *)arg;
	vars = philo->vars;
	// 먹고->자고->생각하고 처리
	if (vars->fork[philo->no - 1] && vars->fork[philo->no % vars->nop])
	{
		
	}
	else
	{
		
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_philo	*philo;
	int		i;

	if (ac < 5 || ac > 6 || set_vars(&vars, av) || !set_philo_fork(&vars, philo))
		return (0);
	pthread_mutex_init(&vars.mutex, NULL);
	i = -1;
	while (++i < vars.nop)
	{
		philo[i].no = i + 1;
		philo[i].vars = &vars;
		pthread_create(&philo[i].thread, NULL, philo, (void *)&philo[i]);
	}
	i = -1;
	while (++i < vars.nop)
		pthread_join(philo[i].thread, NULL);
	pthread_mutex_destroy(&vars.mutex);
	free(philo);
	free(vars.fork);
	return (0);
}
