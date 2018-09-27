/* Universidade Federal do Rio de Janeiro 
   Escola Politecnica 
   Departamento de Eletronica e de Computacao 
   EEL270 - Computacao II - Turma 2018/1
   Prof. Marcelo Luiz Drumond Lanza 
   Autor: Joao Victor Carvalho Rito 

   $Author$ 
   $Date$ 
   $Log$

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0804.h"

#define OK															0
#define NUMERO_ARGUMENTOS_INVALIDO 							1
#define ARGUMENTO_INVALIDO										2

#define NUMERO_ARGUMENTOS										COMPRIMENTO_IDENTIFICADOR + 1
#define EOS															'\0'

int
main (int argc, char *argv [ ])
{
	unsigned indiceArgumento;
	unsigned short posicaoNumeros [COMPRIMENTO_IDENTIFICADOR] = {0,1,2,3,4,5,6,7,8,9,11};
	char identificadorPisPasep [COMPRIMENTO_IDENTIFICADOR + 1 + 1];
	
	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <d01> <d02> <d03> ... <d%i> \n\n", argv [0], COMPRIMENTO_IDENTIFICADOR);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indiceArgumento = 1; indiceArgumento < argc; indiceArgumento++)
	{
		/* Teste de erro #2: argumento com mais de 1 digito */
		if (strlen (argv [indiceArgumento]) != 1)
		{
			printf ("\nErro 1.%i: Argumento #%i invalido.\n", ARGUMENTO_INVALIDO, indiceArgumento);
			printf ("Insira apenas 1 caractere por argumento.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}

		identificadorPisPasep [posicaoNumeros [indiceArgumento - 1]] = argv [indiceArgumento][0];
	}
	
	identificadorPisPasep [COMPRIMENTO_IDENTIFICADOR - 1]	= '-';
	identificadorPisPasep [COMPRIMENTO_IDENTIFICADOR + 1] = EOS;

	printf ("\nIdentificador PIS/PASEP %s.\n\n", (ValidarPisPasep(identificadorPisPasep) == verdadeiro)? "valido" : "invalido");

	return OK;
}


/* $RCSfile$ */