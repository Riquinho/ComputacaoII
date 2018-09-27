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
   unsigned expoenteInverso, contadorExpoente;
   long double resultado;

   /* n^0 = 1; para todo n */
   if (expoente == 0)
      return 1;

   /* 0^n = inf; para todo n < 0 */
   else if ( (base == 0) && (expoente < 0) )
      return (1.0 / 0.0);

   /* n^x = 1 / n*n*n*...*n (-x) vezes; para todo x < 0 */
   else if ( expoente < 0 )
   {
      expoenteInverso = -expoente;
      resultado = 1;
      contadorExpoente = 1;

      do
      {
         resultado = resultado * base;
         contadorExpoente++;
      }
      while (contadorExpoente <= expoenteInverso);

      return (1 / resultado);
   }

   /* n^x = n*n*n*...*n x vezes */
   else
   {
      resultado = 1;
      contadorExpoente = 1;

      do
      {
         resultado = resultado * base;
         contadorExpoente++;
      }
      while (contadorExpoente <= expoente);

      return resultado;
   }
}

/* $RCSfile$ */