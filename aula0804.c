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
#include <string.h>
#include "aula0804.h"

/* GERAR DIGITO VERIFICADOR PIS PASEP
 * ----------------------------------
 * > Recebe string dos digitos do identificador PIS/PASEP.
 * > Retorna o digito verificador PIS/PASEP do identificador dado. */
char
GerarDigitoVerificadorPisPasep (char *identificadorPisPasep)
{
	unsigned short indiceDigito;
	char pesos [COMPRIMENTO_IDENTIFICADOR - 1] = {3,2,9,8,7,6,5,4,3,2};
	unsigned somaResultados, resto;

	/* Teste de erro #1: Recebe ponteiro nulo */
	if (identificadorPisPasep == NULL)
		return PONTEIRO_NULO_FUNCAO;

	/* Teste de erro #2: Comprimento invalido da string */
	if (strlen (identificadorPisPasep) != COMPRIMENTO_IDENTIFICADOR - 1)
		return COMPRIMENTO_INVALIDO_FUNCAO;

	/* Inicia a variavel */
	somaResultados = 0;

	for (indiceDigito = 0; indiceDigito < COMPRIMENTO_IDENTIFICADOR - 1; indiceDigito++)
	{
		/* Teste de erro #3: digito nao-numerico*/
		if (identificadorPisPasep [indiceDigito] > '9' ||
			identificadorPisPasep [indiceDigito] < '0')
			return (DIGITO_INVALIDO_FUNCAO);

		/* Multiplica o digito pelo peso da sua posicao. */
		somaResultados += (identificadorPisPasep [indiceDigito] - '0') * (pesos [indiceDigito]);
	}
	
	resto = somaResultados % 11 - '0';

	if (resto == 0 - '0' || resto == 1 - '0')
		return '0';
	
	return (11 - resto);
}

/* VALIDAR PIS PASEP
 * -----------------
 * > Recebe string do identificador PIS/PASEP + '-' + digito verificador
 * > Retrona:
 * > > falso (= 0) para digito verificador invalido ou qualquer erro
 * > > verdadeiro(= 1) para digito verificador valido */
boolean 
ValidarPisPasep (char *identificadorPisPasep)
{
	unsigned short indiceDigito;
	char identificadorAuxiliar [COMPRIMENTO_IDENTIFICADOR];
	char digitoVerificador;

	/* Teste de erro #1: recebe ponteiro nulo */
	if (identificadorPisPasep == NULL)
		return falso;

	/* Teste de erro #2: comprimento da string invalido */
	if (strlen (identificadorPisPasep) != COMPRIMENTO_IDENTIFICADOR + 1)
		return falso;

	/* Teste de erro #3: verifica se penultimo digito e' hifen (-) */
	if (identificadorPisPasep [COMPRIMENTO_IDENTIFICADOR - 1] != '-')
		return falso;

	for (indiceDigito = 0; indiceDigito < COMPRIMENTO_IDENTIFICADOR - 1; indiceDigito++)
	{
		/* Teste de erro #5: digito (1...antepenultimo) invalido */
		if (identificadorPisPasep [indiceDigito] > '9' ||
			identificadorPisPasep [indiceDigito] < '0')
			return falso;

		identificadorAuxiliar [indiceDigito] = identificadorPisPasep [indiceDigito];

	}

	/* Ultimo elemento do vetor de char e' EOS, caracterizando como string */
	identificadorAuxiliar [indiceDigito] = '\0';

	digitoVerificador = GerarDigitoVerificadorPisPasep(identificadorAuxiliar);

	if (identificadorPisPasep[COMPRIMENTO_IDENTIFICADOR] != digitoVerificador)
		return falso;

	return verdadeiro;
}

/* $RCSfile$ */