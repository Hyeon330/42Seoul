#include "../header/philo.h"

void    test1()
{
	struct timeval    tm;
	long long	time;

	while (1)
	{
		gettimeofday(&tm, NULL);
		time = tm.tv_sec * 1000000 + tm.tv_usec;
		printf("%lld\n", time);
		if (tm.tv_usec == 11)
			break ;
	}
}

void	*p_function(void *data)
{
	pid_t	pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();

	char* thread_name = (char *)data;
	int i = 0;

	while (i < 3)
	{
		printf("htread name: %s, tid: %p, pid: %u\n", thread_name, &tid, (unsigned int)pid);
		i++;
		sleep(1);
	}
	return (NULL);
}

void	test2()
{
	pthread_t pthread[2];
	int	thr_id;
	int	status;
	char *p1 = "thread_1";
	char *p2 = "thread_2";
	char *p3 = "thread_3";

	sleep(1);

	thr_id = pthread_create(&pthread[0], NULL, p_function, (void *)p1);
	if (thr_id < 0)
	{
		perror("pthread0 create error");
		exit(EXIT_FAILURE);
	}

	thr_id = pthread_create(&pthread[1], NULL, p_function, (void *)p2);
	if (thr_id < 0)
	{
		perror("pthread0 create error");
		exit(EXIT_FAILURE);
	}

	p_function((void *)p3);

	pthread_join(pthread[0], (void **)&status);
	pthread_join(pthread[1], (void **)&status);

	printf("end??\n");
}

typedef struct s_aa {
	pthread_mutex_t mutex;
	int count;
}	t_aa;

int     ft_putstr_fd(char *s, int fd)
{
	int	cnt;

	cnt = -1;
	while (s[++cnt])
		write(fd, s + cnt, 1);
	return (cnt);
}

void *increment_count(void *arg) {
	t_aa *aa;
	pthread_t tid;
    int i;

	aa = (t_aa *)arg;
	tid = pthread_self();
    for (i = 0; i < 100; i++) {
		// 뮤텍스 잠금
		pthread_mutex_lock(&aa->mutex);

        // 전역 변수 증가
		printf("tid: %x, count: %d\n", (unsigned int)tid, ++aa->count);

		// 뮤텍스 해제
 		pthread_mutex_unlock(&aa->mutex);

    }
    return NULL;
}

int	test3()
{
	t_aa aa;

	aa.count = 0;

	pthread_mutex_init(&aa.mutex, NULL);

    // 두 개의 스레드 생성
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment_count, (void *)&aa);
	// pthread_detach(thread1);
    pthread_create(&thread2, NULL, increment_count, (void *)&aa);
	// pthread_detach(thread2);

    // 두 스레드가 종료될 때까지 대기
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 결과 출력
    printf("count: %d\n", aa.count);

    // 뮤텍스 제거
    pthread_mutex_destroy(&aa.mutex);

    return 0;
}

typedef struct s_abc {
	int	a;
	int	b;
	int c;
}	t_abc;

int	a()
{
	printf("true\n");
	return (1);
}

int	b()
{
	printf("false\n");
	return (0);
}

int main()
{
	test1();
}
