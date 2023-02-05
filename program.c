#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NX 5
#define NY 7

/** -------------------------
 * @param grid - �񎟌��z��̃|�C���^
 * �p�Y���̃O���b�h����NX�A�cNY�̃T�C�Y�ŏ��������܂��B
 * �O���b�h�́A�����̎Q�Ƃŗ^������񎟌��z��ł��B
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
 * @param grid - �񎟌��z��̃|�C���^ 
 * �p�Y���̃O���b�h�̃������̈���J�����܂��B
 * �v���O�����̏I�����Ɏ��s���܂��B
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
 * @param grid - �񎟌��z��̃|�C���^
 * �O���b�h�̐}���R�}���h���C����ɕ\�����܂��B
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
 * @param inputUint - �T�C�Y�Q�̔z��̃|�C���^
 * �u��ԍ�+���p�X�y�[�X+�s�ԍ��v�̌`���̕W�����͂����߁A
 * �K�؂Ȍ`���̓��͂�����ꂽ���ɁA�����̔z��Ɋi�[���܂��B
 * �֐�updateGrid()���ŌĂяo����܂��B
 *  -------------------------*/
void getValidInput (unsigned* inputUint)
{
    unsigned uint0, uint1;
    do {
        char input[100];
        printf("�}�X���w�肵�Ă��������i��:3��E5�s��3 5�j\n");
        fgets(input, 100, stdin);
        if (sscanf(input, "%u %u", &uint0, &uint1)) {
            if (uint0<NX && uint1<NY) {
                break;
            } else {
                printf("���͌`�����Ԉ���Ă��܂��B��ԍ���NX-1�ȉ��A�s�ԍ���NY-1�ȉ��Ŏw�肵�Ă�������\n");
                continue;
            }
        } else {
            printf("���͌`�����Ԉ���Ă��܂��B\n�u��ԍ�+���p�X�y�[�X+�s�ԍ��v�̌`���Ŏw�肵�Ă�������\n");
            continue;
        }
    } while (true);
    inputUint[0] = uint0;
    inputUint[1] = uint1;
}


/** -------------------------
 * @param grid - �񎟌��z��̃|�C���^
 * getValidInput()�֐���p���ē���ꂽ���Ɋ�Â��āA
 * �O���b�h��`�������܂��B
 *  -------------------------*/
void updateGrid (char*** grid)
{
    //getvalidinput�����s
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
 * @param grid - �񎟌��z��̃|�C���^
 * �X�V���ꂽ�O���b�h���A�I�������𖞂����Ă��邩���肵�܂��B
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

    /* �z��̏����� */
    char **grid;
    initGrid(&grid);
    printGrid(&grid);

    //while (isNotSolved(&grid)) {
    bool isNotSolved = true;
    unsigned targetx, targety;
    while (true) {
        // ����
        updateGrid(&grid);
        printGrid(&grid);
        if (isSolved(&grid)) {
            printf("���ׂẴ}�X��O�ɂȂ�܂����B�Q�[���I���ł��I");
            break;
        } else {
            continue;
        }
    }

    // grid�Ɋ��蓖�Ă������������
    freeGrid(&grid);
    return 0;
}