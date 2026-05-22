#include <stdio.h>

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            ans = mid;
            high = mid - 1;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            ans = mid;
            low = mid + 1;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

void countCopies(int arr[], int n, int key) {
    int first = firstOccurrence(arr, n, key);

    if(first == -1) {
        printf("Key not present\n");
        return;
    }

    int last = lastOccurrence(arr, n, key);

    int count = last - first + 1;

    printf("%d - %d\n", key, count);
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int n, i, key;

        scanf("%d", &n);

        int arr[n];

        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        scanf("%d", &key);

        countCopies(arr, n, key);
    }

    return 0;
}