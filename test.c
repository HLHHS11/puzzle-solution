#include<stdio.h>
#include<stdlib.h>

void makeArray(int*** a, unsigned v, unsigned h)
{
    unsigned i;
    *a = (int**)calloc(v, sizeof(int*));
    for (i = 0; i < v; i++) {
        (*a)[i] = (int*)calloc(h, sizeof(int));
        //*a[i] = (int*)calloc(h,sizeof(int)); // *(a[i])と同じなのでエラー
    }
}

void freeArray(int*** a, unsigned v)
{
    unsigned i;
    for (i = 0; i < v; i++) {
        free((*a)[i]);
    }
    free(*a);
}

int main()
{
    int** a;
    unsigned v, h;
    scanf("%u %u", &v, &h);

    unsigned i, j;

    makeArray(&a, v, h);

    for (i = 0; i < v; i++) {
        for (j = 0; j < h; j++) {
            a[i][j] = i * j;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    freeArray(&a,v);
    return 0;
}