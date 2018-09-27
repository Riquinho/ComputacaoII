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

/* Tab size: 3 */

/* OBJETIVO: Converter um arquivo texto do formato UNIX para formato DOS.
 * 
 * UNIX: \n
 * DOS:  \r\n
 *
 */


/* Tab Size: 3 */

/* OBJETIVO: Converter um arquivo texto do formato DOS  para formato UNIX.
 * 
 * UNIX: \n
 * DOS:  \r\n
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE										500
#endif

#ifdef __FreeBSD__
#define _WITH_DPRINTF

#if (__FreeBSD__ == 9)
#include <unistd.h>
#endif

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define OK														0
#define NUMERO_ARGUMENTOS_INVALIDO						1
#define COMPRIMENTO_NOME_ARQUIVO_INVALIDO				2
#define ERRO_ABRINDO_ARQUIVO								3
#define ERRO_LENDO_ARQUIVO									4
#define ERRO_ESCREVENDO_ARQUIVO							5
#define ERRO_FECHANDO_ARQUIVO								6

#define NUMERO_ARGUMENTOS									2
#define COMPRIMENTO_NOME_ARQUIVO							1024
#define COMPRIMENTO_MAXIMO_BUFFER						10
#define BACKUP_EXTENSAO										".bak"
#define EOS														'\0'

int
main (int argc, char *argv[ ])
{
	FILE *arquivoOriginal, *arquivoTemporario;
	char nomeArquivoTemporario [COMPRIMENTO_NOME_ARQUIVO];
	char nomeArquivoBackup [COMPRIMENTO_NOME_ARQUIVO];
	int descritorArquivoTemporario;
	char buffer [COMPRIMENTO_MAXIMO_BUFFER + 1];

	/* Erro #01: Numero invalido de argumentos */
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nErro 1.%02i: Numero invalido de argumentos!\n", NUMERO_ARGUMENTOS_INVALIDO);
		printf ("Foram inseridos %i de %i argumentos.\n", (argc - 1), (NUMERO_ARGUMENTOS - 1));
		printf ("Use: %s <arquivo>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/* Erro #02: Comprimento do nome do arquivo invalido 
	 * -4 = ".bak"
	 * -1 = EOS */
	if (strlen (argv [1]) > COMPRIMENTO_NOME_ARQUIVO - 4 - 1)
	{
		printf ("\nErro 1.%02i: Comprimento invalido do nome do arquivo.\n", COMPRIMENTO_NOME_ARQUIVO_INVALIDO);
		printf ("Comprimento maximo: %i caracteres", COMPRIMENTO_NOME_ARQUIVO - 5);
		exit (COMPRIMENTO_NOME_ARQUIVO_INVALIDO);
	}

	arquivoOriginal = fopen (argv [1], "r");

	/* Erro #03: Falha ao abrir o arquivo original. */
	if (arquivoOriginal == NULL)
	{
		printf ("Erro ao abrir o arquivo: \"%s\"\n", argv [1]);
		printf ("Erro (#%02i): %s\n", errno, strerror (errno));
		exit (ERRO_ABRINDO_ARQUIVO);
	}

	strcpy (nomeArquivoTemporario, "arquivoTemporario-XXXXXX");
	descritorArquivoTemporario = mkstemp (nomeArquivoTemporario);

	/* Erro #04: Falha ao criar o arquvio temporario. */
	if (descritorArquivoTemporario == -1)
	{
		printf ("Erro ao criar o arquivo temporario.\n");
		printf ("Erro (#%2i): %s\n", errno, strerror (errno)); 
		fclose (arquivoOriginal); 
		exit (ERRO_ABRINDO_ARQUIVO);
	}

	arquivoTemporario = fdopen (descritorArquivoTemporario, "w");

	/* Erro #05: Falha ao abrir arquivo temporario para escrita. */
	if (arquivoTemporario == NULL)
	{
		printf ("Erro ao abrir o arquivo temporario.\n");
		printf ("Erro (#%2i): %s\n", errno, strerror (errno));
		fclose (arquivoOriginal);
		exit (ERRO_ABRINDO_ARQUIVO);
	}

	/* Faz conversao DOS-UNIX armazenando o resultado no arquivo temporario */
	while ((fgets (buffer, COMPRIMENTO_MAXIMO_BUFFER + 1, arquivoOriginal)) != NULL)
	{
		/* 2 caracteres de quebra linha no final do buffer */
		if ((buffer [strlen (buffer) - 2] == '\r') && (buffer [strlen (buffer) - 1]) == '\n')
		{
			buffer [strlen (buffer) - 2] = EOS;
			fprintf (arquivoTemporario, "%s\n", buffer);
		}
		/* Caractere '\r' na ultima posicao do buffer e '\n' na posicao seguinte */
		else if (buffer [strlen (buffer) - 1] == '\r')
		{
			buffer [strlen (buffer) - 1] = EOS;
			fprintf (arquivoTemporario, "%s", buffer);
		}
		/* Buffer no meio de uma linha / buffer so com '\n' */
		else
			fprintf (arquivoTemporario, "%s", buffer);
	}

	/* Erro #06: Falha ao ler arquivo original. */
	if (ferror (arquivoOriginal))
	{
		printf ("Erro lendo arquivo: \"%s\"\n", argv [1]);
		printf ("Erro (#%i): %s\n", errno, strerror (errno));
		fclose (arquivoOriginal);
		fclose (arquivoTemporario);
		remove (nomeArquivoTemporario);
		exit (ERRO_LENDO_ARQUIVO);
	}

	/* Erro #07: Falha ao escrever arquivo temporario. */
	if (ferror (arquivoTemporario))
	{
		printf ("Erro escrevendo arquivo temporario.\n");
   	printf ("Erro (#%i): %s\n", errno, strerror (errno));
		fclose (arquivoOriginal);
		fclose (arquivoTemporario);
		remove (nomeArquivoTemporario);
		exit (ERRO_ESCREVENDO_ARQUIVO);
	}
	
	/* Renomeia o arquivo original.
	 * Adiciona a extencao ".bak". */
	snprintf (nomeArquivoBackup, 20 , "%s%s", argv [1], BACKUP_EXTENSAO);
	rename (argv [1], nomeArquivoBackup);

	/* Renomeia o arquivo temporario.
	 * Muda para o antigo nome do arquivo original. */
	rename (nomeArquivoTemporario, argv [1]);
	
	/* Erro #08: Falha ao fechar o arquivo de backup. */
	if (fclose(arquivoOriginal) != 0)
	{
		printf ("Falha ao fechar arquivo: \"%s\"\n", nomeArquivoBackup);
		printf ("Verifique se os arquivos foram corrompidos.\n");
		printf ("Erro (#%i): %s\n", errno, strerror (errno));
		fclose (arquivoTemporario);
		exit (ERRO_FECHANDO_ARQUIVO);
	}

	/* Erro #09: Falha ao fechar o novo arquivo. */
	if (fclose(arquivoTemporario) != 0)
	{
		printf ("Falha ao fechar o arquivo \"%s\"\n", nomeArquivoTemporario);
		printf ("Verifique se os arquivos foram corrompidos.\n");
		printf ("Erro (#%i): %s\n", errno, strerror (errno));
		exit (ERRO_FECHANDO_ARQUIVO);
	}

	printf ("-------------------------------------------\n");
	printf (" Conversao DOS-UNIX realizada com sucesso!\n\n");
	printf (" (UNIX) Arquivo: \"%s\"\n", argv [1]);
	printf (" (DOS)   Backup: \"%s\"\n", nomeArquivoBackup);
	printf ("-------------------------------------------\n");

	return OK;
}


/* $RCSfile$ */