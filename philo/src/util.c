/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:33:48 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/19 23:05:13 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdead(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_stat);
	if (philo->stat == DIE)
	{
		pthread_mutex_unlock(&philo->m_stat);
		return (1);
	}
	pthread_mutex_unlock(&philo->m_stat);
	return (0);
}

long long	get_time()
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

long long	print_stat(t_philo *philo, int stat)
{
	long long	time;

	pthread_mutex_lock(&philo->vars->print);
	time = get_time();
	printf("%lld %d ", time - philo->vars->start_time, philo->id);
	if (stat == FORK)
		printf("has taken a fork\n");
	if (stat == EAT)
		printf("is eating\n");
	if (stat == SLEEP)
		printf("is sleeping\n");
	if (stat == THINK)
		printf("is thinking\n");
	pthread_mutex_unlock(&philo->vars->print);
	return (time);
}

int	iseat(t_philo *philo)
{
	if (philo->eat_cnt == philo->vars->notpme)
	{
		philo->vars->full_cnt++;
		return (1);
	}
	return (0);
}

void	ft_usleep(t_philo *philo, long long start, int stat)
{
	long long	time;

	while (!isdead(philo))
	{
		time = get_time();
		if ((stat == EAT && time - start >= philo->vars->tte) || \
			(stat == SLEEP && time - start >= philo->vars->tts))
			return ;
		usleep(100);
	}
}
