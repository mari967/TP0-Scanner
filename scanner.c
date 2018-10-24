#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int calcularColumna(char caracter)
{
    int columna;
    if(caracter == -1)
        columna = FDT;
    else if(isalpha(caracter))
        columna = LETRA;
    else if(isdigit(caracter))
        columna = DIGITO;
    else if(isspace(caracter))
        columna = ESPACIO;
    else columna = OTRO;
    return columna;
}

int tokenIdentificado(ESTADO actual)
{
    switch(actual)
    {
    case ID:
        return IDENTIFICADOR;
    case CONST:
        return CONSTANTE;
    case ERR:
        return ERROR;
    case FINAL:
        return FIN;
    }
}

int scanner (FILE *archivo)
{
    const int filas = 8;
    const int columnas = 5;

    int TT[filas][columnas];
    TT[INICIAL][LETRA] = E1;
    TT[INICIAL][DIGITO] = E2;
    TT[INICIAL][ESPACIO] = INICIAL;
    TT[INICIAL][OTRO] = E3;
    TT[INICIAL][FDT] = FINAL;
    TT[E1][LETRA] = E1;
    TT[E1][DIGITO] = E1;
    TT[E1][ESPACIO] = ID;
    TT[E1][OTRO] = E3;
    TT[E1][FDT] = ID;
    TT[E2][LETRA] = CONST;
    TT[E2][DIGITO] = E2;
    TT[E2][ESPACIO] = CONST;
    TT[E2][OTRO] = E3;
    TT[E2][FDT] = CONST;
    TT[E3][LETRA] = ERR;
    TT[E3][DIGITO] = ERR;
    TT[E3][ESPACIO] = ERR;
    TT[E3][OTRO] = E3;
    TT[E3][FDT] = ERR;

    int columna;
    char caracter;
    ESTADO actual = INICIAL;
    TOKEN tok;

    while (actual < ID)
    {   caracter = fgetc(archivo);
        columna = calcularColumna(caracter);
        actual = TT[actual][columna];
    }
    tok = tokenIdentificado(actual);
    if(actual != FINAL)
        ungetc(caracter, archivo);

    return tok;
}
