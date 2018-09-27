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
  ULL resultado = 1;

  while (numero > 1)
  {
    resultado = resultado * numero;
    /* resultado *= numero; */
    numero--;
  }

  return resultado;
}

/* $RCSfile$ */
