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

void checkDuplicate(int arr[], int n) {
    int i;

    sortArray(arr, n);

    for(i = 0; i < n - 1; i++) {

        if(arr[i] == arr[i + 1]) {
            printf("YES\n");
            return;
        }
    }

    printf("NO\n");
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

        checkDuplicate(arr, n);
    }

    return 0;
}