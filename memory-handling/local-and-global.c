#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    printf("Динамически создаваемая переменная хранится по адресу: %p\n", dynamic_variable);
    free(dynamic_variable);

    // На разных платформах по-разному устроен memory layout.
#ifdef __linux__
    assert(&local_variable > dynamic_variable);
    assert(dynamic_variable > &global_uninitialized_variable);
    assert(&global_uninitialized_variable > &global_initialized_variable);
#elif _WIN64
    assert(&global_uninitialized_variable > &global_initialized_variable);
    assert(&global_initialized_variable > dynamic_variable);
    assert(dynamic_variable > &local_variable);
#endif

    return 0;
}
