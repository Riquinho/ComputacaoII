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

long double
CalcularExponencial (double base, int expoente)
{
   /* n^0 = 1; para todo n */
   if (expoente == 0)
      return 1;

   /* 0^n = inf; para todo n < 0 */
   else if ( (base == 0) && (expoente < 0) )
      return (1.0 / 0.0);

   /* n^x = 1 / n^(-x); para todo x < 0 */
   else if ( expoente < 1 )
      return ( 1 / ( CalcularExponencial( base, (-expoente ) ) ) );

   /* n^x = n * n^(x-1) */
   else     
      return ( base * CalcularExponencial( base, (expoente - 1) ) );
}
/* $RCSfile$ */