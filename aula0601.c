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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "aula0601.h"

/* Implementacao das funcoes:
 * - MostrarMonitor
 * - LimparMonitor
 * - DesenharRetangulo
 * - PreencherPoligono */

/* Definicao: coordenada inicial = (0,0) */
/* As funcoes podem fazer tratamentos de erro redundandes com ponto de vista do programa principal.
 * Mas estes tratamentos de erros foram propositais, para tornarem as funcoes portaveis para outros programas.
 * Podendo entao serem executadas em qualquer ordem. */

/* Exibe os pixels de um monitor recebido como parametro */
tipoErros
MostrarMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
					unsigned maximoLinhas, unsigned maximoColunas)
{
	unsigned indiceLinha, indiceColuna;

	/* Teste de erro #1: dimensoes acima do permitido (NUMERO_MAXIMO_LINHAS/COLUNAS) */
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
		return (maximoLinhasInvalido);
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
		return (maximoColunasInvalido);

	/* Limpa o terminal */
	system ("clear");
	
	/* Exibe cada pixel */
	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
	{
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
			printf("%c ", monitor [indiceLinha][indiceColuna] == aceso ? ACESO : APAGADO);
		/* Quebra de linha ao final de cada linha */
		printf("\n");
	}
	/* Tempo para usuario visualizar */
	sleep(1);
	return ok;
}

/* Define todos os pixels do monitor como apagado */
/* No final, chama a funcao MostrarMonitor e exibe o monitor */
tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
					unsigned maximoLinhas, unsigned maximoColunas)
{
	unsigned indiceLinha, indiceColuna;

	/* Teste de erro #1: dimensoes acima do permitido (NUMERO_MAXIMO_LINHAS/COLUNAS) */
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
		return (maximoLinhasInvalido);
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
		return (maximoColunasInvalido);

	/* Define cada pixel como apagado */
	for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
			monitor [indiceLinha][indiceColuna] = apagado;

	/* Exibe o monitor */
	MostrarMonitor (monitor, maximoLinhas, maximoColunas);

	return ok;
}

/* Desenha um retangulo a partir de 2 coordenadas recebidas */
/* No final, chama a funcao MostrarMonitor e exibe o monitor */
tipoErros
DesenharRetangulo (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
						unsigned maximoLinhas, unsigned maximoColunas,
						unsigned ordenadaEsquerda, unsigned abscissaEsquerda,
						unsigned ordenadaDireita, unsigned abscissaDireita)
{
	unsigned indiceLinha, indiceColuna;

	/* Teste de erro #1: dimensoes acima do permitido (NUMERO_MAXIMO_LINHAS/COLUNAS) */
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
		return (maximoLinhasInvalido);
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
		return (maximoColunasInvalido);

	/* Teste de erro #2: coordenadas do retangulo acima do permitido */
	if (ordenadaEsquerda > maximoLinhas)
		return (ordenadaEsquerdaInvalida);
	if (abscissaEsquerda > maximoColunas)
		return (abscissaEsquerdaInvalida);
	if (ordenadaDireita > maximoLinhas || ordenadaDireita < ordenadaEsquerda)
		return (ordenadaDireitaInvalida);
	if (abscissaDireita > maximoColunas || abscissaDireita < abscissaEsquerda)
		return (abscissaDireitaInvalida);

	/* Define os pixels do LADO ESQUERDO como aceso */
	for (indiceLinha = ordenadaEsquerda - 1; indiceLinha < ordenadaDireita; indiceLinha++)
		monitor[indiceLinha][abscissaEsquerda-1] = aceso;
	/* Define os pixels do LADO DIREITO como aceso */
	for (indiceLinha = ordenadaEsquerda - 1; indiceLinha < ordenadaDireita; indiceLinha++)
		monitor[indiceLinha][abscissaDireita-1] = aceso;
	/* Define os pixels do LADO SUPERIOR como aceso */
	for (indiceColuna = abscissaEsquerda - 1; indiceColuna < abscissaDireita; indiceColuna++)
		monitor[ordenadaEsquerda - 1][indiceColuna] = aceso;
	/* Define os pixels do LADO INFERIOR como aceso */
	for (indiceColuna = abscissaEsquerda - 1; indiceColuna < abscissaDireita; indiceColuna++)
		monitor[ordenadaDireita - 1][indiceColuna] = aceso;

	/* Exibe o monitor */
	MostrarMonitor (monitor, maximoLinhas, maximoColunas);

	return ok;
}

/* Preenche qualquer poligono a partir de um ponto interno dado */
/* Ao acender cada pixel, chama a funcao MostrarMonitor e exibe o monitor */
/* Coordenadas iniciais: (0,0) */
tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
						unsigned maximoLinhas, unsigned maximoColunas,
						unsigned linha, unsigned coluna)
{

	/* Teste de erro #1: dimensoes acima do permitido (NUMERO_MAXIMO_LINHAS/COLUNAS) */
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
		return (maximoLinhasInvalido);
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
		return (maximoColunasInvalido);

	/* Teste de erro #2: coordenadas do retangulo acima do permitido */
	if (linha > maximoLinhas)
		return (linhaInvalida);
	if (coluna > maximoColunas)
		return (colunaInvalida);

	/* Algoritimo para preecher qualquer poligono
	 * Se o pixel esta aceso:
	 * - nada ocorre
	 * Se o pixel esta apagado:
	 * - acendo o pixel
	 * - executa o algoritimo para os 4 pixels vizinhos */
	if (monitor[linha][coluna] == apagado)
	{
		monitor [linha][coluna] = aceso;

		/* Exibe o monitor apos acender 1 pixel */
		MostrarMonitor (monitor, maximoLinhas, maximoColunas);

		if (linha != maximoLinhas)
			PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha + 1, coluna);
		if (linha != 0)
			PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha - 1, coluna);
		if (coluna != maximoColunas)
			PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha, coluna + 1);
		if (coluna != 0)
			PreencherPoligono (monitor, maximoLinhas, maximoColunas, linha, coluna - 1);
	}


	
	return ok;

}

/* $RCSfile$ */