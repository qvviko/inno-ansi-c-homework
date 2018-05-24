//
// Created by cubazis on 23.05.18.
//

#include "binarize.h"


void binarize_u(unsigned long long x) {
    int outNum[64];

    int i = 0;
    while (x > 0) {
        outNum[i] = x % 2;
        i++;
        x = x / 2;
    }
}

void binarize_s(signed long long y) {
    int outNum[64];

    int i = 0;
    if (y < 0){
        int sign = 1;
        y = y*(-1);
    }
    else{
        int sign = 0;
    }
    while (y > 0) {
        outNum[i] = y % 2;
        i++;
        y = y / 2;
    }
    i = 63;
    while (i != -1) {
        printf("%d", outNum[i]);
        i--;
    }

}
