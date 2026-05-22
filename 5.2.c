#include <stdio.h>

void sort(int arr[], int n) {

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

void findPair(int arr[], int n, int key) {

    sort(arr, n);

    int left = 0;
    int right = n - 1;

    while(left < right) {

        int sum = arr[left] + arr[right];

        if(sum == key) {
            printf("%d %d\n", arr[left], arr[right]);
            return;
        }
        else if(sum < key) {
            left++;
        }
        else {
            right--;
        }
    }

    printf("No Such Element Exist\n");
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

        findPair(arr, n, key);
    }

    return 0;
}