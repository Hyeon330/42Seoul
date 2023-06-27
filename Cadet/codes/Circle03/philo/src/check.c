/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:23:39 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/27 16:48:12 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdead(t_vars *vars)
{
	int	ret;

	pthread_mutex_lock(&vars->m_dead);
	ret = vars->dead;
	pthread_mutex_unlock(&vars->m_dead);
	return (ret);
}

int	isfull(t_philo *philo)
{
	if (philo->eat_cnt == philo->vars->notpme)
	{
		pthread_mutex_lock(&philo->vars->m_full);
		philo->vars->full_cnt++;
		pthread_mutex_unlock(&philo->vars->m_full);
		return (1);
	}
	return (0);
}

int	is_all_full(t_vars *vars)
{
	int	ret;

	pthread_mutex_lock(&vars->m_full);
	ret = vars->full_cnt == vars->nop;
	pthread_mutex_unlock(&vars->m_full);
	return (ret);
}

int	chk_philos(t_philo *philo, t_vars *vars)
{
	int	i;

	usleep(100);
	i = -1;
	while (++i < vars->nop)
	{
		pthread_mutex_lock(&philo[i].m_eat_time);
		pthread_mutex_lock(&philo->vars->m_time);
		if (philo[i].last_eat_time && \
			get_time() - philo[i].last_eat_time > vars->ttd)
		{
			pthread_mutex_unlock(&philo->vars->m_time);
			pthread_mutex_unlock(&philo[i].m_eat_time);
			pthread_mutex_lock(&vars->m_dead);
			vars->dead = philo[i].id;
			pthread_mutex_unlock(&vars->m_dead);
			return (0);
		}
		pthread_mutex_unlock(&philo->vars->m_time);
		pthread_mutex_unlock(&philo[i].m_eat_time);
	}
	return (1);
}
