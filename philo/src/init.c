/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:35:21 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/20 15:52:17 by hyeonsul         ###   ########.fr       */
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
	vars->notpme = -1;
	vars->full_cnt = 0;
	vars->dead = 0;
	if (pthread_mutex_init(&vars->print, NULL) || \
		pthread_mutex_init(&vars->m_dead, NULL))
		return (1);
	return (set_num(&vars->nop, av[1]) || set_num(&vars->ttd, av[2]) || \
			set_num(&vars->tte, av[3]) || set_num(&vars->tts, av[4]) || \
			(av[5] && set_num(&vars->notpme, av[5])));
}

int	set_philo_fork(t_vars *vars, t_philo **philo)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * vars->nop);
	if (!*philo)
		return (0);
	vars->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * vars->nop);
	if (!vars->fork)
	{
		free(*philo);
		return (0);
	}
	memset(*philo, 0, sizeof(t_philo) * vars->nop);
	return (1);
}

int	philo_init(t_vars *vars, t_philo **philo, char **av)
{
	int	i;

	if (set_vars(vars, av) || !set_philo_fork(vars, philo))
		return (1);
	i = -1;
	while (++i < vars->nop)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].vars = vars;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].last_eat_time = 0;
		if (pthread_mutex_init(&vars->fork[i], NULL) || \
			pthread_mutex_init(&(*philo)[i].m_eat_time, NULL))
			return (1);
	}
	return (0);
}
