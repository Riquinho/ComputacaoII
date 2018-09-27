/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2018/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * $Author$
 * $Date$
 * $Log$
 */

#include <stdio.h>
#include <stdlib.h>

#include "exemplo_024.h"

#define NUMERO_ARGUMENTOS             2           

#define OK				                    0
#define NUMERO_ARGUMENTOS_INVALIDO    1
#define CARACTERE_INVALIDO            2

#define EOS                           '\0'

int 
main (int argc, char *argv [])
{
  BYTE numero;
  unsigned indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <inteiro-nao-negativo>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  for (indice = 0; argv [1][indice] != EOS; ++indice)
    if (argv [1][indice] < '0' || argv [1][indice] > '9')
    {
      printf ("Argumento contem caractere invalido: \"%c\"\n", argv [1][indice]);
      exit (CARACTERE_INVALIDO);
    }  

  numero = (BYTE) atoi (argv [1]);

  printf ("%s!: %llu\n", argv [1], CalcularFatorial (numero));
  return OK;
}

/* $RCSfile$ */
