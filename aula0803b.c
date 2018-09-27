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

#include "aula0801.h"

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
	byte  identificadorPisPasep [COMPRIMENTO_IDENTIFICADOR - 1];
	byte comprimento;
	
	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <Identificador-PIS-PASEP> \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Teste de erro #2: Comprimento do argumento invalido */
	if ((comprimento = (byte) strlen (argv [1])) != COMPRIMENTO_IDENTIFICADOR + 1) 
	{
		printf ("\nErro 1.%i: Comprimento do Identificador PIS/PASEP eh invalido.\n\n", COMPRIMENTO_IDENTIFICADOR_INVALIDO);
		exit (COMPRIMENTO_IDENTIFICADOR_INVALIDO);
	}

	/* Teste de erro #3: Argumento contem caractere nao-numerico. */
	for (indiceArgumento = 0; indiceArgumento < comprimento - 2; indiceArgumento++)
	{
		if (argv [1][indiceArgumento] < '0' || argv [1][indiceArgumento] > '9')
		{
			printf ("\nErro 1.%i: Argumento contem caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Caractere invalido: %c\n\n", argv [1][indiceArgumento]);
			exit (ARGUMENTO_INVALIDO);
		}

		identificadorPisPasep [indiceArgumento] = (byte) (argv [1][indiceArgumento] - '0');
	}

	/* Teste de erro #4: Verifica se o 11o digito e' hifen (-) */ 
	if (argv[1][comprimento-2] != '-')
	{
		printf ("\nErro 1.%i: Argumento contem caractere invalido.\n", ARGUMENTO_INVALIDO);
		printf ("Caractere invalido: %c\n\n", argv [1][comprimento-2]);
		exit (ARGUMENTO_INVALIDO);
	}

	/* Teste de erro #5: 12o digito contem caractere nao-numerico */
	if (argv[1][comprimento-1] < '0' || argv[1][comprimento-1] > '9')
	{
		printf ("\nErro 1.%i: Argumento contem caractere invalido.\n", ARGUMENTO_INVALIDO);
		printf ("Caractere invalido: %c\n\n", argv [1][comprimento-1]);
		exit (ARGUMENTO_INVALIDO);
	}

	identificadorPisPasep [comprimento-2] = (byte) (argv [1][comprimento-1] - '0');

	/* Para qualquer erro dentro da funcao ValidarPisPasep, a mesma retorna falso.
	 * Nao precisando entao, verificar se a funcao retornou erro. */

	printf ("\nIdentificador PIS/PASEP %s.\n\n", (ValidarPisPasep(identificadorPisPasep) == verdadeiro)? "valido" : "invalido");

	return OK;
}

/* $RCSfile$ */