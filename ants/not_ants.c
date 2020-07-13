#include <stdio.h>
#include <stdlib.h>

// doesn't work for some reason

int main(){
    int input;
    scanf("%d", &input);
    
    // notice if a ant hits another ant, it is as if they passed through each other
    while (input--) {
        int length, cases;
        scanf("%d %d", &length, &cases);
        int max = 0, min = length;
        
        float mid = length / 2;
        float closest_mid = (float) length;
        while (cases--) {
            int ant, inv_ant;
            scanf("%d", &ant);
            inv_ant = length - ant;
            // max
            if (ant < inv_ant)
                max = ant;
            else if (length - ant > max)
                max = length - ant;

            // min
            if (ant < min)
                min = ant;
            else if (length - ant < min)
                max = length - ant;

            // closest to mid
            if (abs(mid - (float) ant) < closest_mid)
                closest_mid = abs(mid - (float) ant);
        }

        int _max, _min;
        if (max > length - min)
            _max = max;
        else
            _max = length - min;

        _min = (int) (mid - closest_mid);

        printf("%d %d\n", _min, _max);
    }
}