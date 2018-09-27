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

#ifndef _AULA0901_
#define _AULA0901_ "@(#)aula0901.h $Revision$"

#define STRING_MAX														1050 + 1
#define LINHA_MAX															76
#define CONJUNTO_BASE_64												"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

typedef unsigned char byte;

typedef enum {ok, ponteiroNulo, caractereInvalido, comprimentoInvalido, paddingInvalido, codigoInvalido} tipoErros;

tipoErros
CodificarBase64 (byte *entrada, unsigned numeroBytes, char *saida);

tipoErros
DecodificarBase64 (char *entrada, byte *saida, unsigned *numeroBytes);

#endif


/* $RCSfile$ */