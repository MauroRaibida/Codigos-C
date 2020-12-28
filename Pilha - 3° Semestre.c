#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void imprime(Pilha *p){
    int i;
    printf("\n\nEsta é a pilha:");
    for (i = p->topo-1; i>=0;i--){
        printf("%d ",p->item[i]);
    }
    printf("\n\n");
}

int main()
{
    int opc,x,y;
    Pilha p;
    iniPilha(&p);
    do{
        printf("1-Inserir item na pilha\n2-Remover item da pilha\n3-Listar dados da pilha\n4-Sair\nDigite a opção:");
        do{
            scanf("%d",&opc);
            if((opc<=0)||(opc>4)){
                printf("Opcao invalida\n");
            }
        }while((opc<=0)||(opc>4));

        if (opc==1){
        	printf("\nDigite o numero a ser inserido: ");
            scanf("%d",&x);
            y=push(&p,x);
            if(y==-1){
            	printf("\nA pilha esta cheia\n\n");
            }
            else{
            	printf("\nO numero foi inserido\n\n");
            }
        }
        else{
            if(opc==2){
	            y=pop(&p);
	            if(y==-2){
	            	printf("\nA pilha esta vazia\n\n");
	            }
	            else{
	            	printf("\nO numero foi removido\n\n");
	            }
            }
            else{
                if (opc==3){
                    imprime(&p);
                }
            }

        }

    }while(opc!=4);
}
