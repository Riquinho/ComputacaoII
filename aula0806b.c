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
#define COMPRIMENTO_IDENTIFICADOR_INVALIDO				2
#define ARGUMENTO_INVALIDO										3

#define NUMERO_ARGUMENTOS										2
#define EOS															'\0'

int
main (int argc, char *argv [ ])
{
	unsigned indiceArgumento;
	char  identificadorPisPasep [COMPRIMENTO_IDENTIFICADOR + 2];
	unsigned comprimento;
	
	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <Identificador-PIS-PASEP> \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Teste de erro #2: Comprimento string invalido */
	if ((comprimento = strlen (argv [1])) != COMPRIMENTO_IDENTIFICADOR + 1) 
	{
		printf ("\nErro 1.%i: Comprimento do Identificador PIS/PASEP invalido.\n\n", COMPRIMENTO_IDENTIFICADOR_INVALIDO);
		exit (COMPRIMENTO_IDENTIFICADOR_INVALIDO);
	}

	for (indiceArgumento = 0; indiceArgumento < comprimento; indiceArgumento++)
		identificadorPisPasep [indiceArgumento] = argv [1][indiceArgumento];

	identificadorPisPasep [indiceArgumento] = EOS;

	printf ("\nIdentificador PIS/PASEP %s.\n\n", (ValidarPisPasep(identificadorPisPasep) == verdadeiro)? "valido" : "invalido");

	return OK;
}

/* $RCSfile$ */