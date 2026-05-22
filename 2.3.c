#include <stdio.h>

void countPairs(int arr[], int n, int k) {
    int count = 0;
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {

            if(arr[j] - arr[i] == k ||
               arr[i] - arr[j] == k) {
                count++;
            }
        }
    }

    printf("%d\n", count);
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int n, i, k;

        scanf("%d", &n);

        int arr[n];

        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        scanf("%d", &k);

        countPairs(arr, n, k);
    }

    return 0;
}