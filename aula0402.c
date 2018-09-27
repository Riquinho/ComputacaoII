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

#include <stdio.h>
#include <stdlib.h>

#include "aula0401.h"

#define OK                                      0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define ARGUMENTO_INVALIDO                      2

#define NUMERO_ARGUMENTOS                       3  

#define EOS                                     '\0'

int
main (int argc, char *argv [ ])
{
   char *validacao;
   double base;
   int expoente;

   /* Teste de erro #1: Numero invalido de argumentos */
   if (argc != NUMERO_ARGUMENTOS)
   {
      printf ("\nNumero invalido de argumentos!\n");
      printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
      printf ("Use: %s <base> <expoente>\n\n", argv [0]);
      exit (NUMERO_ARGUMENTOS_INVALIDO);
   }

   /* Teste de erro #2: Argumento #1 (base) nao eh real */
   base = strtod (argv[1], &validacao);
   if (*validacao != EOS)
   {
      printf ("\nArgumento #1 caracteres invalidos.\nInsira apenas numeros reais.\n");
      printf ("Use: %s <real> <inteiro>\n\n", argv [0]);
      exit (ARGUMENTO_INVALIDO);
   }
 
   /* Teste de erro #3: Argumento #2 (expoente) nao eh inteiro */
   expoente = strtol (argv[2], &validacao, 10);
   if (*validacao != EOS)  
   {
      printf ("\nArgumento #2 contem caracteres invalidos.\nInsira apenas numeros inteiros.\n");
      printf ("Use: %s <real> <inteiro>\n\n", argv [0]);
      exit (ARGUMENTO_INVALIDO);
   }

   /* Titulo */
   printf ("\nCALCULO DE EXPONENCIAL\n\n");

   /* Exibe: (base)^(expoente) = resultado */
   printf ("(%g)^(%d) = %Lf\n\n", base, expoente, CalcularExponencial (base,expoente));

   return OK;
}

/* $RCSfile$ */