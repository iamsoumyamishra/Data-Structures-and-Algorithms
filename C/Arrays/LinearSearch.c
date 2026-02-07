#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, target, flag = 0, index;
    scanf("%d", &n);

    int * arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        if (target == arr[i]){
            flag = 1;
            index = i;
            break;
        }
    }

    if (flag == 1) {
        printf("%d found at index at %d\n", target, index);
    } else {
        printf("%d not found\n", target);
    }
    
    return 0;
}