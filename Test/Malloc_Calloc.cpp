#include <stdio.h>
#include <stdlib.h>

int main () {
    int* allocated_with_malloc = (int*)malloc(5 * sizeof(int));
    int* allocated_with_calloc = (int*)calloc(5, sizeof(int));

    printf("Values of allocated_with_calloc: ");
    for (size_t i = 0; i < 5; ++i) {
        printf("%d ", allocated_with_calloc[i]);
    }

    putchar('\n');

    int* failed_malloc = (int*)malloc(1000000000000);
    if (failed_malloc == NULL) {
        printf("The allocation failed, the value of failed_malloc is: %p", (void*)failed_malloc);
    }

    free(allocated_with_malloc);
    free(allocated_with_calloc);

    return 0;
}
