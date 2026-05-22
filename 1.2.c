#include <stdio.h>

void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int comp = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        comp++;

        if(arr[mid] == key) {
            printf("Present %d\n", comp);
            return;
        }
        else if(key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
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

        binarySearch(arr, n, key);
    }

    return 0;
}