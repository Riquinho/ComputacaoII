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


#include "aula0301.h"

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO 				1
#define ARGUMENTO_INVALIDO						2

#define NUMERO_ARGUMENTOS						2

#define EOS										'\0'

int
main (int argc, char *argv [ ])
{
	unsigned indiceCaractere;
	char *validacao;
	unsigned short valor, indiceTermo;

	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nNumero invalido de argumentos!\n");
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <interio>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Teste de erro #2: Caracteres invalidos */
	for (indiceCaractere = 0; argv [1][indiceCaractere] != EOS; indiceCaractere++)
		if (argv [1][indiceCaractere] == '-')
		{
			printf ("\nErro 02: Argumento #1 contem caracteres invalidos.\nInsira apenas numeros positivos.\n\n");
			printf ("Use: %s <inteiro-positivo>\n\n", argv [0]);
			exit (ARGUMENTO_INVALIDO);
		}

	valor = strtoul (argv [1],&validacao,10);
	if (*validacao != EOS)	
	{
		printf ("\nErro 03: Argumento #1 contem caracteres invalidos.\nInsira apenas numeros inteiros.\n\n");
		printf ("Use: %s <inteiro-positivo>\n\n", argv [0]);
		exit (ARGUMENTO_INVALIDO);
	}

	printf ("\nSERIE DE FIBONACCI\nValor Inserido: %hu\n\n", valor);

	/* Imprime o valor do valor da sequencia de F(0) ate F(n). */
	for (indiceTermo = 0; indiceTermo <= valor; indiceTermo++)
		printf(" F (%hu) = %llu\n", indiceTermo, CalcularTermoSerieFibonacci(indiceTermo));

	printf ("\n");

	return OK;
}

/* $RCSfile: aula0302.c,v $ */