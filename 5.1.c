#include <stdio.h>

void maxOccurrence(char arr[], int n) {

    int count[26] = {0};

    int i;

    for(i = 0; i < n; i++) {
        count[arr[i] - 'a']++;
    }

    int max = 0;
    char ch;

    for(i = 0; i < 26; i++) {

        if(count[i] > max) {
            max = count[i];
            ch = i + 'a';
        }
    }

    if(max == 1) {
        printf("No Duplicates Present\n");
    }
    else {
        printf("%c-%d\n", ch, max);
    }
}

int main() {

    int T;
    scanf("%d", &T);

    while(T--) {

        int n, i;
        scanf("%d", &n);

        char arr[n];

        for(i = 0; i < n; i++) {
            scanf(" %c", &arr[i]);
        }

        maxOccurrence(arr, n);
    }

    return 0;
}