#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Инициализация генератора случайных чисел.
    srand(time(NULL));

    // Генерация случайного числа
    int random_number = rand();
    // TODO: В Windows (CLion) выводятся иероглифы вместо кириллицы.
    printf("Случайное число: %d\n", random_number);

    return 0;
}