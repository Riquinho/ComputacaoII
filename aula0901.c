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

/* TAB size = 3 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aula0901.h"

/* <FUNCOES LOCAIS> */

/* | f1 - AcharPosicaoChar |
 * Acha a primeira posicao de um caractere em uma string.
 * Retorna o valor da posicao do char no vetor de char.
 * Retorna 65 se nao encontrar o caractere.
 * Uso: - Verificar se a funcao DecodificarBase64 recebe apenas
 			 elementos da tabela Base64.
		  - Achar o valor de uma char na tabela Base64. */
byte
AcharPosicaoChar (char *string, char caractere)
{
	char *posicaoCharPtr;
	unsigned caractereNaoEncontrado = 65;
	
	posicaoCharPtr = strchr(CONJUNTO_BASE_64, caractere);
	
	if (posicaoCharPtr == NULL)
		return caractereNaoEncontrado;

	return (byte) (posicaoCharPtr - string);
}

/* | f2 - FrequenciaChar |
 * Calcula quantas vezes um caractere aparece em uma string.
 * Retorna o numero de aparicoes do caractere.
 * Retorna zero se nao encontrar o caractere.
 * Uso: - Tratamento de Erro #04: uso incorreto de paddings */
unsigned
FrequenciaChar (char *string, char caractere)
{
	unsigned contadorRepeticao;
	unsigned indiceCaracteres;

	contadorRepeticao = 0;

	for (indiceCaracteres = 0; indiceCaracteres < strlen (string); indiceCaracteres++)
		if (string [indiceCaracteres] == caractere)
			contadorRepeticao++;

	return contadorRepeticao;
}
/* </FUNCOES LOCAIS> */
	
tipoErros
CodificarBase64 (byte *entrada, unsigned numeroBytes, char *saida)
{
	unsigned indiceEntrada, indiceSaida;
	unsigned resto;

	/* Erro #01: Funcao recebe ponteiro nulo */
	if (entrada == NULL)
		return ponteiroNulo;

	/* Erro #02: Argumento contem caractere invalido.
	 * 		  	 Valores abaixo de 33 e iguais a 127 na 
	 *				 tabela ASCII estendida sao invalidos. 
	 * 			 Nao verifica maiores de 255 pois so'
	 * 			 recebe entradas do tipo byte. 			*/
	for (indiceEntrada = 0; indiceEntrada < numeroBytes; indiceEntrada++)
		if (entrada [indiceEntrada] < 32 || entrada [indiceEntrada] == 127 )
			return caractereInvalido;

	indiceSaida = indiceEntrada = 0;

	while ((indiceEntrada % 3 == 0) && (indiceEntrada + 3 <= numeroBytes))
	{
		/* 1. Byte */
		saida [indiceSaida]		= CONJUNTO_BASE_64 [(entrada [indiceEntrada] >> 2) & (0x03F)];
		/* 2. Byte */
		saida [indiceSaida + 1] = CONJUNTO_BASE_64 [((entrada [indiceEntrada] << 4) & (0x30)) | ((entrada [indiceEntrada + 1] >> 4) & (0x0F))];
		/* 3. Byte */
		saida [indiceSaida + 2] = CONJUNTO_BASE_64 [((entrada [indiceEntrada + 1] << 2) & (0x3C)) | ((entrada [indiceEntrada + 2] >> 6) & (0x03))];
		/* 4. Byte */
		saida [indiceSaida + 3] = CONJUNTO_BASE_64 [(entrada [indiceEntrada + 2]) & (0x3F)];
		
		indiceSaida += 4;
		indiceEntrada += 3;

		/* Quebra de linha a cada LINHA_MAX caracteres */
		if (indiceSaida % LINHA_MAX == 0)
		{
			saida [indiceSaida]		= '\r';
			saida [indiceSaida + 1] = '\n';
			indiceSaida += 2;
		}
	}

	resto = numeroBytes - indiceEntrada;

	/* Se restarem 2 bytes de entrada */
	if (resto == 2)
	{
		/* 1. Byte */
		saida [indiceSaida] 		= CONJUNTO_BASE_64 [(entrada [indiceEntrada] >> 2) & (0x3F)];
		/* 2. Byte */
		saida [indiceSaida + 1] = CONJUNTO_BASE_64 [((entrada [indiceEntrada] << 4) & (0x30)) | 
																  ((entrada [indiceEntrada + 1] >> 4) & (0x0F))];
		/* 3. Byte */
		saida [indiceSaida + 2] = CONJUNTO_BASE_64 [(entrada [indiceEntrada + 1] << 2) & (0x3C)];
		/* 4. Byte */
		saida [indiceSaida + 3] = '=';

		indiceSaida += 4;
		indiceEntrada += 2;
	}

	/* Se restarem 1 byte de entrada */
	if (resto == 1)
	{	
		/* 1. Byte */
		saida [indiceSaida]	   = CONJUNTO_BASE_64 [(entrada [indiceEntrada] >> 2) & (0x3F)];
		/* 2. Byte */
		saida [indiceSaida + 1] = CONJUNTO_BASE_64 [(entrada [indiceEntrada] << 4) & (0x30)];
		/* 3. Byte */
		saida [indiceSaida + 2] = '=';
		/* 4. Byte */
		saida [indiceSaida + 3] = '=';

		indiceSaida += 4;
		indiceEntrada += 1;
	}

	/* EOS no ultimo caractere da string */
	saida [indiceSaida] = '\0';
	indiceSaida++;

	return ok;
}

