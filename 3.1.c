#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    int comparisons = 0;
    int shifts = 0;

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0) {
            comparisons++;

            if(arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            }
            else {
                break;
            }
        }

        arr[j + 1] = key;
    }

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\ncomparisons = %d", comparisons);
    printf("\nshifts = %d\n", shifts);
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

        insertionSort(arr, n);
    }

    return 0;
}