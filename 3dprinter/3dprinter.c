#include <stdio.h>
#include <math.h> 

int days(int input) {
    if (input < 4)
        return input;
    else {
        float x = log(input) / log(2);
        int y = ceil(x);
        y++;
        return y;
    }
}

int main(){
    int input;
    scanf("%i", &input);

    printf("%i\n", days(input));
    return 0;
}
