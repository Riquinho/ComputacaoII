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

#define PONTEIRO_NULO 											3
#define COMPRIMENTO_INVALIDO									4 
#define DIGITO_INVALIDO 										5

#define NUMERO_ARGUMENTOS										2
#define EOS															'\0'

int
main (int argc, char *argv [ ])
{
	unsigned indiceArgumento;
	char  identificadorPisPasep [COMPRIMENTO_IDENTIFICADOR];
	unsigned comprimento; 
	char digitoVerificador;
	
	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <Identificador-PIS-PASEP> \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Teste de erro #2: Comprimento do argumento invalido */
	if ((comprimento = strlen (argv [1])) != COMPRIMENTO_IDENTIFICADOR - 1) 
	{
		printf ("\nErro 1.%i: Comprimento do Identificador PIS/PASEP invalido.\n\n", COMPRIMENTO_IDENTIFICADOR_INVALIDO);
		exit (COMPRIMENTO_IDENTIFICADOR_INVALIDO);
	}

	for (indiceArgumento = 0; indiceArgumento < comprimento; indiceArgumento++)
		identificadorPisPasep [indiceArgumento] = argv [1][indiceArgumento];

	identificadorPisPasep [indiceArgumento] = EOS;

	digitoVerificador = GerarDigitoVerificadorPisPasep (identificadorPisPasep);
	
	/* Teste de erro #3: Funcao recebe ponteiro nulo */
	/* Na pratica, nao ocorre, pois os Teste de erro #1 e #2 impossibilitam recebimento de ponteiro nulo */
	if (digitoVerificador == PONTEIRO_NULO_FUNCAO)
	{
		printf ("\nErro 2.%i: Entrada de ponteiro nulo na funcao GerarDigitoVerificadorPisPasep.\n\n",
					PONTEIRO_NULO);
		exit (PONTEIRO_NULO);
	}

	/* Teste de erro #4: Funcao recebe string com comprimento invalido */
	/* Na pratica, nao ocorre, pois o Teste de erro #2 impossibilitam comprimento invalido */
	if (digitoVerificador == COMPRIMENTO_INVALIDO_FUNCAO)
	{
		printf ("\nErro 2.%i: Comprimento invalido da string inserida em GerarDigitoVerificadorPisPasep.\n\n",
					COMPRIMENTO_INVALIDO);
		exit (COMPRIMENTO_INVALIDO);
	}

	/* Teste de erro #5: Funcao recebe string com caracteres nao-numericos */
	if (digitoVerificador == DIGITO_INVALIDO_FUNCAO)
	{
		printf ("\nErro 2.%i: Digito do indentificador PIS/PASEP invalido.\n", DIGITO_INVALIDO);
		printf ("Insira apenas caracteres numericos (1...9).\n\n");
		exit (DIGITO_INVALIDO);
	}
	
	printf ("\nDigito Verificador: %c\n\n", digitoVerificador);

	return OK;
}


/* $RCSfile$ */