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

	return OK;

}

