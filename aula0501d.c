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


#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada (unsigned long int termos)
{
	float resultado;
	unsigned long int indiceTermos;

	/* S(0) = 0 */
	if (termos == 0)
		return 0;
	/* Repete S(1) + S(2) + ... , ate S(n) */
	else
	{
		resultado = 0;
		indiceTermos = 1;
		while (indiceTermos <= termos)
		{	
			/* indiceTermos par */
			if (indiceTermos % 2 == 0)
				resultado = resultado - (1/(CalcularExponencial(indiceTermos,indiceTermos)));
			/* indiceTermos impar */
			else
				resultado = resultado + (1/(CalcularExponencial(indiceTermos,indiceTermos)));
	
			indiceTermos++;
		}
		return resultado;
	}
}

/* $RCSfile$ */