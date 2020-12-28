#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct no{
    int info;
    struct no *Llink;
    struct no *Rlink;
    struct no *Dlink;
    enum {PRETO, VERMELHO} color;
}no;

#define NIL &sentinela         
no sentinela = { 0, NIL, NIL, 0, 0};


void iniarvore(no **T){
	*T = NIL;
}

int max(int a, int b){
    if(a > b){
    	return a;
    }else{
    	return b;
    }
}

no *menor(no *T){
	if((T) == NIL || (T)==NULL){
		return T;
	}
	if((T)->Llink == NULL){
		return (T)->Llink;
	}
	menor(T->Llink);
}


no *transplante(no **T, no *u, no *v){
	if(u->Dlink == NIL){
		(*T) = v;
	}else if(u == (u->Dlink)->Llink){
		(u->Dlink)->Llink = v;
	}
	else{
		(u->Dlink)->Rlink = v;
	}
	v->Dlink = u->Dlink;
}


no *rotRight(no **T, no *p) {
  assert(*T != NIL || p->Llink != NIL);
  no *q, *temp;

  q = p->Llink;
  temp = q->Rlink;
  q->Rlink = p;
  p->Llink = temp;

  transplante(T, p, q);

  if (p != NIL)
    p->Dlink = q;
  if (p == *T)
    *T = q;
}

no *rotLeft(no **T, no *p) {
  assert(*T != NIL || p->Rlink != NIL);
  no *q, *temp;

  q = p->Rlink;
  temp = q->Llink;
  q->Llink = p;
  p->Rlink = temp;

  transplante(T, p, q);

  if (p != NIL)
    p->Dlink = q;
  if (p == *T)
    *T = q;
}

void imprimeOrd(no *T){

	if(T!= NULL){
		imprimeOrd(T->Llink);
		printf("%d ", T->info);
		imprimeOrd(T->Rlink);
	}
}

void imprimePre(no *T) {
  
  if(T != NULL) {
    printf("%d ", T->info);
    imprimePre(T->Llink);
    imprimePre(T->Rlink);
  }
}

void imprimePos(no *T) {
  
  if(T != NULL) {
    imprimePos(T->Llink);
    imprimePos(T->Rlink);
    printf("%d ", T->info);
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

int drawtree(no **T){
	no *N;
	N = (*T);

	if((*T)==NULL){
		return -1;
	}
	if((*T)->Llink != NULL){
		FILE *f = fopen("arvore.txt", "a");	
		N = (*T)->Llink;
		fprintf(f, "%d -> %d\n", (*T)->info, (N)->info);
		fclose(f);
	}
	if((*T)->Rlink != NULL){
		FILE *f = fopen("arvore.txt", "a");	
		N = (*T)->Rlink;
		fprintf(f, "%d -> %d\n", (*T)->info, (N)->info);
		fclose(f);
	}
	drawtree(&(*T)->Rlink);
	drawtree(&(*T)->Llink);
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

no *fix(no **T, no *z){
	no *y;
	while((z->Dlink)->color == 1){
		if(z->Dlink == (((z->Dlink)->Dlink)->Llink)){
			y = ((z->Dlink)->Dlink)->Rlink;
			if(y->color == 1){//Tio vermelho
				z->Dlink->color = 0;
				y->color = 0;
				((z->Dlink)->Dlink)->color = 1;
				z = (z->Dlink)->Dlink;
			}else{
				if(z == (z->Dlink)->Rlink){
					z = z->Dlink;
					rotLeft(T, z);
				}
				z->Dlink->color = 0;
				((z->Dlink)->Dlink)->color = 1;
				rotRight(T, ((z->Dlink)->Dlink)); 
			}
		}
		else{
			y = ((z->Dlink)->Dlink)->Llink;
			if(y->color == 1){//Tio vermelho
				z->Dlink->color = 0;
				y->color = 0;
				((z->Dlink)->Dlink)->color = 1;
				z = (z->Dlink)->Dlink;
			}else{
				if(z == (z->Dlink)->Llink){
					z = z->Dlink;
					rotRight(T, z);
				}
				(z->Dlink)->color = 0;
				((z->Dlink)->Dlink)->color = 1;
				rotLeft(T, ((z->Dlink)->Dlink)); 
			}
		}
	}
	(*T)->color = 0;
}

no *insere(no **T, int n){
	no *y = NIL;
	no *x = *T;
	no* z  = (no *) malloc(sizeof(no));
	z->info = n;

	while(x != NIL){
		y=x;
		if(z->info < x->info){
			x = x->Llink;
		}else{
			x = x->Rlink;
		}
	}
	z->Dlink = y;
	if(y == NIL){
		*T = z;
	}else if(z->info < y->info){
		y->Llink = z;
	}else{
		y->Rlink = z;
	}
	z->Llink = NIL;
	z->Rlink = NIL;
	z->color = 1;
	fix(&*T, z);
}

no *consertaRB(no **T, no *x){
	no *w;
	while(x != (*T) && x->color == 0){
		if(x == (x->Dlink)->Llink){
			w = (x->Dlink)->Rlink;
			if(w->color = 1){
				w->color = 0;
				(x->Dlink)->color = 1;
				rotLeft(T, x->Dlink);
				w = (x->Dlink)->Rlink;
			}
			if((w->Llink)->color == 0 && (w->Rlink)->color == 0){
				w->color = 1;
				x = x->Dlink;
			}else{
				if((w->Rlink)->color==0){
					(w->Llink)->color = 0;
					w->color = 1;
					rotRight(T, w);
					w = (x->Dlink)->Rlink;
				}
				w->color = x->Dlink->color;
				(x->Dlink)->color = 0;
				(w->Rlink)->color = 0;
				rotLeft(T, x->Dlink);
				x = (*T);
			}
		}
		else{
			w = (x->Dlink)->Llink;
			if(w->color = 1){
				w->color = 0;
				(x->Dlink)->color = 1;
				rotRight(T, x->Dlink);
				w = (x->Dlink)->Llink;
			}
			if((w->Rlink)->color == 0 && (w->Llink)->color == 0){
				w->color = 1;
				x = x->Dlink;
			}else{
				if((w->Llink)->color==0){
					(w->Rlink)->color = 0;
					w->color = 1;
					rotLeft(T, w);
					w = (x->Dlink)->Llink;
				}
				w->color = (x->Dlink)->color;
				x->Dlink->color = 0;
				w->Llink->color = 0;
				rotRight(T, x->Dlink);
				x = (*T);
			}
		}
	x->color = 0;
	}	
}



no *removeRB(no **T, no *z){
	no *x, *y = z;
	int corY = y->color;

	if(z->Llink == NIL){
		x = z->Rlink;
		transplante(T, z, z->Llink);
	}else{
		y = menor(z->Rlink);
		corY = y->color;
		x = y->Rlink;
		if(y->Dlink == z){
			x->Dlink = y;
		}else{
			transplante(T, y, y->Rlink);
			y->Rlink = z->Rlink;
			(y->Rlink)->Dlink = y; 
		}
		transplante(T, z, y);
		y->Llink = z->Llink;
		(y->Llink)->Dlink = y;
		y->color = z->color;
	}
	if(corY == 0){
		consertaRB(T, x);
	}
}