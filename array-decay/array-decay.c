// Пример, демонстрирующий эффект разложения массива на указатель.
#include <stdio.h>

void print_array_length(int arr[]) {
    printf("= Inside another function =\n");
    size_t size_of_array = sizeof(arr);
    size_t size_of_first_element = sizeof(arr[0]);

    printf("\tSize of the array: %zu bytes\n", size_of_array);
    printf("\tSize of the first element: %zu bytes\n", size_of_first_element);
    printf("\tCalculated number of elements: %zu / %zu = %zu\n", size_of_array, size_of_first_element, size_of_array / size_of_first_element);
}

int main() {
    // Массив из 5 элементов типа int.
    int a[5] = {1, 2, 3, 4, 5};

    size_t size_of_array = sizeof(a);
    size_t size_of_first_element = sizeof(a[0]);

    printf("= In the same function =\n");
    // Здесь нужно использовать именно спецификатор zu.
    // Если прописать llu, то на Raspberry Pi это работает неправильно.
    printf("\tSize of the array: %zu bytes\n", size_of_array);
    printf("\tSize of the first element: %zu bytes\n", size_of_first_element);
    printf("\tCalculated number of elements: %zu / %zu = %zu\n", size_of_array, size_of_first_element, size_of_array / size_of_first_element);

    print_array_length(a);

    return 0;
}