#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NX 5
#define NY 7

/** -------------------------
 * @param grid - 二次元配列のポインタ
 * パズルのグリッドを横NX、縦NYのサイズで初期化します。
 * グリッドは、引数の参照で与えられる二次元配列です。
 *  -------------------------*/
void initGrid (char*** grid)
{
    unsigned i, j;
    *grid = (char**)calloc(NY, sizeof(char*));
    for (i=0; i<NY; i++) {
        (*grid)[i] = (char*)calloc(NX, sizeof(char));
        for (j=0; j<NX; j++) {
            (*grid)[i][j] = 'X';
        }
    }
}


/** -------------------------
 * @param grid - 二次元配列のポインタ 
 * パズルのグリッドのメモリ領域を開放します。
 * プログラムの終了時に実行します。
 *  -------------------------*/ 
void freeGrid (char*** grid)
{
    unsigned i;
    for (i=0; i<NY; i++) {
        free((*grid)[i]);
    }
    free(*grid);
}


/** -------------------------
 * @param grid - 二次元配列のポインタ
 * グリッドの図をコマンドライン上に表示します。
 *  -------------------------*/
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


/** -------------------------
 * @param inputUint - サイズ２の配列のポインタ
 * 「列番号+半角スペース+行番号」の形式の標準入力を求め、
 * 適切な形式の入力が得られた時に、引数の配列に格納します。
 * 関数updateGrid()内で呼び出されます。
 *  -------------------------*/
void getValidInput (unsigned* inputUint)
{
    unsigned uint0, uint1;
    do {
        char input[100];
        printf("マスを指定してください（例:3列・5行→3 5）\n");
        fgets(input, 100, stdin);
        if (sscanf(input, "%u %u", &uint0, &uint1)) {
            if (uint0<NX && uint1<NY) {
                break;
            } else {
                printf("入力形式が間違っています。列番号はNX-1以下、行番号はNY-1以下で指定してください\n");
                continue;
            }
        } else {
            printf("入力形式が間違っています。\n「列番号+半角スペース+行番号」の形式で指定してください\n");
            continue;
        }
    } while (true);
    inputUint[0] = uint0;
    inputUint[1] = uint1;
}


/** -------------------------
 * @param grid - 二次元配列のポインタ
 * getValidInput()関数を用いて得られた情報に基づいて、
 * グリッドを描き換えます。
 *  -------------------------*/
void updateGrid (char*** grid)
{
    //getvalidinputを実行
    unsigned inputUint[2];
    getValidInput(inputUint);
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


/** -------------------------
 * @param grid - 二次元配列のポインタ
 * 更新されたグリッドが、終了条件を満たしているか判定します。
 *  -------------------------*/ 
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


/** -------------------------
 * 
 * 
 *  -------------------------*/ 
int main (void)
{

    /* 配列の初期化 */
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