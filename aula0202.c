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

#include "aula0201.h"

#define OK							0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO 			2

#define NUMERO_ARGUMENTOS 			3

#define EOS 						'\0'

int
main (int argc, char *argv[ ])
{

	unsigned indiceArgumento, indiceCaractere;
	int numeroA, numeroB;

	/* Verifica se foram inseridos o numero correto de argumentos
	* Se o numero de argumentos for diferente de NUMERO_ARGUMENTOS --> mensagem de erro
	*/
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero invalido de argumentos!\n");
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS) - 1);
		printf ("Use: %s <inteiro> <inteiro>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
   }

	/* Verifica se foram inseridos apenas caracteres numericos.
	* Assim, apenas numeros inteiros positivos serao aceitos.
	*/
	for (indiceArgumento = 1; indiceArgumento < argc; indiceArgumento++)
		for (indiceCaractere = 0; argv [indiceArgumento][indiceCaractere] != EOS; indiceCaractere++)
			if (argv [indiceArgumento][indiceCaractere] < '0' || argv [indiceArgumento][indiceCaractere] > '9')
		{
			printf ("Entrada contem caractere invalido. Argumento #%u.\nInsira apenas numeros inteiros positivos.\n\n", indiceArgumento);
			exit (ARGUMENTO_INVALIDO);
		}

	/* Define numeroA e numeroB */
	numeroA = atoi (argv [1]);
	numeroB = atoi (argv [2]);

	/* Mensagem de erro para MDC (0,0) */
	if (CalcularMaximoDivisorComum (numeroA,numeroB) == 0)
		printf("Nao existe MDC entre 0 e 0!\n\n");
	/* Calculo do Maximo Divisor Comum apos passar por todas as verificacoes de erro */
	else
		printf("MDC (%s,%s) = %llu\n\n", argv[1], argv[2], CalcularMaximoDivisorComum (numeroA,numeroB));

	return OK;
}

/* $RCSfile$ */