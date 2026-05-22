#include <stdio.h>

void findSequence(int arr[], int n) {
    int i, j, k;

    for(k = 0; k < n; k++) {
        i = 0;
        j = k - 1;

        while(i < j) {
            int sum = arr[i] + arr[j];

            if(sum == arr[k]) {
                printf("%d, %d, %d\n", i, j, k);
                return;
            }
            else if(sum < arr[k]) {
                i++;
            }
            else {
                j--;
            }
        }
    }

    printf("No sequence found\n");
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int n, i;

        scanf("%d", &n);

        int arr[n];

        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        findSequence(arr, n);
    }

    return 0;
}