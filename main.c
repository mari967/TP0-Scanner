#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"

/*TP0  –  2018
"Un  escáner  elemental"
Grupo  10
Cervantes Marisol, 1639201
Lodeiros Ayrton, 1646473
Nishizaka Matías, 1634483
Rey Gastón, 1561674*/

int main()
{
    FILE *archivo;

    archivo = fopen("datos.txt", "r+");
    if (!archivo)
    {
        printf("No se pudo abrir el archivo de lectura ");
        return EXIT_FAILURE;
    }
    int identificadores = 0;
    int constantes = 0;
    int errores = 0;
    int token;

    do
    {
        token = scanner(archivo);
        switch (token)
        {
        case IDENTIFICADOR:
            printf("Identificador\n");
            identificadores++;
            break;
        case CONSTANTE:
            printf("Constante entera\n");
            constantes++;
            break;
        case ERROR:
            printf("Error\n");
            errores++;
            break;
        }
    }
    while (token != FIN);
    printf("----\nTotales:\n");
    printf("Identificadores %i\n", identificadores);
    printf("Constantes enteras %i\n", constantes);
    printf("Errores %i\n",errores);
    fclose(archivo);
    return EXIT_SUCCESS;
}
