/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:36:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/08 17:58:30 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_stat(int ms, int id, int stat)
{
	printf("%dms %d ", ms, id);
	if (stat == FORK)
		printf("has taken a fork\n");
	if (stat == EAT)
		printf("is eating\n");
	if (stat == SLEEP)
		printf("is sleeping\n");
	if (stat == THINK)
		printf("is thinking\n");
	if (stat == DIE)
		printf("died");
}

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
	vars->fork = (int *)malloc(sizeof(pthread_mutex_t) * vars->nop);
	if (!vars->fork)
	{
		free(*philo);
		return (0);
	}
	memset(*philo, 0, sizeof(t_philo) * vars->nop);
	return (1);
}

long long	get_time()
{
	struct timeval	tm;
	long long		time_stamp;

	gettimeofday(&tm, NULL);
	return (tm.tv_sec * 1000000 + tm.tv_usec);
}

void	take_fork(t_vars *vars, int *fork, int id)
{
	pthread_mutex_lock(&vars->fork[fork[0]]);
	pthread_mutex_lock(&vars->fork[fork[1]]);
	print_stat(get_time() - vars->start_time, id, FORK);
}

void	eating(t_vars *vars, int *fork, int id)
{
	print_stat(get_time() - vars->start_time, id, EAT);
	usleep(vars->tte);
	pthread_mutex_unlock(&vars->fork[fork[0]]);
	pthread_mutex_unlock(&vars->fork[fork[1]]);
}

void	sleeping(t_vars *vars, int *fork, int id)
{
	print_stat(get_time() - vars->start_time, id, SLEEP);
	usleep(vars->tts);
}

void	thinking(t_vars *vars, int *fork, int id)
{
	print_stat(get_time() - vars->start_time, id, THINK);
}

void	*thread(void *arg)
{
	t_philo			*philo;
	t_vars			*vars;
	int				fork[2];
	long long		prev_tm;

	philo = (t_philo *)arg;
	vars = philo->vars;
	// printf("num: %d, nop: %d, notepme: %d\n", philo->id, vars->nop, vars->notepme);
	// 먹고->자고->생각하고 처리
	if (!(philo->id % 2))
	{
		thinking(vars, fork, philo->id);
		usleep(vars->tte);
	}
	fork[0] = philo->id - 1;
	fork[1] = philo->id % vars->nop;
	while (!vars->died)
	{
		take_fork(vars, fork, philo->id);
		eating(vars, fork, philo->id);
		sleeping(vars, fork, philo->id);
		thinking(vars, fork, philo->id);
	}
	return (NULL);
}

void	*dying_moniter(void *arg)
{
	
}

int	philo_init(t_vars *vars, t_philo **philo, char **av)
{
	int	i;

	if (set_vars(vars, av) || !set_philo_fork(vars, *philo))
		return (1);
	i = -1;
	while (++i < vars->nop)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].vars = vars;
		if (pthread_mutex_init(&vars->fork[i], NULL))
			return (1);
	}
	return (0);
}

void	philo_start(t_vars *vars, t_philo *philo)
{
	int	i;

	vars->start_time = get_time();
	i = -1;
	while (++i < vars->nop)
		pthread_create(&philo[i].thread, NULL, thread, (void *)&philo[i]);
}

void	philo_end(t_vars *vars, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < vars->nop)
	{
		pthread_join(philo[i].thread, NULL);
		pthread_mutex_destroy(&vars->fork[i]);
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_philo	*philo;
	int		i;

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
