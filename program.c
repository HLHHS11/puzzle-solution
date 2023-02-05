#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NX 10
#define NY 12

// 完成
void initGrid (char*** grid)
{
    unsigned i, j;
    *grid = (char**)calloc(NY, sizeof(char*));
    for (i=0; i<NY; i++) {
        (*grid)[i] = (char*)calloc(NX, sizeof(char));
        for (j=0; j<NX; j++) {
            (*grid)[i][j] = 'O';
        }
    }
}


// 完成
void freeGrid (char*** grid)
{
    unsigned i;
    for (i=0; i<NY; i++) {
        free((*grid)[i]);
    }
    free(*grid);
}


// 完成
void printGrid (char*** grid) {
    unsigned i, j;
    printf(" |");
    for (j=0; j<NX; j++) {
        printf("%u|",j);
    }
    printf("\n");
    for (j=0; j<NX+1; j++) {
        printf("-+");
    }
    printf("\n");
    for (i=0; i<NY; i++) {
        printf("%u|",i);
        for (j=0; j<NX; j++) {
            printf("%c|",(*grid)[i][j]);
        }
        printf("\n");
    }
}


void getValidInput (unsigned* inputUint)
{
    unsigned uint0, uint1;
    do {
        char input[100];
        print("マスを指定してください（例:3列・5行→3 5）\n");
        fgets(input, 100, stdin);
        if (sscanf(input, "%u %u", &uint0, &uint1)) {
            if (uint0<NX && uint1<NY) {
                break;
            } else {
                printf("列番号はNX-1以下、行番号はNY-1以下で指定してください\n");
                continue;
            }
        } else {
            printf("入力形式が間違っています。\n「列番号+半角スペース+行番号」の形式で指定してください\n");
            continue;
        }
    } while (true);
    inputUint[0] = uint0;
    inputUint[1] = uint1;
    // *(inputUint)[0] = uint0;と書いたら
    // "オペランド '*' はポインターである必要がありますが、型 "unsigned int" が指定されています"
    // といわれた。受け取ったポインタにはずっと*つけると思ってたから、
    // 認識を変えなければ！！
}


void updateGrid (char*** grid)
{
    //getvalidinputを実行
    unsigned inputUint[2];
    getValidInput(&inputUint);
    int itr[5][2] = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
    unsigned i;
    int tempX, tempY;
    for (i=0; i<5; i++) {
        tempX = inputUint[0] + itr[i][0];
        tempY = inputUint[1] + itr[i][1];
        if ((tempX>=0&&tempX<NX) && (tempY>=0&&tempY<NY)) {
            if ((*grid)[tempY][tempX] == 'X') {
                (*grid)[tempY][tempX] = 'O';
            } else {
                (*grid)[tempY][tempX] = 'X'; 
            }
        } else {
            continue;
        }
    }


    
}


bool isSolved (char*** grid)
{
    unsigned i,j;
    for (i=0; i<NY; i++) {
        for (j=0; j<NX; j++) {
            if ((*grid)[i][j] == 'X') {
                return false;
            }
        }
    }
    return true;
}



int main (void)
{

    /* 配列の初期化 */
    // エラー返ってきたらそこの処理もしないと 。
    char **grid;
    initGrid(&grid);
    printGrid(&grid);

    //while (isNotSolved(&grid)) {
    bool isNotSolved = true;
    unsigned targetx, targety;
    while (true) {
        // 続く
        updateGrid(&grid);
        printGrid(&grid);
        if (isSolved(&grid)) {
            printf("すべてのマスがOになりました。ゲーム終了です！");
            break;
        } else {
            continue;
        }
    }

    // gridに割り当てたメモリを解放
    freeGrid(&grid);
    return 0;
}