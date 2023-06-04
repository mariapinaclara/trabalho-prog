#include "cadastro.h"
#include "deposito.h"
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int loginsuc, v[60], quit;
double saldo, deposit, saque, valor;
long int password, confsenha, redsenha[8];

void cadastro(int s[60]) {
  char nome[60], strpassword[60];
  int login, confpassword, sizepassw, try, choose;
  long int numgerente;
  double renda;
  try = 3;
  numgerente = 61998007307;

  system("clear||cls");

  printf("Bem vindo\n");
  printf("Wu Dingchang\n");

  printf("Escreva o seu nome a seguir: \n");
  login = user_name(nome);
  printf("Digite a sua renda mensal: \n");
  renda = income(renda);
  printf("Define a sua senha:\n");
  scanf("%ld", &password);

  sprintf(strpassword, "%ld", password);
  sizepassw = strlen(strpassword);

  while (sizepassw < 8) {
    printf("A senha deve ter pelo menos 8 caracteres\n");
    printf("Digite-a novamente: ");
    scanf("%ld", &password);
    sprintf(strpassword, "%ld", password);
    sizepassw = strlen(strpassword);
  }
  printf("Confirme sua senha\n");
  scanf("%d", &confpassword);
  if (confpassword != password) {
    while (try > 0 && confpassword != password) {
      printf("senha errada, tente novamente.\n");
      printf("%d tentativas restantes\n", try);
      scanf("%d", &confpassword);
      try--;
    }
    if (try <= 0) {
      printf("entre em contato com o gerente %ld\n", numgerente);
    }
  }
  if (confpassword == password) {
    printf("cadastro pronto\n");
    loginsuc = 1;
  }
}
void menu_opcoes(int s[60]) {
  long int numconta;
  int choices;
  double add;

  printf("\n\n -----------------------");
  printf("Escolha uma opção:\n");
  printf("\n");
  printf("1 - Saldo\n");
  printf("2 - Deposito\n");
  printf("3 - Sacar\n");
  printf("4 - Transferencia\n");
  printf("5 - Redefinir senha\n");
  printf("6 - Sair\n");
  printf("\n");
  scanf("%d", &choices);

  switch (choices) {
  case 1:
    printf("Saldo\n\n");
    printf("Deseja retirar o extrato ou proseguir pro saldo simples? \n");
    printf("1 - saldo simples\n2 - extrato\n");
    int choose;
    scanf("%d", &choose);
    if (choose == 1) {
      system("clear||cls");
      printf("o seu saldo atual é de %.2lf\n", saldo);
      menu_opcoes(v);

    } else if (choose == 2) {
      system("clear||cls");
      printf("depois eu vejo isso mó preguiça mas é pra ter o extrato viu.\n");
      menu_opcoes(v);

    } else {
      system("clear||cls");
      menu_opcoes(v);
    }
    break;

  case 2:
    printf("Deposito\n\n");
    printf("Digite o valor de deposito\n");
    scanf("%lf", &deposit);
    saldo = saldo + deposit;
    system("clear||cls");
    menu_opcoes(v);
    break;

  case 3:
    printf("Quanta você deseja sacar? \n");
    scanf("%lf", &saque);
    if (saque > saldo) {
      system("clear||cls");
      printf("você não tem saldo o suficiente para este saque\n");
      menu_opcoes(v);
    } else {
      saldo = saldo - saque;
      system("clear||cls");
      printf("saque concluido com sucesso\n");
      printf("o saldo atual é de %.2lf\n", saldo);
      menu_opcoes(v);
    }
    break;

  case 4:
    printf("\nNumero da Conta de Transferência: ");
    scanf("%ld", &numconta);
    printf("\n Informe o valor para transferência: ");
    scanf("%lf", &valor);
    printf("Digite a sua senha\n");
    scanf("%ld", &confsenha);
    if (confsenha == password) {
      saldo = saldo - valor;
      system("clear||cls");
      printf("Transferencia efetuada com sucesso\n");
      printf("saldo atual de:%.2f", saldo);
      menu_opcoes(v);
    }
    else{
        system("clear||cls");
        printf("senha incorreta, retornando ao menu de opções\n");
        menu_opcoes(v);
      }
    break;

  case 5:
    printf("5 - Redefinir senha.\n");
    if (password == redsenha){
      printf("A senha redefinida não pode ser igual a antiga.\n");
      scanf("%ld", &redsenha);
    }
    else {
      printf("Senha redefinida.\n");
      }  
    break;
  case 6:
    printf("até a proxima\n");
    quit = 1;
    break;
  }
}
int main() {
  int start;
  printf("Bem vindo ao banco\n");
  printf("1 - cadastro\n2 - login\n");
  cadastro(v);
  if (loginsuc == 1) {
    menu_opcoes(v);
  }
  if (quit == 1) {
    return 0;
  }
}
