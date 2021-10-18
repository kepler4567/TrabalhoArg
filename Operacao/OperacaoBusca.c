#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontraRegistro(char *buffer, int tam, char *chave, int num, int prox)
{

    char *pt;
    char registro[tam];

    if (strcmp(buffer, "") == 0)
    {
        return prox + 1;
    }

    pt = strtok(buffer, "|");
    char *chaveAtual = pt;

    for (int i = 0; i < 4; i++)
    {

        strcat(registro, pt);
        strcat(registro, " ");
        pt = strtok(NULL, "|");
    }

    if (strcmp(chave, chaveAtual) == 0)
    {
        printf("\n%s (RRN = %d - byte-offset %d)\n", registro, num, (num * 64));
        return 0;
    }

    return strlen(registro);
}

int OperacaoBusca(char *chave)
{

    FILE *file;
    if ((file = fopen("Dados.dat", "rb")) == NULL)
    {
        printf("\nAlgo deu errado na leitura do arquivo dados.dat");
        return 0;
        return (EXIT_FAILURE);
    }

    int prox = 0;
    char registro[64];
    int existeReg = 1;
    int num = 0;
    int busca = 1;
    int encontrou = 0;

    while (existeReg == 1 && encontrou == 0)
    {

        fseek(file, num * 64, SEEK_SET);
        if (fread(registro, sizeof(registro), 1, file) == 0)
        {

            printf("\nErro: registro nao encontrado!\n\n");
            existeReg = 0;
            return EXIT_FAILURE;
        }

        busca = encontraRegistro(registro, 64, chave, num, prox);

        if (busca == 0)
        {
            encontrou = 1;
            return EXIT_SUCCESS;
        }
        prox += busca;
        num++;
    }

    fclose(file);

    return 0;
}
