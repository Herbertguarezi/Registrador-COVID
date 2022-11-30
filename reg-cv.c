#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>
#include <time.h>
#include "structures.h"
#include "colors.h"
#include "crt-files.h"

//fun�oes usadas no programa


void menu(){
  int contador = 1;
  while (contador != 0){
    printf("Cadastrar paciente[1]\n");
    printf("Sair[0]\n");
    scanf("%d", &contador);
    fflush (stdin);
    if (contador == 1){
      printf("Digite o nome do paciente: ");
      fgets((*prtPaciente).nome, 50, stdin);

      printf("Digite o CPF do paciente: ");
      fgets((*prtPaciente).cpf, 20, stdin);

      printf("Digite o telefone do paciente (xx)xxxxx-xxxx: ");
      fgets((*prtPaciente).telefone, 15, stdin);
      fflush(stdin);

      printf("\n=======================================\n");
      printf("Digite o endere�o do paciente: ");
      printf("Rua: ");
      fgets((*prtPaciente).endereco.rua, 100, stdin);
      printf("N�mero: ");
      fgets((*prtPaciente).endereco.numero, 100, stdin);
      printf("Bairro: ");
      fgets((*prtPaciente).endereco.bairro, 100, stdin);
      printf("Cidade: ");
      fgets((*prtPaciente).endereco.cidade, 100, stdin);
      printf("Estado: ");
      fgets((*prtPaciente).endereco.estado, 100, stdin);
      printf("CEP: ");
      fgets((*prtPaciente).endereco.cep, 100, stdin);
      printf("\n=======================================\n");

      printf("Digite a data de nascimento do paciente (dd/mm/aaaa): ");
      fgets((*prtPaciente).nascimento, 11, stdin);

      printf("Digite a idade do paciente: ");
      scanf("%d", &(*prtPaciente).idade);
      fflush(stdin);

      printf("Digite o email do paciente: ");
      fgets((*prtPaciente).email, 50, stdin);

      printf("O paciente possui alguma comorbidade ?[s]/[n] ");
      fgets((*prtPaciente).comorbidades, 100, stdin);
      if(strcmp((*prtPaciente).comorbidades, "s") == 1){
        printf("Digite quais ele possui(diabetes, obesidade, hipertens�o,tuberculose, outros): ");
        fgets((*prtPaciente).comorbidades, 100, stdin);
        criaArquivo();
        printf("\n");
      }
      else{
        criaArquivo();
        printf("\n");
      }

      if ((*prtPaciente).idade >= 65){
        corVermelha();
        printf("\n!!!!!!ATEN��O o paciente pertence ao grupo de risco!!!!!!\n\n");
        corPadrao();
        Sleep(1000);
        for (int i = 0; i < 2; i++) {
          printf("Enviando dados para a Secretaria de Sa�de!");
          for (int j = 0; j < 10; j++) {
              printf(".");
              Sleep(50);
          }
          printf("\r");
          for (int j = 0; j < 60; j++) {
              printf(" "); // apaga a linha anterior
          }
          printf("\r");
        }
        criaArquivoSecretaria();
        Sleep(500);
  }
    }

  }
  printf("\n====================================\n");
  printf("At� a pr�xima!\n");
  printf("====================================\n");
  system ("PAUSE");
}
////////////////////////////


//Fun�ao principal
int main(){
  // definindo localiza��o para aceitar acentos
  setlocale(LC_ALL, "Portuguese_Brazil");
  /////////////////////////////////////////////

  //declara��o de usu�rios no sistema //
  Admin.password = 150503;

  User.password = 123456;

  //////////////////////////////////////////

  char id[10];
  int password;
  int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

  corAmarelo();
  printf("====================================\n");
  printf("Bem vindo ao cadastro de pacientes !\n");
  printf("====================================\n\n");
  corPadrao();

  while(!login_efetuado){
    printf("Digite seu usu�rio: \n");
    fgets(id, 10, stdin);

    printf("Digite sua senha: \n");
    scanf("%d", &password);
    fflush(stdin);

     for (int i = 0; i < 2; i++) {
        printf("Verificando credenciais");
        for (int j = 0; j < 20; j++) {
            printf(".");
            Sleep(50);
        }
        printf("\r");
       for (int j = 0; j < 60; j++) {
           printf(" "); // apaga a linha anterior
       }
      printf("\r");
    }



    if (strcmp(&id, "admin") == 0 || password == Admin.password){
        corVerde();
        printf("\n\nLogado como administrador\n\n");
        login_efetuado = 1;
        corPadrao();
      }
    else if (strcmp(&id, "user") == 0 || password == User.password){
        corVerde();
        printf("\n\nLogado como us�rio padr�o\n\n");
        login_efetuado = 1;
        corPadrao();
      }
    else{
        corVermelha();
        printf("\n===USU�RIO NAO ENCONTRADO===\n");
        printf("Tente novamente!\n\n");
        Sleep(2000);
        corPadrao();
    }
  }
  printf("====================================\n");
  printf("O que deseja fazer ?\n");
  menu();
}
/////////////////////////////////////////////////
