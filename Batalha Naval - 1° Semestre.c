#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
    const int TAM=10,TAM2=15;
    int embarc[TAM][TAM],embarc1[TAM2][TAM2],i,j,cruzadores=0, hidro=0,letra=65,b,acertos=0,cond=0,jogadas=0,dificuldade;
    char a,jogo[TAM][TAM],jogo1[TAM2][TAM2],nome[20];
    srand(time(NULL));

    printf("Selecione a dificuldade: 1 para facil e 2 para dificil ");
    scanf("%d",&dificuldade);

        if(dificuldade==1){
            for(i=0;i<TAM;i++){
                for(j=0;j<TAM;j++){
                    embarc[i][j]=0;
                    jogo[i][j]='~';
                }
            }
            do{
            i=rand()%TAM-2;
            j=rand()%TAM-2;
            if((embarc[i][j]==0)&&(embarc[i][j]!=1)&&(embarc[i][j+1]!=1)&&(i>0)&&(j>0)){
                embarc[i][j]++;
                embarc[i][j+1]++;
                cruzadores++;
            }
            }while(cruzadores<2);

            do{
                i=rand()%TAM-2;
                j=rand()%TAM-2;
                if((embarc[i][j]==0)&&(embarc[i][j]!=1)&&(embarc[i-1][j+1]!=1)&&(embarc[i][j+2]!=1)&&(embarc[i][j]!=2)&&(embarc[i-1][j+1]!=2)&&(embarc[i][j+2]!=2)&&(i>0)&&(j>0)){
                    embarc[i][j]++;
                    embarc[i-1][j+1]++;
                    embarc[i][j+2]++;
                    embarc[i][j]++;
                    embarc[i-1][j+1]++;
                    embarc[i][j+2]++;
                    hidro++;
                }

            }while(hidro<2);
            printf("   1 2 3 4 5 6 7 8 9 10");
            for(i=0;i<TAM;i++){
                printf("\n %c ",letra);
                letra++;
            for(j=0;j<TAM;j++){
                printf("%c ",jogo[i][j]);
            }
        }
        do{
            printf("\nDigite a coordenada\n");
            fflush(stdin);
            scanf("%c",&a);
            scanf("%d",&b);
            if ((a == 'A') || (a == 'a')){
                j=0;
            }
            if ((a == 'B') || (a == 'b')){
                j=1;
            }
            if ((a == 'C') || (a == 'c')){
                j=2;
            }
            if ((a == 'D') || (a == 'd')){
                j=3;
            }
            if ((a == 'E') || (a == 'e')){
                j=4;
            }
            if ((a == 'F') || (a == 'f')){
                j=5;
            }
            if ((a == 'G') || (a == 'g')){
                j=6;
            }
            if ((a == 'H') || (a == 'h')){
                j=7;
            }
            if ((a == 'I') || (a == 'i')){
                j=8;
            }
            if ((a == 'J') || (a == 'j')){
                j=9;
            }
            b--;
            if (embarc[j][b] == 1){
                jogo[j][b] = 'C';
                acertos++;
                jogadas++;
                cond=0;
            }
            if(embarc[j][b]==2){
                jogo[j][b] = 'H';
                acertos++;
                jogadas++;
                cond=0;
            }
            if(embarc[j][b]==0){
                jogo[j][b]='*';
                jogadas++;
                cond=1;
            }
            system("cls");
            letra=65;
            printf("   1 2 3 4 5 6 7 8 9 10");
            for(i=0;i<TAM;i++){
                printf("\n %c ",letra);
                letra++;
            for(j=0;j<TAM;j++){
                printf("%c ",jogo[i][j]);
                }
            }
        if (cond == 0){
            printf("\nVoce acertou\n");
        }
        if (cond==1){
            printf("\nErrou\n");
        }
        }while(acertos != 10);
        printf("Escreva seu nome");
        scanf("%c", &nome);
        printf("Você completou o jogo com %d jogadas",jogadas);
        }
    if(dificuldade==2){
        for(i=0;i<TAM2;i++){
            for(j=0;j<TAM2;j++){
                embarc1[i][j]=0;
                jogo1[i][j]='~';
            }
        }
        do{
            i=rand()%TAM2-2;
            j=rand()%TAM2-2;
            if((embarc1[i][j]==0)&&(embarc1[i][j]!=1)&&(embarc1[i][j+1]!=1)&&(i>0)&&(j>0)){
                embarc1[i][j]++;
                embarc1[i][j+1]++;
                cruzadores++;
            }
        }while(cruzadores<4);

        do{
            i=rand()%TAM2-2;
            j=rand()%TAM2-2;
            if((embarc1[i][j]==0)&&(embarc1[i][j]!=1)&&(embarc1[i-1][j+1]!=1)&&(embarc1[i][j+2]!=1)&&(embarc1[i][j]!=2)&&(embarc1[i-1][j+1]!=2)&&(embarc1[i][j+2]!=2)&&(i>0)&&(j>0)){
                embarc1[i][j]++;
                embarc1[i-1][j+1]++;
                embarc1[i][j+2]++;
                embarc1[i][j]++;
                embarc1[i-1][j+1]++;
                embarc1[i][j+2]++;
                hidro++;
            }

        }while(hidro<4);
        printf("   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15");
        for(i=0;i<TAM2;i++){
            printf("\n%c ",letra);
            letra++;
            for(j=0;j<TAM2;j++){
                printf(" %c ",jogo1[i][j]);
            }
        }

        do{
            printf("\nDigite a coordenada\n");
            fflush(stdin);
            scanf("%c",&a);
            scanf("%d",&b);
            if ((a == 'A') || (a == 'a')){
                j=0;
            }
            if ((a == 'B') || (a == 'b')){
                j=1;
            }
            if ((a == 'C') || (a == 'c')){
                j=2;
            }
            if ((a == 'D') || (a == 'd')){
                j=3;
            }
            if ((a == 'E') || (a == 'e')){
                j=4;
            }
            if ((a == 'F') || (a == 'f')){
                j=5;
            }
            if ((a == 'G') || (a == 'g')){
                j=6;
            }
            if ((a == 'H') || (a == 'h')){
                j=7;
            }
            if ((a == 'I') || (a == 'i')){
                j=8;
            }
            if ((a == 'J') || (a == 'j')){
                j=9;
            }
            if ((a == 'K') || (a == 'k')){
                j=10;
            }
            if ((a == 'L') || (a == 'l')){
                j=11;
            }
            if ((a == 'M') || (a == 'm')){
                j=12;
            }
            if ((a == 'N') || (a == 'n')){
                j=13;
            }
            if ((a == 'O') || (a == 'o')){
                j=14;
            }
            b--;
            if((j>=0)||(j<15)&&(b>=0)||(b>15)){
                if(jogo1[j][b]!='~'){
                    cond=2;
                }
                if (embarc1[j][b] == 1){
                    jogo1[j][b] = 'C';
                    acertos++;
                    jogadas++;
                    cond=0;
                }
                if(embarc1[j][b]==2){
                    jogo1[j][b] = 'H';
                    acertos++;
                    jogadas++;
                    cond=0;
                }
                if(embarc1[j][b]==0){
                    jogo1[j][b]='*';
                    jogadas++;
                    cond=1;
                }
                }
            }
            else{
                cond=3;
            }
            system("cls");
            letra=65;
            printf("    1  2  3  4  5  6  7  8  9  10 11 12 13 14 15");
            for(i=0;i<TAM2;i++){
                printf("\n %c ",letra);
                letra++;
                for(j=0;j<TAM2;j++){
                    printf(" %c ",jogo1[i][j]);
                }
            }
            if (cond == 0){
                printf("\nVocê acertou\n");
            }
            if (cond==1){
                printf("\nNão há nenhum barco nessa posição\n");
            }
            if(cond==2){
                printf("\nVocê já jogou nessa posição");
            }
            if(cond==3){
                printf("\nCoordenada Inválida\n");
            }

        }while(acertos != 20);
            printf("Você completou o jogo com %d jogadas",jogadas);
    }
    else{
        printf("Dificuldade inválida");
    }
    return 0;
}
