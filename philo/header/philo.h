/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:09:56 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/09 20:14:46 by hyeonsul         ###   ########.fr       */
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
	pthread_mutex_t	print;
	int				nop;		// number_of_philosophrs
	int				ttd;		// time_to_die;
	int				tte;		// time_to_eat;
	int				tts;		// time_to_sleep;
	int				notpme;		// [number_of_times_each_philosopher_must_eat]
	int				full_cnt;
	int				died;
	long long		start_time;
}	t_vars;

typedef struct s_philo {
	pthread_t	thread;
	t_vars		*vars;
	int			fork[2];
	int			id;
	int			eat_cnt;
	long long	last_eat_time;
}	t_philo;

enum e_stat {
	DIE = 0,
	FULL,
	FORK,
	EAT,
	SLEEP,
	THINK,
};

#endif
