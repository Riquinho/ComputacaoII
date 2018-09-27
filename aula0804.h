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

#ifndef _AULA0804_
#define _AULA0804_ "@(#)aula0804.h $Revision: 1.1 $"

#define COMPRIMENTO_IDENTIFICADOR									11

#define PONTEIRO_NULO_FUNCAO											11
#define COMPRIMENTO_INVALIDO_FUNCAO									12
#define DIGITO_INVALIDO_FUNCAO										13

typedef enum {falso, verdadeiro} boolean;

char
GerarDigitoVerificadorPisPasep (char *identificadorPisPasep);

boolean 
ValidarPisPasep (char *identificadorPisPasep);

#endif

/* $RCSfile$ */