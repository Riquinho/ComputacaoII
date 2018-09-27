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
#include "aula0801.h"

/* GERAR DIGITO VERIFICADOR PIS PASEP
 * ----------------------------------
 * > Recebe vetor de bytes dos digitos do identificador PIS/PASEP.
 * > Retorna o digito verificador PIS/PASEP do identificador dado. */
byte 
GerarDigitoVerificadorPisPasep (byte identificadorPisPasep[COMPRIMENTO_IDENTIFICADOR - 1])
{
	unsigned indiceDigito;
	byte pesos [COMPRIMENTO_IDENTIFICADOR - 1] = {3,2,9,8,7,6,5,4,3,2};
	unsigned somaResultados, resto;

	somaResultados = 0;

	for (indiceDigito = 0; indiceDigito < COMPRIMENTO_IDENTIFICADOR - 1; indiceDigito++)
	{
		/* Tratamento de Erro: digito > 9 */
		if (identificadorPisPasep[indiceDigito] > 9)
			return (DIGITO_INVALIDO_FUNCAO);
		somaResultados += identificadorPisPasep[indiceDigito]*pesos[indiceDigito];
	}
	
	resto = somaResultados % 11;

	if (resto == 0 || resto == 1)
		return 0;
	
	return (11 - resto);
}

/* VALIDAR PIS PASEP
 * -----------------
 * > Recebe o vetor de bytes dos digitos do identificaas PIS/PASEP + digito verificador
 * > Retrona:
 * > > falso (= 0) para digito verificador invalido ou para qualquer erro.
 * > > verdadeiro(= 1) para digito verificador valido */
boolean 
ValidarPisPasep (byte identificadorPisPasep[COMPRIMENTO_IDENTIFICADOR])
{
	unsigned indiceDigito;
	byte digitoVerificador;

	for (indiceDigito = 0; indiceDigito < COMPRIMENTO_IDENTIFICADOR; indiceDigito++)
	{
		/* Tratamento de Erro: digito > 9 */
		if (identificadorPisPasep[indiceDigito] > 9)
			return falso;
	}

	digitoVerificador = GerarDigitoVerificadorPisPasep(identificadorPisPasep);

	if (identificadorPisPasep[COMPRIMENTO_IDENTIFICADOR - 1] != digitoVerificador)
		return falso;

	return verdadeiro;
}

/* $RCSfile$ */