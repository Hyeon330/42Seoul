/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:36:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/20 19:27:27 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chk_philos(t_philo *philo, t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->nop)
	{
		pthread_mutex_lock(&philo[i].m_eat_time);
		pthread_mutex_lock(&philo->vars->print);
		if (philo[i].last_eat_time && get_time() - philo[i].last_eat_time >= vars->ttd)
		{
			pthread_mutex_unlock(&philo[i].m_eat_time);
			pthread_mutex_unlock(&philo->vars->print);
			pthread_mutex_lock(&vars->m_dead);
			vars->dead = philo[i].id;
			pthread_mutex_unlock(&vars->m_dead);
			break ;
		}
		pthread_mutex_unlock(&philo[i].m_eat_time);
		pthread_mutex_unlock(&philo->vars->print);
	}
	return (vars->dead);
}

void	moniter(t_philo *philo, t_vars *vars)
{
	while (1)
	{
		if (chk_philos(philo, vars))
			break ;
		if (vars->full_cnt == vars->notpme)
			return ;
	}
	usleep(100);
	printf("%lld %d is died\n", get_time() - vars->start_time, philo->vars->dead);
}

void	*thread(void *arg)
{
	t_philo	*philo;
	t_vars	*vars;

	philo = (t_philo *)arg;
	vars = philo->vars;
	philo->last_eat_time = vars->start_time;
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
		pthread_detach(philo[i].thread);
		pthread_mutex_destroy(&vars->fork[i]);
		pthread_mutex_destroy(&philo[i].m_eat_time);
	}
	pthread_mutex_destroy(&vars->print);
	pthread_mutex_destroy(&vars->m_dead);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_philo	*philo;

	philo = NULL;
	if (ac < 5 || ac > 6 || philo_init(&vars, &philo, av))
	{
		write(2, "Error\n", 15);
		return (0);
	}
	philo_start(&vars, philo);
	philo_end(&vars, philo);
	free(philo);
	free(vars.fork);
	return (0);
}
