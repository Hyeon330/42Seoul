#include <stdio.h>

int main() {

    // 커서 이동
    tputs(tgoto(tgetstr("cm", NULL), 10, 5), 1, putchar);

    // 텍스트 출력
    tputs(tgetstr("md", NULL), 1, putchar);  // 강조 효과 적용
    tputs("Hello, World!", 1, putchar);
    tputs(tgetstr("me", NULL), 1, putchar);  // 강조 효과 해제

    refresh();  // 화면 갱신

    getch();  // 사용자 입력 대기

    return 0;
}