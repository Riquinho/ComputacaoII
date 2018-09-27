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

#define OK				0

int
main (int argc, char *argv[])
{
	printf("\nTipos Basicos\n");

	printf("char:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(char), sizeof(char)<=1 ? "byte" : "bytes");

	printf("int:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(int), sizeof(int)<=1 ? "byte" : "bytes");

	printf("float:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(float), sizeof(float)<=1 ? "byte" : "bytes");

	printf("double:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(double), sizeof(double)<=1 ? "byte" : "bytes");

	printf("void:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(void), sizeof(void)<=1 ? "byte" : "bytes");

	printf("\nModificadores de Sinal\n");

	printf("Signed:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(signed), sizeof(signed)<=1 ? "byte" : "bytes");

	printf("Unsigned:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(unsigned), sizeof(unsigned)<=1 ? "byte" : "bytes");

	printf("\nModificadores de Largura\n");

	printf("Short:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(short), sizeof(short)<=1 ? "byte" : "bytes");

	printf("Long:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(long), sizeof(long)<=1 ? "byte" : "bytes");

	printf("Long Long:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(long long), sizeof(long long)<=1 ? "byte" : "bytes");

	printf("\nModificadores de Sinal combinados com Modificadores de Largura\n");

	printf("Signed Short:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(signed short), sizeof(signed short)<=1 ? "byte" : "bytes");

	printf("Signed Long:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(signed long), sizeof(signed long)<=1 ? "byte" : "bytes");

	printf("Signed Long Long:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(signed long long), sizeof(signed long long)<=1 ? "byte" : "bytes");

	printf("Unsigned Short:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(unsigned short), sizeof(unsigned short)<=1 ? "byte" : "bytes");

	printf("Unsigned Long:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(unsigned long), sizeof(unsigned long)<=1 ? "byte" : "bytes");

	printf("Unsigned Long Long:\n");
	printf("\t\t\t\t%zu %s\n", sizeof(unsigned long long), sizeof(unsigned long long)<=1 ? "byte" : "bytes");

	/* Combinacoes Invalidas */
	printf("Combinacoes Invalidas\n");
	printf("Nao ha");

	printf("\n\t\tTipos Basicos combinados com Modificadores de Sinal\n");

	/* Combinacoes Validas */
	printf("Signed Char:\n");
	printf("\t\t%zu %s\n", sizeof(signed char), sizeof(signed char)<=1 ? "byte" : "bytes");

	printf("Signed Int:\n");
	printf("\t\t%zu %s\n", sizeof(signed int), sizeof(signed int)<=1 ? "byte" : "bytes");

	printf("Unsigned Char\n");
	printf("\t\t%zu %s\n", sizeof(unsigned char), sizeof(unsigned char)<=1 ? "byte" : "bytes");

	printf("Unsigned Int:\n");
	printf("\t\t%zu %s\n", sizeof(unsigned int), sizeof(unsigned int)<=1 ? "byte" : "bytes");

	/* Combinacoes Invalidas */
	printf("Combinacoes Invalidas\n");

	printf("Signed Float\n");
	printf("Signed Double\n");
	printf("Signed Void\n");
	printf("Unsigned Float\n");
	printf("Unsigned Double\n");
	printf("Unsigned Void\n");

	
	return OK;

}

