#include<stdio.h>
#include<stdlib.h>

void initSquare (char*** square, unsigned nx, int ny)
{
    printf("%d, %d",nx, ny);
    //�O������p�ӂ���
    unsigned i, j;
    printf("�A�h���X�l��%d\n", &nx);
    *square = (char**)malloc(ny*sizeof(char*));
    for (i=0; i<ny; i++) {
        (*square)[i] = (char*)malloc(nx*sizeof(char));
        //printf("init��d���[�v");
        printf("%d", i);
    }
    for (i=0; i<ny; i++) {
        for (j=0; i<nx; j++) {
            square[i][j] = "O";
            //printf("%d,",i);
        }
    }
    printf("init�I�����\n");
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

    /* �}�X�ڂɑΉ�����z��̏����� */
    unsigned nx, ny;
    printf("�}�X�ڂ̉��̒���nx�Əc�̒���ny����͂��Ă�������\n");
    scanf("%u %u", &nx, &ny);
    printf("�擾�l��%u, %u",nx, ny);
    // �G���[�Ԃ��Ă����炻���̏��������Ȃ��ƁB
    char **square;
    initSquare(&square, nx, ny);
    printSquare(&square, nx, ny);
    printf("printSquare�̌��");
    freeSquare(&square, ny);
    return 0;
}