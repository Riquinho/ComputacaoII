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


#include <math.h>

float
CalcularSerieHarmonicaAlternada (unsigned long int termos)
{
	/* S(0) = 0 */
	if (termos == 0)
		return 0;
	/* Se n eh par --> S(n) = S(n-1) - 1/n^n */
	else if ((termos % 2) == 0)
		return (CalcularSerieHarmonicaAlternada(termos - 1) - (1 / pow(termos, termos)));
	/* Se n eh impar --> S(n) = S(n-1) + 1/n^n */
	else
		return (CalcularSerieHarmonicaAlternada(termos - 1) + (1 / pow(termos, termos)));
}

/* $RCSfile$ */