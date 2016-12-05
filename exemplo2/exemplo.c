#include <stdio.h>
#include <string.h>
#include "regex.h"

int main(){
	regex_t reg;
	char expressao[280], palavra[10];

	strcpy(expressao,"^((?!\A( *(if|else|do|while|for|int|float|char|bool))\Z)(\A *[_a-zA-Z][\w]*\Z))*$");
	strcpy(palavra,"abc");

	if(regcomp(&reg, expressao, REG_NOSUB)==0) {
        if(regexec(&reg, palavra,(size_t)0,0,0)==0) {
            printf("Palavra reconhecida!\n");
        }
        else {
            printf("Palavra não reconhecida!\n");
        }
	}

	//getchar();
	return 0;
}