//
// Created by cubazis on 23.05.18.
//

#include "binarize.h"

int *to_binary(unsigned long long number);

void print_bytes(int bins[]);

void binarize_u(unsigned long long x) {
    int *result = to_binary(x);

    print_bytes(result);
}

void binarize_s(signed long long y) {
    int i = 0;
    int sign;
    if (y < 0) {
        sign = 1;
        y = y * (-1);
    } else {
        sign = 0;
    }

    int *result = to_binary(y);
    if (sign == 1){
        int j = 63;
        while (result[j] == 0) {
            j--;
        }
        while (j % 8 != 7) {
            j++;
        }

        int c = j;
        while (c>=0){
            if (result[c] == 0){
                result[c] = 1;
            } else {
                result[c] = 0;
            }
            c--;
        }

        c =0;
        while(c!=j){
            if (result[c] == 1){
                result[c] = 0;
                c++;
            }
            else{
                result[c] = 1;
                break;
            }
        }
        print_bytes(result);
    }
    else{
        print_bytes(result);
    }
}

int *to_binary(unsigned long long number) {
    static int outNum[64];
    int i = 0;

    while (number > 0) {
        outNum[i] = number % 2;
        i++;
        number = number / 2;
    }
    return outNum;
}

void print_bytes(int bins[]) {
    int j = 63;
    while (bins[j] == 0) {
        j--;
    }
    while (j % 8 != 7) {
        j++;
    }

    while (j > 7) {
        int c;
        for (c = 0; c < 8; c++) {
            printf("%d", bins[j]);
            j--;
        }
        printf(" ");
    }
    int c;
    for (c = 0; c < 8; c++) {
        printf("%d", bins[j]);
        j--;
    }
    printf("\n");
}