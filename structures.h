#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

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

#endif // STRUCTURES_H_INCLUDED
