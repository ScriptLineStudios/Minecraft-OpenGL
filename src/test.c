#include<stdio.h>
#include<math.h>

#include "perlin.h"

int main()
{   
    for (int x = 0; x < 16; x++){
        for (int y = 0; y < 16; y++){
            int height = round(8.0 + pnoise2d((double)x, (double)y, 0.0, 3, 1000000) * 3.0);
            printf("%d \n", height);

        }
    }
    return 0;
}