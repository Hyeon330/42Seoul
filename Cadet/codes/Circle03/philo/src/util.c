/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:33:48 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/27 17:27:13 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

long long	print_stat(t_philo *philo, int stat)
{
	long long	time;

	if (isdead(philo->vars))
		return (0);
	usleep(2);
	pthread_mutex_lock(&philo->vars->m_time);
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
	pthread_mutex_unlock(&philo->vars->m_time);
	return (time);
}

void	ft_usleep(t_philo *philo, long long start, int stat)
{
	long long	time;

	if (!start)
		return ;
	while (!isdead(philo->vars))
	{
		time = get_time();
		if ((stat == EAT && time - start >= philo->vars->tte) || \
			(stat == SLEEP && time - start >= philo->vars->tts))
			return ;
		usleep(100);
	}
}

int	mutex_all_unlock(t_vars *vars)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (++i < vars->nop)
		ret = ret || pthread_mutex_unlock(&vars->fork[i]);
	return (ret);
}
