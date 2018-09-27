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

#define OK				          0

#define NUMERO_ARGUMENTOS   2

int main (int argc, char *argv [])
{
  unsigned numero;

  if (argc != NUMERO_ARGUMENTOS)
    printf ("Uso: %s <inteiro-nao-negativo>\n", argv [0]);
  else 
  {
    numero = (unsigned) atoi (argv [1]);

    if ((numero % 2) == 0)
      printf ("%u eh par\n", numero);
    else
      printf ("%u eh impar\n", numero);
  }

  return OK;
}

/* $RCSfile$ */
