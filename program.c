#include<stdio.h>
#include<stdlib.h>

void initSquare (char*** square, unsigned nx, int ny)
{
    printf("%d, %d",nx, ny);
    //外側から用意する
    unsigned i, j;
    printf("アドレス値は%d\n", &nx);
    *square = (char**)malloc(ny*sizeof(char*));
    for (i=0; i<ny; i++) {
        (*square)[i] = (char*)malloc(nx*sizeof(char));
        //printf("init一重ループ");
        printf("%d", i);
    }
    for (i=0; i<ny; i++) {
        for (j=0; i<nx; j++) {
            square[i][j] = "O";
            //printf("%d,",i);
        }
    }
    printf("init終わった\n");
}


void freeSquare (char*** square, unsigned ny) {
    unsigned i;
    for (i=0; i<ny; i++) {
        free((*square)[i]);
    }
    free(*square);
}


void printSquare (char*** square, unsigned nx, unsigned ny) {
    unsigned i, j;
    printf("aaaaa");
    for (i=0; i<ny; i++) {
        for (j=0; j<nx; j++) {
            printf("agaaaaa");
            printf("%c ",square[i][j]);
        }
        printf("\n");
    }
}


int main (void)
{

    /* マス目に対応する配列の初期化 */
    unsigned nx, ny;
    printf("マス目の横の長さnxと縦の長さnyを入力してください\n");
    scanf("%u %u", &nx, &ny);
    printf("取得値は%u, %u",nx, ny);
    // エラー返ってきたらそこの処理もしないと。
    char **square;
    initSquare(&square, nx, ny);
    printSquare(&square, nx, ny);
    printf("printSquareの後ろ");
    freeSquare(&square, ny);
    return 0;
}