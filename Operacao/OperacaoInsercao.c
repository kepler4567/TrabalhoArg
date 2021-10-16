#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OperacaoInsercao( char *registro)
{

    
    FILE *DadosDat; 
    int   RRN=0, ped;
    char registro2[64];
    int byte_offset_registro;
    int verificador=0;


    if ((DadosDat = fopen("Dados.dat", "r+b")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo Dados.dat");
        
    }

    while (!feof(DadosDat))
    {
        
        fread(registro2, 64,1,DadosDat);
        
        if (registro2[0] == '*')
        {
            ped = RRN;
            verificador = 1;
        }
        
        
        RRN = RRN+1;
        
    }


    if (verificador)
    {

            byte_offset_registro = ped * 64;
            fseek(DadosDat,byte_offset_registro,SEEK_SET);
            fwrite(registro, 64, 1, DadosDat);
            printf("Local: RRN = %i (byte-offset %d) [reutilizado]\n\n", ped, byte_offset_registro);
            rewind(DadosDat);
    }
    else 
    {
            byte_offset_registro = RRN * 64;
            fseek(DadosDat,byte_offset_registro,SEEK_SET);
            fwrite(registro,64, 1, DadosDat);
            printf("Local: RRN = %i (byte-offset %d) [reutilizado]\n\n", RRN, byte_offset_registro);
            rewind(DadosDat);
    }
            
        
   fclose(DadosDat);  

}
