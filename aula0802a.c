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

#define OK															0
#define NUMERO_ARGUMENTOS_INVALIDO 							1
#define ARGUMENTO_NEGATIVO										2
#define ARGUMENTO_INVALIDO										3
#define ARGUMENTO_MUITO_GRANDE								4

#define DIGITO_INVALIDO 										5

#define NUMERO_ARGUMENTOS										COMPRIMENTO_IDENTIFICADOR - 1 + 1
#define EOS															'\0'

int
main (int argc, char *argv [ ])
{
	unsigned indiceArgumento;
	unsigned long long valor;
	byte identificadorPisPasep [COMPRIMENTO_IDENTIFICADOR - 1];
	byte digitoVerificador;
	char *validacao;
	
	/* Teste de erro #1: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <d01> <d02> <d03> ... <d%i> \n\n", argv [0], COMPRIMENTO_IDENTIFICADOR-1);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indiceArgumento = 1; indiceArgumento < argc; indiceArgumento++)
	{
		/* Teste de erro #2: Argumento negativo */
		if (argv [indiceArgumento][0] == '-')
		{
			printf ("\nErro 1.%i: Argumento #%u contem caractere invalido.\n", ARGUMENTO_NEGATIVO, indiceArgumento)	;
			printf ("Caractere invalido: '-'\n\n");
			exit (ARGUMENTO_NEGATIVO);
		}
	
		valor = strtoull (argv [indiceArgumento], &validacao, 10);

		/* Teste de erro #3: Argumento com caractere invalido */
		if (*validacao != EOS)
		{
			printf ("\nErro 1.%i: Argumento #%u contem caractere invalido.\n", ARGUMENTO_INVALIDO, indiceArgumento);
			printf ("Caractere invalido: %c\n\n", *validacao);
			exit (ARGUMENTO_INVALIDO);
		}
	
		/* Teste de erro #4: Valor do argumento > 255 */
		if (valor > 255)
		{
			printf ("\nErro 1.%i: Argumento #%u acima do permitido.\n", ARGUMENTO_MUITO_GRANDE, indiceArgumento);
			printf ("Valor incorreto: %llu\n\n", valor);
			exit (ARGUMENTO_MUITO_GRANDE);
		}
	
		identificadorPisPasep [indiceArgumento - 1] = (byte) valor;
	}

	digitoVerificador = GerarDigitoVerificadorPisPasep (identificadorPisPasep);

	/* Teste de erro #5: Elemento do vetor com mais de 1 digito */
	if (digitoVerificador == DIGITO_INVALIDO_FUNCAO)
	{
		printf ("\nErro 1.%i: digito maior que 9\n\n", DIGITO_INVALIDO);
		exit (DIGITO_INVALIDO);
	}
	
	printf ("\nDigito Verificador: %u\n\n", digitoVerificador);

	return OK;
}

/* $RCSfile$ */