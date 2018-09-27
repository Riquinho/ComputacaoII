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

#define OK													0
#define NUMERO_ARGUMENTOS_INVALIDO 							1
#define COMPRIMENTO_INVALIDO 								2

#define FUNCAO_PONTEIRO_NULO								3
#define FUNCAO_CARACTERE_INVALIDO							4
#define FUNCAO_COMPRIMENTO_INVALIDO							5
#define FUNCAO_PADDING_INVALIDO								6
#define FUNCAO_CODIGO_INVALIDO								7

#define NUMERO_ARGUMENTOS									2

int
main (int argc, char *argv [ ])
{
	unsigned comprimento;
	byte saida [STRING_MAX];
	unsigned resultado;
	unsigned indiceCaractere;

	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <Identificador-PIS-PASEP> \n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Teste de erro #2: Comprimento do argumento invalido */
	if ((comprimento = strlen (argv [1])) > STRING_MAX) 
	{
		printf ("\nErro 1.%i: Comprimento invalido.\n\n", COMPRIMENTO_INVALIDO);
		exit (COMPRIMENTO_INVALIDO);
	}

	comprimento = 0;
	resultado = DecodificarBase64 (argv[1], saida, &comprimento);

	/* Teste de Erro #3: Funcao recebe ponteiro nulo.
								Nao acontece nesse programa, por causa do Teste #1 */
	if (resultado == ponteiroNulo)
	{
		printf ("\nErro 2.%i: Funcao 'DecodificarBase64' recebeu ponteiro nulo como parametro.\n\n", FUNCAO_PONTEIRO_NULO);
		exit (FUNCAO_PONTEIRO_NULO);
	}

	/* Teste de Erro #4: Caractere invalido. */
	if (resultado == caractereInvalido)
	{
		printf ("\nErro 2.%i: Argumento contem caractere invalido.\nInsira apenas caracteres do conjunto Base64.\n\n",
				  FUNCAO_CARACTERE_INVALIDO);
		exit (FUNCAO_CARACTERE_INVALIDO);
	}

	/* Teste de Erro #5: Comprimento invalido. */
	if (resultado == comprimentoInvalido)
	{
		printf ("\nErro 2.%i: Tamanho do argumento invalido.\nInsira um codigo com um numero multiplo de 4 de caracteres.\n\n",
				  FUNCAO_COMPRIMENTO_INVALIDO);
		exit (FUNCAO_COMPRIMENTO_INVALIDO);
	}
	
	/* Teste de Erro #6: Padding invalido. */
	if (resultado == paddingInvalido)
	{
		printf ("\nErro 2.%i: Uso do padding invalido.\nUse '=' apenas no ultimo ou nos 2 ultimos caracteres.\n\n",
				  FUNCAO_PADDING_INVALIDO);
		exit (FUNCAO_PADDING_INVALIDO);
	}

	/* Exibe o resultado da decodificacao, caso nao haja erros */
	printf ("----------------------------------------------------------------\n");
	printf ("\nDECODIFICADOR BASE64\n ");
	printf ("\n    Entrada: %s", argv[1]);
	printf ("\n      Saida: ");
	for (indiceCaractere = 0; indiceCaractere < comprimento; indiceCaractere++)
		printf ("%c", saida[indiceCaractere]);
	
	printf ("\nHexadecimal: ");
	for (indiceCaractere = 0; indiceCaractere < comprimento; indiceCaractere++)
		printf ("0x%02X ", saida[indiceCaractere]);
	
	printf ("\n    Decimal: ");
	for (indiceCaractere = 0; indiceCaractere < comprimento; indiceCaractere++)
		printf ("%u  ", saida[indiceCaractere]);

	printf ("\n    Tamanho: %u", comprimento);
	printf ("\n\n----------------------------------------------------------------\n");
	
	return OK;
}


/* $RCSfile$ */