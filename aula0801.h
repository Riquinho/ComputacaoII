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


#ifndef _AULA0801_
#define _AULA0801_ "@(#)aula0801.h $Revision: 1.1 $"

#define COMPRIMENTO_IDENTIFICADOR									11

#define DIGITO_INVALIDO_FUNCAO										10

typedef unsigned char byte;

typedef enum {falso, verdadeiro} boolean;

byte 
GerarDigitoVerificadorPisPasep (byte identificadorPisPasep[COMPRIMENTO_IDENTIFICADOR - 1]);

boolean 
ValidarPisPasep (byte identificadorPisPasep[COMPRIMENTO_IDENTIFICADOR]);

#endif

/* $RCSfile$ */