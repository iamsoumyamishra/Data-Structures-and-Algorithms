#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    int * arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int insertIndex = i;
        int currentValue = arr[i];
        
        int j = i - 1;
        
        while (j >= 0 && arr[j] > currentValue) {
            arr[j + 1] = arr[j];
            insertIndex = j;
            j--;
        }

        arr[insertIndex] = currentValue;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}