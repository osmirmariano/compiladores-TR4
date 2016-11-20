#include <stdio.h>
#include <string.h>
#include "regex.h"

int main()
{
	regex_t reg;
	char expressao[80],palavra[10];

	strcpy(expressao,"^ *([0-9]*[0-9].[0-9]*[0-9])$");
	strcpy(palavra,"1234.1234");

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