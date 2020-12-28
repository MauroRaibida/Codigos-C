#define MAX 5
#define ERROPILHACHEIA -1
#define ERROPILHAVAZIA -2

typedef struct{
    int item[MAX];
    int topo;
}Pilha;

void iniPilha(Pilha *p){
    p->topo=0;
}

int cheiaPilha (Pilha *p){
    if (p->topo==MAX){
        return 1;
    }
    else
        return 0;
}

int vaziaPilha(Pilha *p){
    if(p->topo==0){
        return 1;
    }
    else
        return 0;
}

int push(Pilha *p, int x){
    if(cheiaPilha(p)==1){
        return(ERROPILHACHEIA);
    }
    else{
        p->item[p->topo]=x;
        p->topo++;
        return(p->topo);
    }
}

int pop (Pilha *p){
    int x;
    if(vaziaPilha(p)==1){
        return(ERROPILHAVAZIA);
    }
    else{
        p->topo--;
        x=p->item[p->topo];
        return(x);
    }
}