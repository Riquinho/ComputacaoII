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

#include "aula0201.h"
#include <stdio.h>
#include <stdlib.h>
/* Calcula o Maximo Divisor Comum entre 2 numeros usando 'do ... while' */

ull
CalcularMaximoDivisorComum (ull numeroA, ull numeroB)
{
	ull restoDivisao;

	if ((numeroA == 0) && (numeroB == 0))
		return 0;
	else if (numeroA == 0)
		return numeroB;
	else if (numeroB == 0)
		return numeroA;
	else if ((numeroA % numeroB) == 0)
		return numeroB;
	else if ((numeroA % numeroB != 0))
	{
		do
		{
			restoDivisao = (numeroA % numeroB);
			numeroA = numeroB;
			numeroB = restoDivisao;
		}
		while ((numeroA % numeroB) != 0);
		return numeroB;
		
	}

	return 0;
}

/* $RCSfile$ */