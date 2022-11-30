#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>
#include <time.h>

//estruturas de dados presentes no programa
struct usuario
{
  int password;
}Admin, User;

typedef struct{
  char rua[50];
  char numero[5];
  char bairro[50];
  char cidade[50];
  char estado[50];
  char cep[20];
}Endereco;


typedef struct{
  Endereco endereco;
  char nome[50];
  char cpf[20];
  char telefone[15];
  int idade;
  char nascimento[11];
  char email[100];
  char comorbidades[150];
}Paciente;



Paciente paciente_1;

Paciente *prtPaciente = &paciente_1;
///////////////////////////////////////////

//funçoes usadas no programa
void corVerde(){
  printf("\033[0;32m");
}

void corVermelha(){
  printf("\033[0;31m");
}

void corPadrao(){
  printf("\033[0m");
}

void criaArquivo(){
  FILE *pontArq;
  pontArq = fopen("./Informações Paciente", "w");

  fputs("Informaçoes do Paciente\n", pontArq);
  fputs("Nome: ", pontArq);
  fprintf(pontArq, "%s", (*prtPaciente).nome);

  fputs("CPF: ", pontArq);
  fprintf(pontArq, "%s", (*prtPaciente).cpf);

  fputs("Telefone: ", pontArq);
  fprintf(pontArq, "%s", (*prtPaciente).telefone);

  //fputs("Endereco: ", pontArq);
  //fprintf(pontArq, "%s", (*prtPaciente).endereco.cidade);

  fputs("Email: ", pontArq);
  fprintf(pontArq, "%s", (*prtPaciente).email);

  fputs("Comorbidades: ", pontArq);
  fprintf(pontArq, "%s", (*prtPaciente).comorbidades);

  fclose(pontArq);
}

void criaArquivoSecretaria(){
  FILE *pontArq;
  pontArq = fopen("./Informações Paciente - Secretaria de Saúde", "w");

  fputs("Informaçoes do Paciente\n\n", pontArq);
  fputs("CEP: ", pontArq);
  fprintf(pontArq, "%s", (*prtPaciente).endereco.cep);

   fputs("Idade: ", pontArq);
  fprintf(pontArq, "%s", (*prtPaciente).idade);
}

void menu(){
  int contador = 1;
  while (contador != 0){
    printf("Cadastrar usuário[1]\n");
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
      printf("Digite o endereço do paciente: ");
      printf("Rua: ");
      fgets((*prtPaciente).endereco.rua, 100, stdin);
      printf("Número: ");
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
        printf("Digite quais ele possui(diabetes, obesidade, hipertensão,tuberculose, outros): ");
        fgets((*prtPaciente).comorbidades, 100, stdin);
        criaArquivo();
        printf("\n");
      }
      else{
        criaArquivo();
        printf("\n");
      }

      if ((*prtPaciente).idade >= 65){
    printf("\n!!!!!!ATENÇÃO o paciente pertenvce ao grupo de risco!!!!!!");
    for (int i = 0; i < 2; i++) {
      printf("Enviando dados para a Secretaria de Saúde!");
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
  }
    }

  }
  printf("\n====================================\n");
  printf("Até a próxima!\n");
  printf("====================================\n");
}

//void cadastra_paciente{
//  char pacientes;
//}

////////////////////////////


//Funçao principal
int main(){
  // definindo localização para aceitar acentos
  setlocale(LC_ALL, "Portuguese_Brazil");
  /////////////////////////////////////////////

  //declaração de usuários no sistema //
  Admin.password = 150503;

  User.password = 123456;

  //////////////////////////////////////////

  char id[10];
  int password;
  int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

  printf("====================================\n");
  printf("Bem vindo ao cadastro de pacientes !\n");
  printf("====================================\n");

  while(!login_efetuado){
    printf("Digite seu usuário: \n");
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
        printf("\n\nLogado como administrador\n");
        login_efetuado = 1;
        corPadrao();
      }
      else if (strcmp(&id, "user") == 0|| password == User.password){
        corVerde();
        printf("\n\nLogado como usário padrão\n");
        corPadrao();
      }
      else
        corVermelha();
        printf("\n===USUÁRIO NAO ENCONTRADO===\n");
        Sleep(2000);
        corPadrao();
  }
  printf("====================================\n");
  printf("O que deseja fazer ?\n");
  menu();
}
/////////////////////////////////////////////////
