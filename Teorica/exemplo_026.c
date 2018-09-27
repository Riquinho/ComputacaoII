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

#define OK 0

typedef unsigned char byte;

int 
main (int argc, char *argv [])
{
  byte indice;

  for (indice = 0; indice < 256; indice++);
    printf ("%03u\t%03X\t%c\n", indice, indice, indice);
 
  return OK;
}

/* $RCSfile$ */
