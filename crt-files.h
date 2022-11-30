#ifndef CRT-FILES_H_INCLUDED
#define CRT-FILES_H_INCLUDED

void criaArquivo(){
    FILE *pontArq;
    pontArq = fopen("./informacoes/Informa��es Paciente", "a");

    fputs("Informa�oes do Paciente\n", pontArq);
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
    fputs("\n\n", pontArq);

    fclose(pontArq);
}

void criaArquivoSecretaria(){
    FILE *pontArqSec;
    pontArqSec = fopen("./informacoes/Informa��es Paciente - Secretaria de Sa�de", "a");

    fputs("Informa�oes do Paciente\n\n", pontArqSec);
    fputs("CEP: ", pontArqSec);
    fprintf(pontArqSec, "%s", (*prtPaciente).endereco.cep);

    fputs("Idade: ", pontArqSec);
    fprintf(pontArqSec, "%d", (*prtPaciente).idade);
    fputs("\n", pontArqSec);

    fclose(pontArqSec);
}

#endif // CRT-FILES_H_INCLUDED
