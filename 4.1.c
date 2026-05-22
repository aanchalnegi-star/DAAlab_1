#include <stdio.h>

int comparisons = 0;
int inversions = 0;

void merge(int arr[], int low, int mid, int high) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    int i, j, k;

    for(i = 0; i < n1; i++)
        L[i] = arr[low + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while(i < n1 && j < n2) {

        comparisons++;

        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
            inversions += (n1 - i);
        }
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int low, int high) {

    if(low < high) {

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
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

        comparisons = 0;
        inversions = 0;

        mergeSort(arr, 0, n - 1);

        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);

        printf("\ncomparisons = %d", comparisons);
        printf("\ninversions = %d\n", inversions);
    }

    return 0;
}