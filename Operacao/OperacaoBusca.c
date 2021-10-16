#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontraRegistro(char *buffer, int tam, char *chave, int num, int prox)
{

<<<<<<< HEAD
    char *pt;
    char registro[tam];
=======
    

    // char registro[64];
    // char key[6];
    // FILE *entrada;
    // int RRN = 0;
    // int ByteOffSet;
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f

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
        printf("\n%s (RRN = %d - byte-offset %d)\n", registro, num, (num * 64) + 4);
        return 0;
    }

<<<<<<< HEAD
    return strlen(registro);
}
=======
    //         ByteOffSet = RRN*64;
    //         printf("registro %s encontrado\n Conteudo = %s (RRN = %i - Byte Offset = %i", key, registro, RRN, ByteOffSet);  
            
    //         return EXIT_SUCCESS;
        
    //     }else{
    //         RRN++;
    //     }
    // }

  
    // printf("Registro nao encontrado!!!\n");
 
 
 return 0;
 }
>>>>>>> ec4ba109d28125041747f066ff26aa2e4d41860f

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
            printf("%i", num);
            return EXIT_SUCCESS;
        }
        prox += busca;
        num++;
    }

    fclose(file);

    return 0;
}
