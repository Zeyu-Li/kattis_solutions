#include <stdio.h>


int main() {
    int nums;
    scanf("%d", &nums);

    char previous;
    scanf("%c", &previous);

    int total = 0;
    
    for (int i = 0; i < nums; i++) {
        char curr;
        scanf(" %c", &curr);
        if (previous == curr) {
            total++;
        }
        previous = curr;
    }

    printf("%d\n", total);
    return 0;
}
