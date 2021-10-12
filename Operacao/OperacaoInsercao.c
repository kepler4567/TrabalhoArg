#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int OperacaoInsercao( char *registro)
{
    // FILE *DadosDat; 
    // int  byte_offset, seek;

    // if ((DadosDat = fopen("dados.dat", "r+b")) == NULL)
    // {
    //     fprintf(stderr, "Erro ao abrir o arquivo Dados.dat");
    //     return EXIT_FAILURE;
    // }

    //   int byte_offset_registro, ped;
    //   rewind(DadosDat);
    //   fread(&cab, sizeof(cab), 1, DadosDat);

    // if (cab.ped != -1)
    // {
    //     *seek = cab.ped;
    //     byte_offset_registro = cab.ped * 64 + sizeof(cab) + sizeof(char);
    //     fseek(DadosDat, byte_offset_registro, SEEK_SET);
    //     fread(&ped, sizeof(int), 1, DadosDat);
    //     byte_offset_registro = cab.ped * 64 + sizeof(cab);
    //     fseek(DadosDat, byte_offset_registro, SEEK_SET);
    //     fwrite(registro, 64, 1, DadosDat);
    //     cab.ped = ped;
    //     rewind(DadosDat);
    //     fwrite(&cab, sizeof(cab), 1, DadosDat);
    //     *byte_offset = byte_offset_registro;
    //     return false;
    // }
    // else
    // {
    //     byte_offset_registro = cab.cont_reg * 64 + sizeof(cab);
    //     fseek(DadosDat, byte_offset_registro, SEEK_SET);
    //     fwrite(registro, 64, 1, DadosDat);
    //     cab.cont_reg++;
    //     rewind(DadosDat);
    //     fwrite(&cab, sizeof(cab), 1, DadosDat);
    //     return true;
    // }
    
    
}
