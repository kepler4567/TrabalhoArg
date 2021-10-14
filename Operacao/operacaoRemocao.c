#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "./OperacaoBusca.c"

int OperacaoRemocao(int chave)
{
    FILE *entrada;
    char registro[64];
    int byte_offset;
    int rrn;
    char ped = '*';

    if ((entrada = fopen("Dados.dat", "a+b")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }
    /* strcpy(registro, OperacaoBusca(chave));
    printf("%s", registro);
    registro[0] = '*'; */

    /* arrumar um forma de retornar o RRN da busca e usar ele para a remoção */

    byte_offset = rrn * 64;
    fseek(entrada, byte_offset, SEEK_SET);
    fwrite(&ped, sizeof(char), 1, entrada);

    return 0;
}
