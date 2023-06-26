/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:36:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/26 19:41:59 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	moniter(t_philo *philo, t_vars *vars)
{
	while (chk_philos(philo, vars))
	{
		if (is_all_full(philo->vars))
			return ;
	}
	usleep(100);
	printf("%lld %d is died\n", \
		get_time() - vars->start_time, philo->vars->dead);
}

void	*thread(void *arg)
{
	t_philo	*philo;
	t_vars	*vars;

	philo = (t_philo *)arg;
	vars = philo->vars;
	pthread_mutex_lock(&philo->m_eat_time);
	philo->last_eat_time = vars->start_time;
	pthread_mutex_unlock(&philo->m_eat_time);
	philo->fork[0] = philo->id - 1;
	philo->fork[1] = philo->id % vars->nop;
	if (philo->id % 2 == 1)
		usleep(vars->tte);
	while (!isdead(vars))
	{
		if (take_fork(philo) || eating(philo) || \
			sleeping(philo) || thinking(philo))
		{
			pthread_mutex_unlock(&philo->vars->fork[philo->fork[0]]);
			pthread_mutex_unlock(&philo->vars->fork[philo->fork[1]]);
			break ;
		}
	}
	return (NULL);
}

void	philo_start(t_vars *vars, t_philo *philo)
{
	int	i;

	vars->start_time = get_time();
	i = -1;
	while (++i < vars->nop)
		pthread_create(&philo[i].thread, NULL, thread, (void *)&philo[i]);
	moniter(philo, vars);
}

void	philo_end(t_vars *vars, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < vars->nop)
	{
		pthread_join(philo[i].thread, NULL);
		pthread_mutex_destroy(&vars->fork[i]);
		pthread_mutex_destroy(&philo[i].m_eat_time);
	}
	pthread_mutex_destroy(&vars->m_time);
	pthread_mutex_destroy(&vars->m_dead);
	pthread_mutex_destroy(&vars->m_full);
	free(philo);
	free(vars->fork);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_philo	*philo;

	philo = NULL;
	if (ac < 5 || ac > 6 || philo_init(&vars, &philo, av) || !vars.nop)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	philo_start(&vars, philo);
	philo_end(&vars, philo);
	return (0);
}
