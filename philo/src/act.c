/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:30:24 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/20 19:09:00 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->vars->fork[philo->fork[0]]);
		print_stat(philo, FORK);
		pthread_mutex_lock(&philo->vars->fork[philo->fork[1]]);
		print_stat(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->vars->fork[philo->fork[1]]);
		print_stat(philo, FORK);
		pthread_mutex_lock(&philo->vars->fork[philo->fork[0]]);
		print_stat(philo, FORK);
	}
	return (isdead(philo->vars));
}

int	eating(t_philo *philo)
{
	philo->eat_cnt++;

	pthread_mutex_lock(&philo->m_eat_time);
	philo->last_eat_time = print_stat(philo, EAT);
	pthread_mutex_unlock(&philo->m_eat_time);
	
	ft_usleep(philo, philo->last_eat_time, EAT);
	pthread_mutex_unlock(&philo->vars->fork[philo->fork[0]]);
	pthread_mutex_unlock(&philo->vars->fork[philo->fork[1]]);
	return (isdead(philo->vars));
}

int	sleeping(t_philo *philo)
{
	ft_usleep(philo, print_stat(philo, SLEEP), SLEEP);
	return (isdead(philo->vars));
}

int	thinking(t_philo *philo)
{
	print_stat(philo, THINK);
	return (isdead(philo->vars));
}
