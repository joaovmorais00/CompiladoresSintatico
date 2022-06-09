#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>


//VERIFICAÇÕES
int verificaOpLogico(char *string);
int verificaOpAritmetico(char *string);
int verificaSeparador(char *string);
int verificaPalavraReservada(char *string);
int verificaLetra(char *string);
int verificaAlphaNumerico(char *string);
int verificaAlgarismo(char *string);
int verificaNumero(char *string);
int verificaEspaco(char *string);
int verificaTipoVar(char *string);
int verificaExistenciaId(char *string, char tokens[][100], char tipos[][100], int tamanho);
