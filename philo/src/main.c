/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:36:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/06 19:33:03 by hyeonsul         ###   ########.fr       */
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
	vars->notepme = -1;
	vars->died = 0;
	return (set_num(&vars->nop, av[1]) || set_num(&vars->ttd, av[2]) || \
			set_num(&vars->tte, av[3]) || set_num(&vars->tts, av[4]) || \
			(av[5] && set_num(&vars->notepme, av[5])));
}

int	set_philo_fork(t_vars *vars, t_philo **philo)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * vars->nop);
	if (!*philo)
		return (0);
	vars->fork = (int *)malloc(sizeof(int) * vars->nop);
	if (!vars->fork)
	{
		free(*philo);
		return (0);
	}
	memset(*philo, 0, sizeof(t_philo) * vars->nop);
	i = -1;
	while (++i < vars->nop)
		vars->fork[i] = 1;
	return (1);
}

struct timeval	get_time()
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return (tm);
}

void	eating()
{

}

void	sleeping()
{

}

void	thinking()
{
	
}

void	*thread(void *arg)
{
	t_philo			*philo;
	t_vars			*vars;
	int				fork[2];
	struct timeval	tm;

	philo = (t_philo *)arg;
	vars = philo->vars;
	printf("num: %d, nop: %d, notepme: %d\n", philo->num, vars->nop, vars->notepme);
	// 먹고->자고->생각하고 처리
	fork[0] = philo->num - 1;
	fork[1] = philo->num % vars->nop;
	pthread_mutex_lock(philo->thread);
	if (vars->fork[fork[0]] && vars->fork[fork[1]])
	{
		vars->fork[fork[0]] = !vars->fork[fork[0]];
		vars->fork[fork[1]] = !vars->fork[fork[1]];
		printf("%d %d has taken a fork\n", get_time().tv_usec, philo->num);
		pthread_mutex_unlock(philo->thread);

		printf("%d %d is eating\n", get_time().tv_usec, philo->num);
		usleep(vars->tte);
		
		vars->fork[fork[0]] = !vars->fork[fork[0]];
		vars->fork[fork[1]] = !vars->fork[fork[1]];

		printf("%d %d is sleeping\n", get_time().tv_usec, philo->num);
		usleep(vars->tts);
	}
	pthread_mutex_unlock(philo->thread);
	
	return (NULL);
}

int	philo_init(t_vars *vars, t_philo **philo, char **av)
{
	int	i;

	if (set_vars(vars, av) || !set_philo_fork(vars, *philo))
		return (1);
	pthread_mutex_init(&vars->mutex, NULL);
	i = -1;
	while (++i < vars->nop)
	{
		(*philo)[i].num = i + 1;
		(*philo)[i].vars = vars;
	}
	return (0);
}

void	philo_start(t_vars *vars, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < vars->nop)
		pthread_create(&philo[i].thread, NULL, thread, (void *)&philo[i]);
}

void	philo_end(t_vars *vars, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < vars->nop)
		pthread_join(philo[i].thread, NULL);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_philo	*philo;
	int		i;

	philo = NULL;
	if (ac < 5 || ac > 6 || philo_init(&vars, &philo, av))
		return (0);
	philo_start(&vars, philo);
	philo_end(&vars, philo);
	pthread_mutex_destroy(&vars.mutex);
	free(philo);
	free(vars.fork);
	return (0);
}
