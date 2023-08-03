#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigpipe_handler(int signum) {
    if (signum == SIGPIPE) {
        printf("SIGPIPE!!\n");
    }
}

int main() {
    signal(SIGPIPE, sigpipe_handler);  // SIGPIPE 시그널 핸들러 등록

    int pipe_fd[2];
    pipe(pipe_fd);

    pid_t child_pid = fork();

    if (!child_pid) {
        // 자식 프로세스에서는 쓰기 작업만 수행
        close(pipe_fd[0]); // 읽기 파이프 종료
        write(pipe_fd[1], "hello\n", 6);
        exit(0);
    }

    return 0;
}
