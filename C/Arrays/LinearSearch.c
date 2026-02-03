#include <stdio.h>
#include <stdlib.h>


int main() {

    int n, key, flag = 0, index;
    scanf("%d", &n);

    int * arr = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    for(int i = 0; i < n; i++){

        if (arr[i] == key){
            index = i;
            flag = 1;
            break;
        }
    }
    
    if (flag) {
        printf("%d found at Index %d\n", key, index);
    } else {
        printf("%d not found\n", key);
    }

    return 0;
}