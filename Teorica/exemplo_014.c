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

#define OK						0

int main (int argc, char *argv [])
{
  unsigned indice;

  printf ("Numero de argumentos: %i\n", argc);

  for (indice = 0; indice < argc; indice++)
    printf ("ARG# %03u: \"%s\"\n", indice, argv [indice]);
  return OK;
}

/* $RCSfile$ */
