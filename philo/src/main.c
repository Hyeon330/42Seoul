/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:36:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/09 21:29:44 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_stat(t_philo *philo, int ms, int stat)
{
	printf("%dms %d ", ms, philo->id);
	if (stat == FORK)
		printf("has taken a fork\n");
	if (stat == EAT)
		printf("is eating\n");
	if (stat == SLEEP)
		printf("is sleeping\n");
	if (stat == THINK)
		printf("is thinking\n");
	if (stat == DIE)
		printf("died\n");
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
	vars->notpme = -1;
	vars->died = 0;
	if (pthread_mutex_init(&vars->print, NULL))
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

long long	get_time()
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

int	eat_check(t_philo *philo)
{
	if (philo->eat_cnt == philo->vars->notpme)
		philo->vars->full_cnt++;
	if (philo->vars->full_cnt >= philo->vars->nop)
		return (1);
	return (0);
}

int	ft_usleep(t_philo *philo, long long start, int stat)
{
	long long	time;

	while (1)
	{
		time = get_time();
		if (!philo->vars->died && (time - philo->last_eat_time >= philo->vars->ttd))
		{
			print_stat(philo, time - philo->vars->start_time, DIE);
			philo->vars->died = 1;
		}
		if (philo->vars->died)
			return (1);
		if (stat == EAT && time - start >= philo->vars->tte)
			return (0);
		if (stat == SLEEP && time - start >= philo->vars->tts)
			return (0);
	}
}

void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->vars->fork[philo->fork[0]]);
		pthread_mutex_lock(&philo->vars->fork[philo->fork[1]]);
	}
	else
	{
		pthread_mutex_lock(&philo->vars->fork[philo->fork[1]]);
		pthread_mutex_lock(&philo->vars->fork[philo->fork[0]]);
	}

	pthread_mutex_lock(&philo->vars->print);
	print_stat(philo, get_time() - philo->vars->start_time, FORK);
	pthread_mutex_unlock(&philo->vars->print);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->print);
	print_stat(philo, get_time() - philo->vars->start_time, EAT);
	pthread_mutex_unlock(&philo->vars->print);

	philo->eat_cnt++;
	philo->last_eat_time = get_time();
	if (!ft_usleep(philo, get_time(), EAT))
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->vars->fork[philo->fork[0]]);
		pthread_mutex_unlock(&philo->vars->fork[philo->fork[1]]);
	}
	else
	{
		pthread_mutex_unlock(&philo->vars->fork[philo->fork[1]]);
		pthread_mutex_unlock(&philo->vars->fork[philo->fork[0]]);
	}
	return (eat_check(philo));
}

int	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->print);
	print_stat(philo, get_time() - philo->vars->start_time, SLEEP);
	pthread_mutex_unlock(&philo->vars->print);
	return (ft_usleep(philo, get_time(), SLEEP));
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->print);
	print_stat(philo, get_time() - philo->vars->start_time, THINK);
	pthread_mutex_unlock(&philo->vars->print);
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
	while (!vars->died)
	{
		take_fork(philo);
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
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
	pthread_mutex_destroy(&vars->print);
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
