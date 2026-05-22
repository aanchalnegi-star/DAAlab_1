#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    int comparisons = 0;
    int swaps = 0;

    for(i = 0; i < n - 1; i++) {

        minIndex = i;

        for(j = i + 1; j < n; j++) {
            comparisons++;

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            swaps++;
        }
    }

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\ncomparisons = %d", comparisons);
    printf("\nswaps = %d\n", swaps);
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

        selectionSort(arr, n);
    }

    return 0;
}