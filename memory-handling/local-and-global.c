#include <stdio.h>

int y = 1;

int main() {
    int x = 4;

    printf("Локальная переменная x хранится по адресу: %p\n", &x);
    printf("Глобальная переменная y хранится по адресу: %p\n", &y);

    return 0;
}
