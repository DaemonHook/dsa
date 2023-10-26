//
// Created by daerh on 2023/10/26.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fout;

    struct person {
        char name[20];
        int age;
        float height;
    } ss;

    int n;
    printf("input n:\n");
    scanf("%d", &n);
    fout = fopen("f01.dat", "rb");
    struct person* p = (struct person*) malloc(n * sizeof(ss));

    for (int i = 0; i < n; i++) {
        fread(p + i, sizeof(ss), 1, fout);
    }

    int avg = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        avg += p[i].age;
        if (p[i].age > p[cur].age) {
            cur = i;
        }
    }
    avg /= n;
    printf("ave: %d\n", avg);

    for (int i = 0; i < n; i++) {
        if (p[i].age == p[cur].age) {
            printf("%s\n", p[i].name);
        }
    }

    return 0;
}