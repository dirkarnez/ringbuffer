#include <stdio.h>
#include <stdlib.h>

size_t idx = -1;

void append(int **cb, int data, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (cb[i] == NULL) {
            idx = i;
            break;
        }
    }
  
    printf("!!%d\n", idx);
    if (idx > -1) {
        cb[idx] = (int *)malloc(sizeof(int));
        *cb[idx] = data;
    } else {

    }
}

void print(int **cb, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (cb[i] == NULL) {
            printf("NULL\n");
        } else {
            printf("%d\n", *cb[i]);
        }
    }
}
int main() {
    int* a[5] = {};
     for (size_t i = 0; i < 5; i++) {
        a[i] = NULL;
    }

    print(a, 5);

    append(a, 10, 5);
    print(a, 5);

    append(a, 11, 5);
    print(a, 5);

    append(a, 12, 5);
    print(a, 5);

    append(a, 13, 5);
    print(a, 5);

    append(a, 14, 5);
    print(a, 5);

    append(a, 15, 5);
    print(a, 5);

    

   return 0;
}

