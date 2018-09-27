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



#include "aula0901.h"

#define OK											0
#define NUMERO_ARGUMENTOS_INVALIDO 								1
#define COMPRIMENTO_INVALIDO 									2

#define FUNCAO_PONTEIRO_NULO									3
#define FUNCAO_CARACTERE_INVALIDO								4

#define NUMERO_ARGUMENTOS									2

int
main (int argc, char *argv [ ])
{
	unsigned comprimento;
	char saida [STRING_MAX];
	unsigned resultado;

	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <Identificador-PIS-PASEP> \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Teste de erro #2: Comprimento do argumento invalido */
	if ((comprimento = strlen (argv [1])) > 768) 
	{
		printf ("\nErro 1.%i: Comprimento invalido.\n\n", COMPRIMENTO_INVALIDO);
		exit (COMPRIMENTO_INVALIDO);
	}

	resultado = CodificarBase64((byte *) argv[1], comprimento, saida);
	
	/* Teste de Erro #3: Funcao recebe ponteiro nulo.
								Nao acontece nesse programa, por causa do Teste #1 */
	if (resultado == ponteiroNulo)
	{
		printf ("\nErro 2.%i: Funcao 'CodificarBase64' recebeu ponteiro nulo como parametro.\n\n", FUNCAO_PONTEIRO_NULO);
		exit (FUNCAO_PONTEIRO_NULO);
	}

	/* Teste de Erro #4: Funcao recebe valor invalido nao imprimivel
								(valor < 32 | valor = 127)	*/
	if (resultado == caractereInvalido)
	{
		printf ("\nErro 2.%i: Argumento contem caractere invalido.\n\n", FUNCAO_CARACTERE_INVALIDO);
		exit (FUNCAO_CARACTERE_INVALIDO);
	}

	/* Caso nao haja nenhum erro, exibe o resultado codificado */
	printf ("----------------------------------------------------------------\n\n");
	printf ("CODIFICADOR BASE64\n");
	printf ("\nEntrada:\n%s\n", argv[1]);
	printf ("\nSaida:\n%s",saida);
	printf ("\n\n----------------------------------------------------------------\n");
	return OK;
}


/* $RCSfile$ */
