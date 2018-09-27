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

#include "aula0301.h"

ull
CalcularTermoSerieFibonacci (unsigned short valor)
{
	ull valorAnteriorAnterior, valorAnterior, valorSeguinte;
	unsigned short contadorTermo;

	valorAnteriorAnterior = 0;
	valorAnterior = 1;
	valorSeguinte = valorAnterior + valorAnteriorAnterior;
	contadorTermo = 2;

	if (valor <= 1)
		return valor;
	else
	{
		/* Ate que chegue no valor desejado:*/
		while (contadorTermo <= valor)
		{
			valorSeguinte = valorAnterior + valorAnteriorAnterior;
			valorAnteriorAnterior = valorAnterior;
			valorAnterior = valorSeguinte;
			contadorTermo++;
		}
		return valorSeguinte;
	}
}

/* $RCSfile: aula0301d.c,v $ */