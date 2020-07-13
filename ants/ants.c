#include <stdio.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main() {
    int input;
    scanf("%d", &input);
    
    while (input--) {
        int length, cases;
        scanf("%d %d", &length, &cases);
        int min = 0;
        int max = 0;
        while (cases--) {
            int ant;
            scanf("%d", &ant);
            min = max(min, min(ant, length-ant));
            max = max(max, max(ant, length-ant));
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}