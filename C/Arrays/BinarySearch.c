#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int target) {

    int left = 0;
    int right = n - 1;

    while ( left <= right ) {

        int mid = (left + right) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;

}

int main() {

    int n, key;
    scanf("%d", &n);

    int * arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    int index = binarySearch(arr, n, key);

    if (index == -1) {
        printf("target not found\n");
    } else {
        printf("target found at index %d\n", index);
    }

    return 0;
}