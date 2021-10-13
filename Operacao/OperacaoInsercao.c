#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OperacaoInsercao( char *registro)
{

    
    FILE *DadosDat; 
    int  seek, RRN=0, ped;
    char registro2[64];
    int byte_offset_registro;
    int verificador=0;


    if ((DadosDat = fopen("Dados.dat", "r+b")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo Dados.dat");
        
    }

    while (registro[RRN] != EOF)
    {
        
        fread(registro, sizeof(char) ,64,DadosDat);
        
        if (registro[0] == '*')
        {
            ped = RRN;
            verificador = 1;
        }
        
        
        RRN++;
        
    }


    if (verificador)
    {
            
    }
    else 
    {
            byte_offset_registro = RRN * 64;
            fwrite(registro, 64, byte_offset_registro, DadosDat);
            printf("Local: RRN = %i (byte-offset %d) [reutilizado]\n", RRN, byte_offset_registro);
    }
            
        
     

}
