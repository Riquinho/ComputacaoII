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

#include "exemplo_024.h"

ULL
CalcularFatorial (BYTE numero)
{
  #ifdef _MY_DEBUG_
  #include <stdio.h>
  static unsigned instancia = 0;
  printf ("Instancia: %u\n", instancia);
  instancia++;
  #endif

  if (numero <= 1)
    return 1;

  return numero * CalcularFatorial (numero -1);
}

/* $RCSfile$ */
