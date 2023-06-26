/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:09:56 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/26 17:18:50 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_vars {
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_time;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_full;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notpme;
	int				full_cnt;
	int				dead;
	long long		start_time;
}	t_vars;

typedef struct s_philo {
	pthread_t		thread;
	pthread_mutex_t	m_eat_time;
	t_vars			*vars;
	int				fork[2];
	int				id;
	int				eat_cnt;
	long long		last_eat_time;
}	t_philo;

enum e_stat {
	FORK = 0,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

// init.c
int			philo_init(t_vars *vars, t_philo **philo, char **av);

// util.c
long long	get_time(void);
long long	print_stat(t_philo *philo, int stat);
void		ft_usleep(t_philo *philo, long long start, int stat);

// check.c
int			isdead(t_vars *vars);
int			isfull(t_philo *philo);
int			is_all_full(t_vars *vars);
int			chk_philos(t_philo *philo, t_vars *vars);

// act.c
int			take_fork(t_philo *philo);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
int			thinking(t_philo *philo);

#endif
