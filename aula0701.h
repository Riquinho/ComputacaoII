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

#ifndef _AULA0701_
#define _AULA0701_ "@(#)aula0701.h $Revision: 1.1 $"

#define MATRIZ_A_LINHAS										5
#define MATRIZ_A_COLUNAS									3
#define MATRIZ_B_LINHAS										MATRIZ_A_COLUNAS
#define MATRIZ_B_COLUNAS									4

void
MultiplicarMatrizes (float matrizA [MATRIZ_A_LINHAS][MATRIZ_A_COLUNAS], 
							float matrizB [MATRIZ_B_LINHAS][MATRIZ_B_COLUNAS],
							float matrizProduto [MATRIZ_A_LINHAS][MATRIZ_B_COLUNAS]); 

#endif

/* $RCSfile$ */