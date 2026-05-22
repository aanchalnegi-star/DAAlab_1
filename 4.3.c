#include <stdio.h>

void sortArray(int arr[], int n) {

    int i, j, temp;

    for(i = 0; i < n - 1; i++) {

        for(j = 0; j < n - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void kthSmallest(int arr[], int n, int k) {

    if(k > n || k <= 0) {
        printf("not present\n");
        return;
    }

    sortArray(arr, n);

    printf("%d\n", arr[k - 1]);
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

        kthSmallest(arr, n, k);
    }

    return 0;
}