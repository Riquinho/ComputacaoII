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


/* 
 * Objetivos:
 * Recebe um argumento da CLI.
 * Passa por tratamento de erro para verificar se numero de argumentos inserido esta correto.
 * Passa por tratamento de erro para verificar se argumento #1 eh eh positivo.
 * Passa por tratamento de erro para verificar se argumento #1 eh inteiro.
 * Exibe o resultado da serie harmonica alternada do numero de termos inseridos.
 */

#include <stdio.h>
#include <stdlib.h>

#include "aula0501.h"

#define OK														0
#define NUMERO_ARGUMENTOS_INVALIDO 								1
#define ARGUMENTO_INVALIDO										2

#define NUMERO_ARGUMENTOS										2	

#define EOS														'\0'

int
main (int argc, char *argv [ ])
{
	int indiceCaractere;
	char *validacao;
	unsigned long int termos;

	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 01: Numero invalido de argumentos!\n");
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <termos>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Teste de erro #2: Numero negativo (presenca de hifen) */
	for (indiceCaractere = 0; argv [1][indiceCaractere] != EOS; indiceCaractere++)
		if (argv [1][indiceCaractere] == '-')
		{
			printf ("\nErro 02: Argumento #1 contem caracteres invalidos.\nInsira apenas numeros positivos.\n\n");
			printf ("Use: %s <inteiro-positivo>\n\n", argv [0]);
			exit (ARGUMENTO_INVALIDO);
		}
 
 	/* Teste de erro #3: Argumento #1 nao eh inteiro */
	/* O argumento eh armazenado como unsigned long na variavel 'termos' */
	termos = strtoul (argv[1], &validacao, 10);
	if (*validacao != EOS)	
	{
		printf ("\nErro 03: Argumento #1 contem caracteres invalidos.\nInsira apenas numeros inteiros.\n\n");
		printf ("Use: %s <inteiro-positivo>\n\n", argv [0]);
		exit (ARGUMENTO_INVALIDO);
	}

	/* Titulo */
	printf ("\nSERIE HARMONICA ALTERNADA\n\n");

	/* Exibe: S(n) = resultado */
	printf ("S(%lu) = %g\n\n", termos, CalcularSerieHarmonicaAlternada (termos));

	return OK;
}

/* $RCSfile$ */