#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int Prioridade(char c, char t);

void InfPosf(char EX[]){
  Pilha p;
  int i = 0;
  char c,t;

  iniPilha(&p); //inicia a pilha
  push(&p, '('); //insere ' na pilha para metodo de parada

  do{
    c = EX[i]; //c recebe primeira posi��o da pilha
    i++; //c icremetado para a pr�xima leitura de DO
    if(c >= 'a' && c <= 'z'){ //ao encontrar uma vari�vel char a mesma � impressa
      printf("%c", c);
    }
    else if(c == '('){  //se na posi��o definida haver ( o mesmo � inserido na pilha de operandos
      push(&p, '(');
    }
    else if(c == ')' || c == '\0'){ //se na posi��o definida houver um final de parenteses ou string
      do{
        t = pop(&p);
        if(t != '(') //como parenteses possui prioridade maior, os operadores ser�o impressos com prioridade
          printf("%c", t);
      }while(t != '(');
    }
    else if(c == '+' || c == '-' || c == '*' || c == '/' ||c == '^' ){
      while(1){
        t = pop(&p); //recebemos os operadores da pilha e checamos sua prioridade para a impress�o
        if(Prioridade(c,t)==1){ //se a prioridade do operador da string for maior que a prioridade do operador da pilha
          push(&p, t);
          push(&p, c);
          break;
        }
        else{
          printf("%c", t);
        }
      }
    }
  }while(c != '\0'); //ao encontrar o final de string, a fun��o n�o � mais executada
  printf("\n");
}


int Prioridade(char c, char t){
  int pc,pt;

  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 5;

  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;
 if(pc>pt){
  return 1;
 }
 else{
  return 0;
 }
}

int main(){
  char EX[100];
  printf("Digite a express�o a ser convertida: ");
  scanf("%s", EX);
  InfPosf(EX);
  return 0;
}
