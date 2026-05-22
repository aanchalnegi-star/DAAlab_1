#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int n, key, i, found = 0, comp = 0;

        scanf("%d", &n);

        int arr[n];

        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        scanf("%d", &key);

        for(i = 0; i < n; i++) {
            comp++;

            if(arr[i] == key) {
                found = 1;
                break;
            }
        }

        if(found)
            printf("Present %d\n", comp);
        else
            printf("Not Present %d\n", comp);
    }

    return 0;
}