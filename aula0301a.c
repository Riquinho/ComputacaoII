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
	if (valor <= 1)
		return valor;
	else
		return (CalcularTermoSerieFibonacci(valor - 1) + CalcularTermoSerieFibonacci(valor - 2));
}

/* $RCSfile: aula0301a.c,v $ */