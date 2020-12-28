#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

int Prioridade(char c, char t);

void InfPosf(char EX[]){
  Pilha p;
  int i = 0;
  char c,t;

  iniPilha(&p); //inicia a pilha
  push(&p, '('); //insere ' na pilha para metodo de parada

  do{
    c = EX[i]; //c recebe primeira posição da pilha
    i++; //c icremetado para a próxima leitura de DO
    if(c >= 'a' && c <= 'z'){ //ao encontrar uma variável char a mesma é impressa
      printf("%c", c);
    }
    else if(c == '('){  //se na posição definida haver ( o mesmo é inserido na pilha de operandos
      push(&p, '(');
    }
    else if(c == ')' || c == '\0'){ //se na posição definida houver um final de parenteses ou string
      do{
        t = pop(&p);
        if(t != '(') //como parenteses possui prioridade maior, os operadores serão impressos com prioridade
          printf("%c", t);
      }while(t != '(');
    }
    else if(c == '+' || c == '-' || c == '*' || c == '/' ||c == '^' ){
      while(1){
        t = pop(&p); //recebemos os operadores da pilha e checamos sua prioridade para a impressão
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
  }while(c != '\0'); //ao encontrar o final de string, a função não é mais executada
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
  printf("Digite a expressão a ser convertida: ");
  scanf("%s", EX);
  InfPosf(EX);
  return 0;
}
