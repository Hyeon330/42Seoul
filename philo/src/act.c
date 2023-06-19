/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:30:24 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/19 23:07:16 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->fork[philo->fork[0]]);
	print_stat(philo, FORK);
	pthread_mutex_lock(&philo->vars->fork[philo->fork[1]]);
	print_stat(philo, FORK);
	return (isdead(philo));
}

int	eating(t_philo *philo)
{
	philo->eat_cnt++;
	philo->last_eat_time = print_stat(philo, EAT);
	ft_usleep(philo, philo->last_eat_time, EAT);
	pthread_mutex_unlock(&philo->vars->fork[philo->fork[0]]);
	pthread_mutex_unlock(&philo->vars->fork[philo->fork[1]]);
	return (isdead(philo));
}

int	sleeping(t_philo *philo)
{
	ft_usleep(philo, print_stat(philo, SLEEP), SLEEP);
	return (isdead(philo));
}

int	thinking(t_philo *philo)
{
	print_stat(philo, THINK);
	return (isdead(philo));
}
