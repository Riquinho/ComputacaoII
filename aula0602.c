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

#include "aula0601.h"

#define OK															0
#define MANUAL														1
#define NUMERO_ARGUMENTOS_INVALIDO 							2
#define ARGUMENTO_NEGATIVO										3
#define ARGUMENTO_INVALIDO										4
#define ARGUMENTO_NULO											5

#define NUMERO_ARGUMENTOS										9

#define EOS															'\0'

/* Implementação do programa de testes da função PreencherPoligono
 * Este programa recebe:
 * - o numero de linhas e o numero de colunas do dispositivo desejado, 
 * - as coordenadas do canto superior esquerdo e do canto inferior direito de um retangulo
 * - as coordenadas de um ponto que esteja dentro deste retangulo. 
 * Se os argumentos forem validos:
 * - limpa o monitor e o exibe
 * - desenha um retangulo e o exibe
 * - preenche o poligono e exibe o monitor toda vez que um pixel eh aceso */

/* Caso o usuario insira 'm' como primeiro argumento, um manual do programa sera exibido */

/* Definicao: coordenada inicial = (1,1) */
/* O programa principal usa (1,1) para facilitar a experiencia do usuario */
/* As funcoes presentes no arquivo aula0601.c adotam (0,0) como inicais */

int
main (int argc, char *argv [ ])
{
	int indiceArgumento;
	char *validacao;
	unsigned numeroLinhas, numeroColunas, ordenadaEsquerda, abscissaEsquerda, ordenadaDireita, abscissaDireita, linha, coluna;
	unsigned dados [NUMERO_ARGUMENTOS - 1];
	unsigned resultado;
	tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

	/* Manual do Programa */
	/* Caso o usuario insira ./nome-do-programa m */
	if (argv [1][0] == 'm' || argv[1][0] == EOS)
	{
		system ("clear");
		printf ("\nMANUAL %s\n\n", argv [0]);
		printf ("\n1. Objetivos\n\n");
		printf ("\t- Exibe um monitor com dimensoes dadas (H e W).\n");
		printf ("\t- Desenha um retangulo com 2 vertices dados (X1, Y1, X2, Y2).\n");
		printf ("\t- Preenche o retangulo a partir de um ponto interno dado (Xi e Yi).\n");
		printf ("\n2. Uso\n\n");
		printf ("\t%s <H> <W> <X1> <Y1> <X2> <Y2> <Xi> <Yi>\n\n", argv [0]);
		printf ("\t\t H - Altura (numero de linhas)\n");
		printf ("\t\t W - Largura (numero de colunas)\n");
		printf ("\t\tX1 - Ordenada Superior Esquerda do Retangulo\n");
		printf ("\t\tY1 - Abscissa Superior Esquerda do Retangulo\n");
		printf ("\t\tX2 - Ordenada Inferior Direita do Retangulo\n");
		printf ("\t\tY2 - Abscissa Inferior Direita do Retangulo\n");
		printf ("\t\tXi - Ordenada de um ponto interno ao retangulo\n");
		printf ("\t\tYi - Abscissa de um ponto interno ao retangulo\n\n");
		printf ("\t- Todos os argumentos devem ser do tipo x > 0\n");
		printf ("\t- As coordenadas do vertice inferior direito devem ser maiores do que as do vertice superior esquerdo (X2 > X1 e Y2 > Y1).\n");
		printf ("\n3. Definicoes\n\n");
		printf ("\tDimensoes maximas do monitor: %ix%i\n", NUMERO_MAXIMO_LINHAS, NUMERO_MAXIMO_COLUNAS);
		printf ("\tCoordenadas do primeiro pixel: (1,1)\n");
		printf ("\n3. Erros\n\n");
		printf ("\t1.2 - Numero de Argumentos Invalido\n");
		printf ("\t1.3 - Argumento Negativo\n");
		printf ("\t1.4 - Argumento Invalido\n");
		printf ("\t1.5 - Argumento Nulo\n\n");
		printf ("\t2.1 - Altura do monitor (H) acima do permitido.\n");
		printf ("\t2.2 - Largura do monitor (W) acima do permitido.\n");
		printf ("\t2.3 - Ordenada Superior Esquerda do Retangulo (X1) invalida.\n");
		printf ("\t2.4 - Abscissa Superior Esquerda do Retangulo (Y2) invalida.\n");
		printf ("\t2.5 - Ordenada Inferior Direita do Retangulo (X2) invalida.\n");
		printf ("\t2.6 - Abscissa Inferior Direita do Retangulo (Y2) invalida.\n");
		printf ("\t2.7 - Ordenada do ponto interno (Xi) invalida.\n");
		printf ("\t2.8 - Abscissa do ponto interno (Yi) invalida.\n\n");

		exit (MANUAL);
	}

	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos.\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("\nUse '%s m' para acessar o manual do programa.\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}


	for (indiceArgumento = 1; indiceArgumento < argc; indiceArgumento++)
	{	
		/* Teste de erro #2: Argumento é um numero negativo.
		 * Tratamento de erro para hifen na primeira posicao da string.
		 * Ja que a funcao strtoul nao trata o hifen na primeira posicao. */
		if (argv [indiceArgumento][0] == '-')
		{
			printf ("\nErro 1.%i: Argumento #%u contem caractere invalido.\n", ARGUMENTO_NEGATIVO, indiceArgumento);
			printf ("Caractere invalido: '-'\n\n");
			printf ("\nUse '%s m' para acessar o manual do programa.\n\n", argv [0]);
			exit (ARGUMENTO_NEGATIVO);
		}
		
		/* Teste de erro #3: Argumento contem caractere invalido. */
		/* A string eh salva num array de strings 'dados' para facilitar a manipulacao dos dados recebidos */
		dados[indiceArgumento-1] = strtoul (argv [indiceArgumento], &validacao, 10);
		if (*validacao != EOS)
		{
			printf ("\nErro 1.%i: Argumento #%u contem caractere invalido.\n", ARGUMENTO_INVALIDO, indiceArgumento);
			printf ("Caractere invalido: '%c'\n\n", *validacao);
			printf ("\nUse '%s m' para acessar o manual do programa.\n\n", argv [0]);
			exit (ARGUMENTO_INVALIDO);
		}

		/* Teste de erro #4: argumento nulo
		 * Nao existe coordenadas (0,0) no programa
		 * Coordenadas iniciais: (1,1) */
		if (dados[indiceArgumento-1] == 0)
		{
			printf ("\nErro 1.%i: Argumento #%u nulo.\n", ARGUMENTO_NULO, indiceArgumento);
			printf ("Lembre-se, as coordenadas iniciais sao (1,1).\n");
			printf ("\nUse '%s m' para acessar o manual do programa.\n\n", argv [0]);
			exit (ARGUMENTO_NULO);
		}
	}

	/* Definicao de cada variavel a partir do vetro 'dados' */
	numeroLinhas 		= dados[0];
	numeroColunas 		= dados[1];
	ordenadaEsquerda 	= dados[2];
	abscissaEsquerda 	= dados[3];
	ordenadaDireita 	= dados[4];
	abscissaDireita 	= dados[5];
	linha 				= dados[6];
	coluna 				= dados[7];

	/* Uso da variavel resultado para facilitar a manipulacao do return de cada funcao */
	/* Economia de espaco, devido ao alto numero de parametros por funcao */
	resultado = LimparMonitor (monitor, numeroLinhas, numeroColunas);

	/* Teste de erro #5: numeroLinhas e/ou numerosColunas invalidos */
	if (resultado != ok)
	{
		printf ("\nErro 2.%i: dimensoes do monitor invalidas.\n", resultado);
		printf ("Use '%s m' para acessar o manual do programa.\n\n", argv [0]);
		exit (resultado);
	}
	
	resultado = DesenharRetangulo (monitor, numeroLinhas, numeroColunas,
					ordenadaEsquerda, abscissaEsquerda, 
					ordenadaDireita, abscissaDireita);

	/* Teste de erro #6: coordenadas do retangulo invalidas */
	if (resultado != ok)
	{
		printf ("\nErro 2.%i: coordenadas do retangulo invalidas.\n", resultado);
		printf ("Use '%s m' para acessar o manual do programa.\n\n", argv [0]);
		exit (resultado);
	}

	/* O programa principal tem coordenadas iniciais (1,1)
	 * Ja a funcao, coordenadas iniciais (0,0)
	 * por isso linha-1 e coluna-1 */
	resultado = PreencherPoligono (monitor, numeroLinhas, numeroColunas,
							 				 linha-1, coluna-1);

	/* Teste de erro #7: ponto interno invalido */
	if (resultado != ok)
	{
		printf ("\nErro 2.%i: coordenadas do ponto interno invalidas.\n", resultado);
		printf ("Use '%s m' para acessar o manual do programa.\n\n", argv [0]);
		exit (resultado);
	}

	/* quebra de linha no final do programa */
	printf("\n");

	return OK;
}

/* $RCSfile$ */