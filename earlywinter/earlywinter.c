#include <stdio.h>

int main(){
    int years, this_year;
    scanf("%d %d", &years, &this_year);

    int yearlist[years];

    for (int i = 0; i< years;i++) {
        scanf("%d", &yearlist[i]);
    }

    int count = 0;
    for (int i = 0; i< years;i++) {
        if (yearlist[i] > this_year) {
            count++;
        } else
        {
            break;
        }
        
        
    }

    if (count == years) {
        printf("It had never snowed this early!");
        return 0;
    }

    printf("It hadn't snowed this early in %d years!\n", count);
    return 0;
}
