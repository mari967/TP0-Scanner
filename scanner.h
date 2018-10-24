#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

typedef enum //filas
{
    INICIAL, E1, E2, E3, ID, CONST, ERR, FINAL
} ESTADO;

typedef enum //columnas
{
    LETRA, DIGITO, ESPACIO, OTRO, FDT
} CARACTER;

typedef enum
{
    IDENTIFICADOR, CONSTANTE, ERROR, FIN
} TOKEN;

int calcularColumna(char caracter);
int tokenIdentificado(ESTADO actual);
int scanner (FILE *archivo);

#endif // SCANNER_H_INCLUDED
