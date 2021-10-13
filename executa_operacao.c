#include "Operacao/OperacaoBusca.c"
#include "Operacao/OperacaoInsercao.c"
#include "Operacao/operacaoRemocao.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void LeComando(char comando[], FILE *entrada){
   
   
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
}



int executa_operacoes(char Arquivo[]){


    
    
    int chave;
    FILE *entrada;
    FILE *DadosDat;
    char comando[67], opcao, registro[65];

   

    DadosDat = fopen("Dados.dat", "r");
    entrada = fopen(Arquivo, "r");

     while (!feof(entrada))
    {
        
        LeComando(comando, entrada);
        opcao = comando[0];
                
        
        if (opcao == 'b')
        {
            chave = recebeChave(comando);
            printf("Operacao de busca ativada na chave: %i\n", chave);
            OperacaoBusca(chave);
        }
        else if (opcao == 'i')
        {
            leRegistro(registro,comando);
            printf("Operacao de insercao ativada do registro: %s\n",  registro);
            OperacaoInsercao(registro);
        }
        else if (opcao == 'r')
        {
            chave = recebeChave(comando);
            printf("Operacao de remocao ativada na chave: %i\n", chave);
            OperacaoRemocao(chave);
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
    

fclose(entrada);
fclose(DadosDat);        
    




    
    return EXIT_SUCCESS;
}