tipoErros
DecodificarBase64 (char *entrada, byte *saida, unsigned *numeroBytes)
{
	/* Declaracao de variaveis locais */
	unsigned indiceEntrada, indiceSaida;
	unsigned indiceBytes;
	unsigned comprimentoEntrada;

	/* Erro #01: Funcao recebe ponteiro nulo */
	if (entrada == NULL)
		return ponteiroNulo;
 
	/* Erro #02: A entrada contem caractere (alem de '=', '\r' e '\n')
	 * 			 que nao pertence 'a Base64.		*/
	for (indiceEntrada = 0; indiceEntrada < strlen (entrada); indiceEntrada++)
	{
		if (AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada]) == 65  &&
			 entrada [indiceEntrada] != '\r' &&  entrada [indiceEntrada] != '\n' &&
			 entrada [indiceEntrada] != '=')
			return caractereInvalido;
	}

	/* Erro #03: O comprimento da entrada, ignorando os caracteres '\n',
	 *				 nao e' zero ou multiplo de 4.	*/
	comprimentoEntrada = (strlen (entrada) - (FrequenciaChar (entrada, '\r') + FrequenciaChar (entrada, '\n')));
	if (comprimentoEntrada % 4 != 0 && comprimentoEntrada != 0)
		return comprimentoInvalido; 
	
	/* Erro #04: Uso indevido do padding */
	/* 1. Mais de 2 paddings */
	if (FrequenciaChar (entrada, '=') > 2)
		return paddingInvalido;
	/* 2. Presenca de 2 paddings fora das ultimas posicoes */
	if ((FrequenciaChar (entrada, '=') == 2)	  &&
		 ((entrada [strlen (entrada) - 2] != '=') ||
		  (entrada [strlen (entrada) - 1] != '=')))
		 return paddingInvalido;
	/* 3. Presenca de 1 paddings fora da ultima posicao */
	if ((FrequenciaChar (entrada, '=') == 1) &&
		 (entrada [strlen (entrada) - 1] != '='))
		return paddingInvalido;

	/* Calculo dos valores do vetor 'saida[]' */
	indiceEntrada = indiceSaida = 0;
	while (indiceEntrada + 4 <= strlen(entrada))
	{
		if (entrada [indiceEntrada] == '\r' &&
			 entrada [indiceEntrada + 1] == '\n')
			indiceEntrada += 2;

		/* Digito 1 (sempre existe) */
		saida [indiceSaida] = ((AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada]) << 2)) |
									 ((AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada + 1]) >> 4));
		
		/* 2 paddings --> nao ha' digito 2 e 3 */
		if (entrada [indiceEntrada + 2] == '=')
			indiceSaida -= 2;

		/* 1 padding  --> nao ha' digito 3 */
		else if (entrada [indiceEntrada + 3] == '=')
		{
			/* Digito 2 */
			saida [indiceSaida + 1] = ((AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada + 1]) << 4) )|
											  ((AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada + 2]) >> 2) );
			indiceSaida -= 1;
		}

		/* Nenhum padding --> ha' digito 2 e 3 */
		else
		{	
			/* Digito 2 */
			saida [indiceSaida + 1] = ((AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada + 1]) << 4) )|
											  ((AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada + 2]) >> 2) );
			/* Digito 3 */
			saida [indiceSaida + 2] = ((AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada + 2]) << 6) ) |
											  (AcharPosicaoChar (CONJUNTO_BASE_64, entrada [indiceEntrada + 3]) );
		}

		indiceEntrada += 4;
		indiceSaida   += 3;
	}

	/* Tamanho do vetor de bytes 'saida[]' */
	*numeroBytes = indiceSaida;

	/* Erro #05: Codigo inserido invalido.
	 *				 Decodificacao retorna valor fora da faixa permitida
	 *				 da tabela ASCII estendida.
	 *				 Faixa permitida: 33 ate 255 (!= 127). */
	for (indiceBytes = 0; indiceBytes < *numeroBytes; indiceBytes++)
		if ((saida [indiceBytes] < 33) | (saida [indiceBytes] == 127))
			return codigoInvalido;

	return ok;
}


/* $RCSfile$ */