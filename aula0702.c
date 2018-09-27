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

#include "aula0701.h"

#define OK															0
#define NUMERO_ARGUMENTOS_INVALIDO 							1
#define ARGUMENTO_INVALIDO										2

#define NUMERO_ARGUMENTOS										1 + (MATRIZ_A_LINHAS * MATRIZ_A_COLUNAS) + (MATRIZ_B_LINHAS * MATRIZ_B_COLUNAS)


#define EOS															'\0'

int
main (int argc, char *argv [ ])
{
	unsigned indiceArgumento, indiceLinha, indiceColuna;
	char *validacao;
	float matrizA [MATRIZ_A_LINHAS][MATRIZ_A_COLUNAS], 
			matrizB [MATRIZ_B_LINHAS][MATRIZ_B_COLUNAS],
			matrizProduto [MATRIZ_A_LINHAS][MATRIZ_B_COLUNAS];

	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Matriz A: %ix%i\tMatriz B: %ix%i\n", MATRIZ_A_LINHAS, MATRIZ_A_COLUNAS, MATRIZ_B_LINHAS, MATRIZ_B_COLUNAS);
		printf ("Use: %s <a11> <a12> <a13> ... <b31> <b32> <b33> <b34> \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Define a matriz A a partir dos argumentos
	 * Tratamento de erro para ver se um numero FLOAT */
	for (indiceLinha = 0; indiceLinha < MATRIZ_A_LINHAS; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < MATRIZ_A_COLUNAS; indiceColuna++)
		{
			indiceArgumento = indiceLinha * MATRIZ_A_COLUNAS + indiceColuna + 1;
			matrizA [indiceLinha][indiceColuna] = strtof (argv [indiceArgumento], &validacao);
			if (*validacao != EOS)
			{
				printf ("\nErro 1.%i: Argumento #%u contem caractere invalido.\n", ARGUMENTO_INVALIDO, indiceArgumento)	;
				printf ("Caractere invalido: '%c'\n\n", *validacao);
				exit (ARGUMENTO_INVALIDO);
			}
		}

	/* Define a matriz B a partir dos argumentos
	 * Tratamento de erro para ver se um numero FLOAT */
	for (indiceLinha = 0; indiceLinha < MATRIZ_B_LINHAS; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < MATRIZ_B_COLUNAS; indiceColuna++)
		{
			indiceArgumento = indiceLinha * MATRIZ_B_COLUNAS + MATRIZ_A_LINHAS*MATRIZ_A_COLUNAS + indiceColuna + 1;
			matrizB [indiceLinha][indiceColuna] = strtof (argv [indiceArgumento], &validacao);
			if (*validacao != EOS)
			{
				printf ("\nErro 1.%i: Argumento #%u contem caractere invalido.\n", ARGUMENTO_INVALIDO, indiceArgumento)	;
				printf ("Caractere invalido: '%c'\n\n", *validacao);
				exit (ARGUMENTO_INVALIDO);
			}
		}	

	/* Titulo */
	printf ("\nRESULTADO MULTIPLICACAO DE MATRIZES\n\n");

	MultiplicarMatrizes (matrizA, matrizB, matrizProduto);
	
	/* imprime a matriz resultado */
	for (indiceLinha = 0; indiceLinha < MATRIZ_A_LINHAS; indiceLinha++)
	{
		printf("[ ");
		for (indiceColuna = 0; indiceColuna < MATRIZ_B_COLUNAS; indiceColuna++)
			printf("%06.2f  ", matrizProduto[indiceLinha][indiceColuna]);
		printf("]\n");
	}

	printf("\n");

	return OK;
}

/* $RCSfile$ */