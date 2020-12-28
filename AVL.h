#include <stdio.h>
#include <stdlib.h>

typedef struct Treeno{
	int info, altura;
	struct Treeno *Llink;
	struct Treeno *Rlink;
}no;


void iniarvore(no **T){
	*T = NULL;
}


int max(int a, int b){
    if(a > b){
    	return a;
    }else{
    	return b;
    }
}


int altura(no *T){
	int dir = 0, esq = 0;
  if (T->Rlink != NULL)
    dir = (T->Rlink)->altura;
  
  if (T->Llink != NULL)
    esq = (T->Llink)->altura;
  
  return max(esq, dir) + 1;
}

int bal(no *T){
int dir = 0, esq = 0;
  if (T->Rlink != NULL)
    dir = (T->Rlink)->altura;

  if (T->Llink != NULL)
    esq = (T->Llink)->altura;

  return dir - esq;
}

void rotLeft(no **T) {
  
  no *q, *p, *temp;

  p = *T;
  q = p->Rlink;
  temp = q->Llink;
  q->Llink = p;
  p->Rlink = temp;

  p->altura = altura(p);
  q->altura = altura(q);

  *T = q;
}


void rotRight(no **T) {
   no *q, *p, *temp;
  p = *T;

  q = p->Llink;
  temp = q->Rlink;

  q->Rlink = p;
  p->Llink = temp;

  p->altura = altura(p);
  q->altura = altura(q);

  *T = q;
}


int insere(no **T, int item){
    int balance=0, balanson=0;
    no *N;

    if ((*T) == NULL){
        N = (no *) malloc(sizeof(no));
        (N)->info =  item;
		(N)->Llink = NULL;
		(N)->Rlink = NULL;
		(N)->altura = 1;
		(*T) = N;
 	}else if( item < ((*T)->info)){
	    insere(&((*T)->Llink), item);
	}else if( item >= ((*T)->info) ){
	    insere(&((*T)->Rlink),item);
	}

	(*T)->altura = altura(*T);
 	balance = bal(*T);
    if (balance == 2){
    	balanson = bal((*T)->Rlink);
    	if(balanson==1){
    		rotLeft(&(*T));
    	}else{
    		rotRight(&(*T)->Rlink);
    		rotLeft(&(*T));
    	}	
    }else if(balance == -2){
    	balanson = bal((*T)->Llink);
    	if(balanson == -1){
    		rotRight(&(*T));
    	}else{
    		rotLeft(&(*T)->Llink);
    		rotRight(&(*T));
    	}
    }
    return 1;
}

void imprimeOrd(no **T){

	if((*T)!= NULL){
		imprimeOrd(&(*T)->Llink);
		printf("%d ", (*T)->info);
		imprimeOrd(&(*T)->Rlink);
	}
}

void imprimePre(no **T) {
  
  if((*T) != NULL) {
    printf("%d ", (*T)->info);
    imprimePre(&(*T)->Llink);
    imprimePre(&(*T)->Rlink);
  }
}

void imprimePos(no **T) {
  
  if((*T) != NULL) {
    imprimePos(&(*T)->Llink);
    imprimePos(&(*T)->Rlink);
    printf("%d ", (*T)->info);
  }
}

int percorretree(no **T, int item){
	if(*T==NULL){
		puts("O valor nao foi encontrado na arvore");
		system("pause");
		system("cls");
		return 0;
	}
	if(item == (*T)->info){
		printf("O valor %d foi encontrado na arvore\n", item);
		system("pause");
		system("cls");
		return 1;
	}else{
		if(item < (*T)->info){
			percorretree(&(*T)->Llink, item);
		}else{
			if(item > (*T)->info){
				percorretree(&(*T)->Rlink, item);
			}
		}
	}
}


int end(no **T){
	if((*T) != NULL){
		end(&(*T)->Llink);
		end(&(*T)->Rlink);	
	}
	free(*T);
	(*T) = NULL;
}

no *achamaior(no **T){
	
	if((*T)->Rlink == NULL){		
		printf("O maior valor eh %d\n", (*T)->info);
		return *T;
	} else {
		achamaior(&(*T)->Rlink);
	}
	
	return NULL;
}

int achamenor(no **T, int menor){
	if((*T)==NULL){
		printf("O menor valor e: %d\n", menor);
		system("pause");
		return menor;
	}else{
		if((*T)->info <= menor){
			menor = (*T)->info;
			achamenor(&(*T)->Llink, menor);
		}
	}
}

int removeavl(no **T, int item){
  no *p, *aux;
  if (*T == NULL){
    return 0;
  }
  else{
    if (item < (*T)->info){
      removeavl(&(*T)->Llink, item);
    }
    else if(item > (*T)->info){
      removeavl(&(*T)->Rlink, item);
    }
    else {
      if(((*T)->Llink == NULL) && ((*T)->Rlink == NULL)){ // no folha
        p = (*T);
        free (p);
        (*T) = NULL;
        return 1;
      }
      else if ((*T)->Llink == NULL){ // so tem no a direita
        p = (*T); // guarda aposicao
        (*T) = (*T)->Rlink; // aponta para o no filho colocando ele no lugar do que sera apagado
        free(p); // libera o elemento
      }
      else if ((*T)->Rlink == NULL){ // so tem o no da esquerda
        p = (*T); // guarda a posicao
        (*T) = (*T)->Llink; //aponta para o no filho colocando ele no lugar do que sera apagado
        free (p);
      }
      else{// tem dois filhos
        p = achamaior(&(*T)->Llink); //pega o maior do lado esquerdo (que é menor lado)
        (*T)->info = p->info;  //guarda o que tinha no p no endereço que tava o que ia ser apagado
        removeavl(&((*T)->Llink),p->info); // remove o no que tava guardando a informaçao do que agora ta no p
      }
    }
   } 

   (*T)->altura = altura(*T);
   int balance, balanson;
    balance = bal(*T);
    if (balance == 2){
    	balanson = bal((*T)->Rlink);
    	if(balanson==1){
    		rotLeft(&(*T));
    	}else{
    		rotRight(&(*T)->Rlink);
    		rotLeft(&(*T));
    	}	
    }else if(balance == -2){
    	balanson = bal((*T)->Llink);
    	if(balanson == -1){
    		rotRight(&(*T));
    	}else{
    		rotLeft(&(*T)->Llink);
    		rotRight(&(*T));
    	}
    }
    return 1;
}