/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:09:56 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/06 18:17:06 by hyeonsul         ###   ########.fr       */
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
	pthread_mutex_t	mutex;
	int				*fork;
	int				nop;		// number_of_philosophrs
	int				ttd;		// time_to_die;
	int				tte;		// time_to_eat;
	int				tts;		// time_to_sleep;
	int				notepme;	// [number_of_times_each_philosopher_must_eat]
	int				died;
}	t_vars;

typedef struct s_philo {
	pthread_t	thread;
	t_vars		*vars;
	int			num;
}	t_philo;

#endif
