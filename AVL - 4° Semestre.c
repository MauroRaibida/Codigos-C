#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AVL.h"

int main(){
	int escolha, x, y=0;
	no *T;
    system("cls");
    puts("Arvore AVL");
    system("pause");
    system("cls");
    puts("Inicializar a Arvore?");
    puts("1.sim");
    scanf("%d", &escolha);
    if(escolha==1){
		iniarvore(&T);
	}
	system("cls");
	while(true){
        puts("2. Inserir");
        puts("3. Acha valor");
        puts("4. Acha menor valor");
        puts("5. Acha maior valor");
        puts("6. Remover valor");
        puts("7. Imprime Arvore");
        puts("8. Esvaziar arvore");
        puts("99. Sair");

        scanf("%d", &escolha);
        system("cls");
        if(escolha==2){
            puts("Digite o numero que deseja acrescentar: \n");
            scanf("%d", &x);
            insere(&T, x);
            system("cls");
        }
        
        if(escolha==3){
            puts("Digite o valor que deseja encontrar: \n");
            scanf("%d", &x);
            system("cls");
            percorretree(&T, x);
            system("cls");
        }
        if(escolha==4){
            system("cls");
            achamenor(&T, 9999);
            system("pause");
            system("cls");
        }
        if(escolha == 5){
            achamaior(&T);
            system("pause");
            system("cls");
        }
        if(escolha == 6){
           puts("Digite o valor que deseja remover: \n");
            scanf("%d", &x);
            system("cls");
            removeavl(&T, x);
         
        }
        if(escolha==7){
            system("cls");
            int choice=0;
            printf("Qual metodo deseja imprimir os valores?\n");
            puts("1. Em Ordem");
            puts("2. Pre Ordem");
            puts("3. Pos Ordem");
            scanf("%d", &choice);
            if(choice == 1){
                imprimeOrd(&T);
            }else if(choice == 2){
                imprimePre(&T);
            }else if(choice == 3){
                imprimePos(&T);
            }
            system("pause");
            system("cls");
            puts("\n");
        }
        if(escolha==8){
            end(&T);
            system("cls");
            puts("Arvore deletada.");
            y = 0;
            system("pause");
            system("cls");
        }
        if(escolha==99){
            return -1;
        }
    }
}

