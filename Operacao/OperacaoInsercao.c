#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int OperacaoInsercao( char *registro)
{
    FILE *DadosDat; 
    int  byte_offset, seek;

    if ((DadosDat = fopen("dados.dat", "r+b")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo Dados.dat");
        return EXIT_FAILURE;
    }
    
    
}
