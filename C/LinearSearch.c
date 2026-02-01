#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, key;
    scanf("%d", &n);

    int * arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key){
            printf("%d found at index %d\n", key, i);
            return 0;
        }
    }

    printf("%d not found\n", key);

    return 0;
}