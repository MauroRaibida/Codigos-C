#include <stdio.h>
#include <stdlib.h>

void mostra(int *vet, int n, int ord);
void buble(int *vet, int n);
void selection(int *vet, int n);
void insertion(int *vet, int n);
int busca_sequencial(int *vet, int n, int num);
int busca_binaria(int *vet, int n, int num);

int main()
{
    int *vet,n,i,num_proc,met,ord,busca;
    //scan numero de elementos do vetor
    printf("Digite o numero de elementos do vetor:");
    scanf("%d",&n);

    //alocação dinamica de memoria
    vet=malloc(n*sizeof(int));
    if(vet==NULL){
        printf("Memoria Insuficiente");
        exit(1);
    }

    //scan dos elementos do vetor
    printf("\nEntre com os elementos do vetor:\n");
    for(i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }

    //Scan metodo de ordenação
    printf("\nSelecione o metodo de ordenacao desejado\n1 - Buble Sort\n2 - Selection Sort\n3 - Insertion Sort\n-> ");
    do{
        scanf("%d",&met);
        if((met<1)||(met>3)){
            printf("Metodo invalido, por favor selecione um metodo valido\n-> ");
        }
    } while((met<1)||(met>3));

    //Scan ordem
    printf("\nSelecione:\n1 - Crescente\n2 - Decrescente\n-> ");
    do{
        scanf("%d",&ord);
        if ((ord<1)||(ord>2)){
            printf("Ordem invalida, por favor selecione uma ordem valido\n-> ");
        }
    }while((ord<1)||(ord>2));

    //Escolha da função
    if(met==1){
        buble(vet,n);
    }
    else{
        if(met==2){
            selection(vet,n);
        }
        else{
            if(met==3){
                insertion(vet,n);
            }
        }
    }

    mostra(vet,n,ord);
    printf("\n");

    //Scan do numero a ser procurado
    printf("\nDigite o numero a ser procurado:");
    scanf("%d",&num_proc);


    //Scan da busca
    printf("\nSelecione o metodo de busca desejado\n1 - Busca Sequencial\n2 - Busca Binaria\n-> ");
    do{
        scanf("%d",&busca);
        if ((busca<1)||(busca>2)){
            printf("Metodo de busca invalida, por favor selecione um metodo valido\n-> ");
        }
    }while ((busca<1)||(busca>2));


    //Escolha metodo de pesquisa
    if(busca==1){
        if(busca_sequencial(vet,n,num_proc)==1){
            printf("O numero %d se encontra no vetor",num_proc);
        }
        else{
            printf("O numero %d nao se encontra no vetor",num_proc);
        }
    }
    else{
        if(busca_binaria(vet,n,num_proc)==1){
            printf("O numero %d se encontra no vetor",num_proc);
        }
        else{
            printf("O numero %d nao se encontra no vetor",num_proc);
        }
    }
    printf("\n");
    free(vet);
    vet=NULL;
    return 0;
}

void buble(int *vet, int n)
{
    int i,j,aux;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            if(vet[j]>vet[j+1]){
                aux=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
            }
        }
    }
}

void selection(int *vet, int n)
{
    int i,j,min,aux;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(vet[j]<vet[min]){
                min=j;
            }
        }
        aux=vet[i];
        vet[i]=vet[min];
        vet[min]=aux;
    }
}

void insertion(int *vet, int n)
{
    int i,j,aux;
    for(i=1;i<n;i++){
        aux=vet[i];
        j=i-1;
        while((j>=0)&&(vet[j]>aux)){
            vet[j+1]=vet[j];
            j--;
        }
        vet[j+1]=aux;
    }
}

int busca_sequencial(int *vet, int n, int num)
{
    int i;
    for(i=0;i<n;i++){
        if(num == vet[i]){
            return 1;
        }
    }
    return 0;
}
int busca_binaria(int *vet, int n, int num)
{
      int i=0,f=n-1,m;
      do{
        m=(i+f)/2;
        if (num == vet[m]){
          return 1;
        }
        if (num < vet[m]){
          f = m-1;
        }
        else{
          i=m+1;
        }
      }while(i<=f);
  return 0;
}

void mostra(int *vet, int n, int ord)
{
    int i;
    printf("\nVetor ordenado:\n");
    //se a ordem for crescente
    if(ord==1){
        for(i=0;i<n;i++){
            printf("%d ",*(vet+i));
        }
    }
    //se a ordem for decrescente
    else{
        for(i=n-1;i>=0;i--){
            printf("%d ",*(vet+i));
        }
    }
}
