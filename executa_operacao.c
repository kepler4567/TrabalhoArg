#include "Operacao/OperacaoBusca.c"
#include "Operacao/OperacaoInsercao.c"
#include "Operacao/operacaoRemocao.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeComando(char comando[], FILE *entrada)
{

<<<<<<< HEAD
=======
void LeComando(char comando[], FILE *entrada){
   
   
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f
    int i = 0;
    char c = fgetc(entrada);
    if (c != EOF)
    {
        while (c != '\n')
        {
            comando[i] = c;
            i++;
            c = fgetc(entrada);
        }
        comando[i] = '\0';
    }


}

int recebeChave(char comando[])
{
    char Key[7];
    int i, j = 2;
    for (i = 0; i < 6; i++)
    {
        Key[i] = comando[j];
        j++;
    }
    Key[j] = '\0';
    j = 2;
    return atoi(Key);
}

void leRegistro(char Registro[], char comando[])
{
    int i = 0;
    int j = 2;

    while (comando[i] != '\0')
    {
        Registro[i] = comando[j];
        i++;
        j++;
    }
<<<<<<< HEAD
    while (i <= 64)
=======
    while (i<=64)
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f
    {
        Registro[i] = '\0';
        i++;
    }
<<<<<<< HEAD
=======
    
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f
}

int executa_operacoes(char Arquivo[])
{

<<<<<<< HEAD
=======

int executa_operacoes(char Arquivo[]){


    
    
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f
    int chave;
    char key[7];
    FILE *entrada;
    FILE *DadosDat;
    char comando[67], opcao, registro[64];
<<<<<<< HEAD
=======

   
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f

    DadosDat = fopen("Dados.dat", "r");
    entrada = fopen(Arquivo, "r");

    while (!feof(entrada))
    {
<<<<<<< HEAD

=======
        
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f
        LeComando(comando, entrada);
        opcao = comando[0];

        if (opcao == 'b')
        {
            chave = recebeChave(comando);
<<<<<<< HEAD
            printf("Busca pelo registro de chave '%i'\n", chave);
            itoa(chave, key, 10);
            OperacaoBusca(key);
=======
            printf("Operacao de busca ativada na chave: %i\n", chave);
            OperacaoBusca(chave);
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f
        }
        else if (opcao == 'i')
        {
            leRegistro(registro, comando);
            printf("Insercao do registro de chave '%s'\n", registro);
            OperacaoInsercao(registro);
        }
        else if (opcao == 'r')
        {
            chave = recebeChave(comando);
<<<<<<< HEAD
            printf("Remocao do registro de chave '%i'\n", chave);
            itoa(chave, key, 10);
            OperacaoRemocao(key);
=======
            printf("Operacao de remocao ativada na chave: %i\n", chave);
            OperacaoRemocao(chave);
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f
        }
        else
        {
            fprintf(stderr, "Argumentos incorretos!\n");
            fprintf(stderr, "Modo de uso:\n");
            fprintf(stderr, "$ (chave|registro)\n");
            fprintf(stderr, "$ (b|i|r)");
            exit(EXIT_FAILURE);
        }
    }
<<<<<<< HEAD
=======
    

fclose(entrada);
fclose(DadosDat);        
    


>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f

    fclose(entrada);
    fclose(DadosDat);

    return EXIT_SUCCESS;
}