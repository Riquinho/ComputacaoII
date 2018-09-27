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

#include "aula0701.h"

void
MultiplicarMatrizes (float matrizA [MATRIZ_A_LINHAS][MATRIZ_A_COLUNAS], 
							float matrizB [MATRIZ_B_LINHAS][MATRIZ_B_COLUNAS],
							float matrizProduto [MATRIZ_A_LINHAS][MATRIZ_B_COLUNAS])
{

unsigned indiceLinhaMatrizA, indiceColunaMatrizA, indiceColunaMatrizB;
float somaTermo;

	for (indiceLinhaMatrizA = 0; indiceLinhaMatrizA < MATRIZ_A_LINHAS; indiceLinhaMatrizA++)
		for (indiceColunaMatrizB = 0; indiceColunaMatrizB < MATRIZ_B_COLUNAS; indiceColunaMatrizB++)
		{
			somaTermo = 0;
			for (indiceColunaMatrizA = 0; indiceColunaMatrizA < MATRIZ_A_COLUNAS; indiceColunaMatrizA++)
				somaTermo += matrizA [indiceLinhaMatrizA][indiceColunaMatrizA] * 
								 matrizB [indiceColunaMatrizA][indiceColunaMatrizB];
			matrizProduto [indiceLinhaMatrizA][indiceColunaMatrizB] = somaTermo;
		}

}

/* $RCSfile$ */