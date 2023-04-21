/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:09:56 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/22 07:44:05 by hyeonsul         ###   ########.fr       */
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
	int				nop;
	int				ttd;	// time_to_die;
	int				tte;	// time_to_eat;
	int				tts;	// time_to_sleep;
	int				notepme;
	struct timeval	start_time;
}	t_vars;

typedef struct s_philo {
	pthread_t	thread;
	t_vars		*vars;
	int			no;
	int			eat_count;
}	t_philo;

#endif
