//
// Created by daerh on 2023/10/26.
//

#include <stdio.h>

int func1(int val)
{
    int sum = 0;
    if (val) {
        sum = val + func1(val - 1);
    }
    return sum;
}

int main()
{
    printf("%d\n", func1(-9));
}