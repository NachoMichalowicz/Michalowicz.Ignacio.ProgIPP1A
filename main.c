#include <stdio.h>
#include <stdlib.h>

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);

typedef struct{

    int id;
    char procesador[10];
    char marca[10];
    int precio;

} Notebook;

int main()
{

    Notebook net1;
    strcpy(net1.marca, "genius");
    net1.precio = 200;

    Notebook net2;
    strcpy(net2.marca, "bafio");
    net2.precio = 2000;

    Notebook notebookList[1];

    notebookList[0] = net1;
    notebookList[1] = net2;

    sortNotebooks(2, &notebookList);
    printf("\n%d", notebookList[0].precio);

    float price = aplicarDescuento(200);
    int numCaracteres = contarCaracteres("holalalaaaa", 'a');

    printf("\n%.2f", price);
    printf("\n%d", numCaracteres);


}

float aplicarDescuento(float precio)
{
    float descuento = 5;
    descuento = precio * descuento;

    descuento = descuento/100;

    precio = precio - descuento;

    return precio;

}

int contarCaracteres(char cadena[], char caracter)
{
    int size = strlen(cadena);
    int contador = 0;

    for (int i = 0; i < size; i++)
    {
       if (cadena[i] == caracter)
       {
           contador++;
       }
    }

    return contador;
}

void sortNotebooks(int len, Notebook *notebooks)
{
    for (int i = 0; i < len; i++)
    {
        Notebook notI;
        notI = notebooks[i];
        char marcaI[10];
        int precioI;
        precioI = notI.precio;
        strcpy(marcaI, notI.marca);

        for (int j = i; j < len; j++)
        {
            Notebook notJ;
            notJ = notebooks[j];
            char marcaJ[10];
            int precioJ;
            precioJ = notJ.precio;
            strcpy(marcaJ, notJ.marca);

            if (marcaI > marcaJ)
            {
                Notebook aux;
                aux = notebooks[i];

                notebooks[i] = notebooks[j];
                notebooks[j] = notebooks[i];
            }
            else
            {
                if (marcaI == marcaJ)
                {
                    if (precioI > precioJ)
                    {
                        Notebook aux;
                        aux = notebooks[i];

                        notebooks[i] = notebooks[j];
                        notebooks[j] = notebooks[i];
                    }
                }
            }
        }

    }
}
