#include <stdio.h>

void commonElements(int arr1[], int m, int arr2[], int n) {

    int i = 0;
    int j = 0;

    while(i < m && j < n) {

        if(arr1[i] == arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}

int main() {

    int m, n, i;

    scanf("%d", &m);

    int arr1[m];

    for(i = 0; i < m; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &n);

    int arr2[n];

    for(i = 0; i < n; i++)
        scanf("%d", &arr2[i]);

    commonElements(arr1, m, arr2, n);

    return 0;
}