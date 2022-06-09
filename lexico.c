#include "lexico.h"

//VERIFICAÇÕES

int verificaOpLogico(char *string){
    regex_t reg;
	
    if (regcomp(&reg , "^[><!&|]$|^>=$|^<=$|^==$|^!=$|^&&$|^\\|\\|$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Validou\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaOpAritmetico(char *string){
	regex_t reg;
	
    if (regcomp(&reg , "^[\\+\\-\\/\\*%%=]$|^\\+\\+$|^\\-\\-$|^\\>\\>$|^\\<\\<$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Validou\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaSeparador(char *string){
	regex_t reg;
	if (regcomp(&reg , "^[\\(\\)\\{\\},;]$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}
	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Validou\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaPalavraReservada(char *string){
	regex_t reg;

	if (regcomp(&reg , "^int$|^float$|^char$|^string$|^if$|^else$|^for$|^while$|^print$|^read$|^return$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Palavra reservada\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaLetra(char *string){
	regex_t reg;

	if (regcomp(&reg , "^[a-z]$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Entrou");
		// printf("\nLetra\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaEspaco(char *string){
	regex_t reg;
	if (regcomp(&reg , "^\\s$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Espaco\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaAlphaNumerico(char *string){
	regex_t reg;

	if (regcomp(&reg , "^[a-zA-Z0-9_]$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Entrou");
		// printf("\nLetra\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaAlgarismo(char *string){
	regex_t reg;

	if (regcomp(&reg , "^[0-9]$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Entrou");
		// printf("\nAlgarismo\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaNumero(char *string){
	regex_t reg;

	if (regcomp(&reg , "^[0-9]+\\.[0-9]+$|^[0-9]+$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("\nNumero\n");
		return 1;
	}else{
		return 0;
	}
}


int verificaTipoVar(char *string){
	regex_t reg;
	// printf("\nentrou verifica var %s\n", string);
	if (regcomp(&reg , "float$|int$|char$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		// printf("Entrou");
		// printf("\nTipo var\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaExistenciaId(char *string, char tokens[][100], char tipos[][100], int tamanho){
	// printf("\nEntrou existencia ID %d\n", tamanho);
	for (int i = 0; i < tamanho; i++){
		// printf("\n%s %s\n", tipos[i], tokens[i]);
		if(strcmp(tipos[i], "IDENTIFICADOR")==0 && strcmp(string, tokens[i])==0 ){
			// printf("\nAchou id\n");
			return 1;
		}
	}
	return 0;
	
}


