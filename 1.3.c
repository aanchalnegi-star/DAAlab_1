#include <stdio.h>
#include <math.h>

void jumpSearch(int arr[], int n, int key) {
    int step = 2;
    int prev = 0;
    int comp = 0;
    int i;

    while(prev < n && arr[prev] < key) {
        comp++;

        if(prev + step >= n)
            break;

        prev = prev + step;
    }

    int start = prev - step;

    if(start < 0)
        start = 0;

    int end = prev;

    if(end >= n)
        end = n - 1;

    for(i = start; i <= end; i++) {
        comp++;

        if(arr[i] == key) {
            printf("Present %d\n", comp);
            return;
        }
    }

    printf("Not Present %d\n", comp);
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int n, key, i;

        scanf("%d", &n);

        int arr[n];

        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        scanf("%d", &key);

        jumpSearch(arr, n, key);
    }

    return 0;
}