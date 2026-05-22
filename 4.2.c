#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;
int swaps = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

int partition(int arr[], int low, int high) {

    int random = low + rand() % (high - low + 1);

    swap(&arr[random], &arr[high]);

    int pivot = arr[high];

    int i = low - 1;
    int j;

    for(j = low; j < high; j++) {

        comparisons++;

        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {

    if(low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    srand(time(0));

    int T;
    scanf("%d", &T);

    while(T--) {

        int n, i;

        scanf("%d", &n);

        int arr[n];

        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        comparisons = 0;
        swaps = 0;

        quickSort(arr, 0, n - 1);

        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);

        printf("\ncomparisons = %d", comparisons);
        printf("\nswaps = %d\n", swaps);
    }

    return 0;
}