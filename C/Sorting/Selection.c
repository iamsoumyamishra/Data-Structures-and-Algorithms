#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    int * arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < n-1; i++) {

        int min_index = i;
        
        for (int j = i; j < n; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }

        int min_value = arr[min_index];

        for (int j = min_index; j > i; j--) {
            arr[j] = arr[j - 1];
        }

        arr[i] = min_value;
    }

    for (int i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}