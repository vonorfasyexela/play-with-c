#include <stdio.h>
#include <stdlib.h>

int global_initialized_variable = 1;
int global_uninitialized_variable;

int main() {
    // Локальная переменная будет создана в стеке.
    // При этом неважно, инициализируется она или нет.
    int local_variable = 4;
    printf("Локальная переменная хранится по адресу: %p\n", &local_variable);

    // Инициализированная глобальная переменная будет создана в секции .data.
    printf("Глобальная ИНИЦИАЛИЗИРОВАННАЯ переменная хранится по адресу: %p\n", &global_initialized_variable);
    // Неинициализированная глобальная переменная будет создана в секции .bss.
    printf("Глобальная НЕинициализированная переменная хранится по адресу: %p\n", &global_uninitialized_variable);

    // Динамически создаваемая переменная будет располагаться в куче.
    int *dynamic_variable = malloc(sizeof(*dynamic_variable));
    printf("Динамически создаваемая переменная хранится по адресу: %p\n", &dynamic_variable);
    free(dynamic_variable);

    return 0;
}
