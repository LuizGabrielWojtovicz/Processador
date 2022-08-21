#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NULL ((void *)0)

int isNumber(char *string)
{
    int boolean;

    for(int i = 0; i < (strlen(string)); i++)
    {
        if(isdigit(string[i]))
        {
            boolean = 1;
        }
        else
        {
            boolean = 0;
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    //memory:

    int storange = 32;
    char *data[storange];

      for(int i = 0; i < storange; i++)
      {
        data[i] = (char *) malloc((19*10000)*sizeof(char));
      }

    char *dataTemp;
    dataTemp = (char *) malloc((19*10000)*sizeof(char));

    //interface + registers:

    int j = 0;
    int key;
    int idNumber[32];

    do
    {

        printf("1. Adicionar dado;\n2. Ver dados nos registros;\n3. finalizar.\n");
        scanf("%i", &key);

        if(key == 1)
        {
            printf("Digite o dado:");
            scanf("%s", data[j]);
            j++;

            if(isNumber(data[j]) == 1)
            {
                idNumber[j] = 1;
            }
            else
            {
                idNumber[j] = 0;
            }
        }
        else if(key == 2)
        {
            for(int i = 0; i < storange; i++)
            {
                if(i < 9)
                {
                    dataTemp = data[i];
                    printf("R0%i >> %s // tipo-> %s\n", i + 1, dataTemp, (isNumber(dataTemp))? "Numero" : "Caracteres");
                }
                else if(i >= 10)
                {
                    dataTemp = data[i];
                    printf("R%i >> %s // tipo -> %s\n", i + 1, dataTemp, (isNumber(dataTemp))? "Numero" : "Caracteres");
                }
            }
        }

        if(j == storange)
        {
            j = 0;
            free(data[j]);
        }

    } while(key != 3);

    return 0;

}
