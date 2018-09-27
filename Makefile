#   Universidade Federal do Rio de Janeiro 
#   Escola Politecnica 
#   Departamento de Eletronica e de Computacao 
#   EEL270 - Computacao II - Turma 2018/1
#   Prof. Marcelo Luiz Drumond Lanza 
#   Autor: Joao Victor Carvalho Rito 
#
#   $Author$ 
#   $Date$ 
#   $Log$
#
#

CC = gcc
LD = gcc

CFLAGS = -Wall -ansi -std=c99
LFLAGS = -Wall -ansi

AULA0101OB = aula0101.o
AULA0102OB = aula0102.o
AULA0103OB = aula0103.o
AULA0104OB = aula0104.o
AULA0105OB = aula0105.o
AULA0106OB = aula0106.o
AULA0107OB = aula0107.o

AULA0202AOBJS = aula0201a.o aula0202.o
AULA0202BOBJS = aula0201b.o aula0202.o
AULA0202COBJS = aula0201c.o aula0202.o
AULA0202DOBJS = aula0201d.o aula0202.o

AULA0302AOBJS = aula0301a.o aula0302.o
AULA0302BOBJS = aula0301b.o aula0302.o
AULA0302COBJS = aula0301c.o aula0302.o
AULA0302DOBJS = aula0301d.o aula0302.o

AULA0402AOBJS = aula0401a.o aula0402.o
AULA0402BOBJS = aula0401b.o aula0402.o
AULA0402COBJS = aula0401c.o aula0402.o
AULA0402DOBJS = aula0401d.o aula0402.o

AULA0502AOBJS = aula0501a.o aula0502.o
AULA0502BOBJS = aula0501b.o aula0502.o
AULA0502COBJS = aula0501c.o aula0502.o
AULA0502DOBJS = aula0501d.o aula0502.o
AULA0502EOBJS = aula0501e.o aula0502.o

LIBMATEMATICAOBJS = aula0401a.o
LIBMATEMATICA = libmatematica.a

AULA0602OBJS = aula0601.o aula0602.o

AULA0702OBJS = aula0701.o aula0702.o

AULA0802AOBJS = aula0802a.o aula0801.o
AULA0802BOBJS = aula0802b.o aula0801.o
AULA0803AOBJS = aula0803a.o aula0801.o
AULA0803BOBJS = aula0803b.o aula0801.o
AULA0805AOBJS = aula0805a.o aula0804.o
AULA0805BOBJS = aula0805b.o aula0804.o
AULA0806AOBJS = aula0806a.o aula0804.o
AULA0806BOBJS = aula0806b.o aula0804.o

AULA0902OBJS = aula0901.o aula0902.o
AULA0903OBJS = aula0901.o aula0903.o

AULA1001OBJS = aula1001.o
AULA1002OBJS = aula1002.o



AULA01 =	aula0101\
			aula0102\
			aula0103\
			aula0104\
			aula0105\
			aula0106\
			aula0107

AULA02 = 	aula0202a\
			aula0202b\
			aula0202c\
			aula0202d

AULA03 = 	aula0302a\
			aula0302b\
			aula0302c\
			aula0302d

AULA04 = 	aula0402a\
			aula0402b\
			aula0402c\
			aula0402d

AULA05 = 	aula0502a\
			aula0502b\
			aula0502c\
			aula0502d\
			aula0502e

AULA06 = 	aula0602

AULA07 = 	aula0702

AULA08 = 	aula0802a\
			aula0802b\
			aula0803a\
			aula0803b\
			aula0805a\
			aula0805b\
			aula0806a\
			aula0806b


AULA09 = 	aula0902\
			aula0903

AULA10 = 	aula1001\
			aula1002

AULAS =		$(AULA01)\
			$(AULA02)\
			$(AULA03)\
			$(AULA04)\
			$(AULA05)\
			$(AULA06)\
			$(AULA07)\
			$(AULA08)\
			$(AULA09)\
			$(AULA10)


ALL = 		$(AULAS)\
			$(LIBS)

# Regra Implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

aula0101: $(AULA0101OB)
	$(LD) $(LFLAGS) -o $@ $(AULA0101OB)

aula0102: $(AULA0102OB)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OB)

aula0103: $(AULA0103OB)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OB)

aula0104: $(AULA0104OB)
	$(LD) $(LFLAGS) -o $@ $(AULA0104OB)

aula0105: $(AULA0105OB)
	$(LD) $(LFLAGS) -o $@ $(AULA0105OB)

aula0106: $(AULA0106OB)
	$(LD) $(LFLAGS) -o $@ $(AULA0106OB)

aula0107: $(AULA0107OB)
	$(LD) $(LFLAGS) -o $@ $(AULA0107OB)

aula02: $(AULA02)

aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)

aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)

aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)

aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)

aula03: $(AULA03)

aula0302a: $(AULA0302AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS)

aula0302b: $(AULA0302BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS)

aula0302c: $(AULA0302COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302COBJS)

aula0302d: $(AULA0302DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS)

aula04: $(AULA04)

aula0402a: $(AULA0402AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS)

aula0402b: $(AULA0402BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402BOBJS)

aula0402c: $(AULA0402COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402COBJS)

aula0402d: $(AULA0402DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402DOBJS)

aula05: $(AULA05)

aula0502a: $(AULA0502AOBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502AOBJS) -L. -lmatematica

aula0502b: $(AULA0502BOBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502BOBJS) -L. -lmatematica

aula0502c: $(AULA0502COBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502COBJS) -L. -lmatematica

aula0502d: $(AULA0502DOBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502DOBJS) -L. -lmatematica

aula0502e: $(AULA0502EOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502EOBJS) -lm

aula06: $(AULA06)

aula0602: $(AULA0602OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602OBJS)

aula07: $(AULA07)

aula0702: $(AULA0702OBJS)
	$(LD) $(LFLGAS) -o $@ $(AULA0702OBJS)

aula08: $(AULA08)

aula0802a: $(AULA0802AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0802AOBJS)

aula0802b: $(AULA0802BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0802BOBJS)

aula0803a: $(AULA0803AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0803AOBJS)

aula0803b: $(AULA0803BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0803BOBJS)

aula0805a: $(AULA0805AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0805AOBJS)

aula0805b: $(AULA0805BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0805BOBJS)

aula0806a: $(AULA0806AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0806AOBJS)

aula0806b: $(AULA0806BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0806BOBJS)

aula09: $(AULA09)

aula0902: $(AULA0902OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0902OBJS)

aula0903: $(AULA0903OBJS)
	$(LD) $(LFLGAS) -o $@ $(AULA0903OBJS) 

aula10: $(AULA10)

aula1001: $(AULA1001OBJS)
	$(LD) $(LFLGAS) -o $@ $(AULA1001OBJS)

aula1002: $(AULA1002OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA1002OBJS)

clean:
	rm -f *.o $(AULAS)

# $RCSfile$ #
