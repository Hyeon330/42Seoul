/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:36:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/19 23:06:49 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	dying_moniter(t_vars *vars)
// {
// 	pthread_mutex_lock(&vars->died_st);
// 	while (!vars->died && vars->full_cnt != vars->nop)
// 	{
// 		pthread_mutex_unlock(&vars->died_st);
// 		usleep(100);
// 		pthread_mutex_lock(&vars->died_st);
// 	}
// 	pthread_mutex_unlock(&vars->died_st);
// 	if (vars->died)
// 		printf("%lld %d is died\n", get_time() - vars->start_time, vars->died);
// }

int	chk_philos(t_philo *philo, t_vars *vars, long long time)
{
	int	i;

	i = -1;
	while (++i < vars->nop)
	{
		if (time - philo[i].last_eat_time >= vars->ttd)
		{
			pthread_mutex_lock(&philo[i].m_stat);
			philo[i].stat = DIE;
			pthread_mutex_unlock(&philo[i].m_stat);
			return (philo[i].id);
		}
	}
	return (0);
}

void	moniter(t_philo *philo, t_vars *vars)
{
	int	dead_id;

	dead_id = 0;
	while (1)
	{
		dead_id = chk_philos(philo, vars, get_time());
		if (dead_id)
			break ;
		if (vars->full_cnt == vars->notpme)
			return ;
		usleep(100);
	}
	usleep(100);
	printf("%lld %d is died\n", get_time() - vars->start_time, dead_id);
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
		ft_usleep(philo, get_time(), EAT);

	while (!philo->stat)
	{
		if (take_fork(philo) || eating(philo) || \
			sleeping(philo) || thinking(philo))
			break ;
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
	}
	pthread_mutex_destroy(&vars->print);
	// pthread_mutex_destroy(&vars->died_st);
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
