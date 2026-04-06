#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // В таком виде эта программа всегда будет выводить одно и то же число.
    int random_number = rand();
    printf("Случайное число БЕЗ инициализации: %d\n", random_number);
}