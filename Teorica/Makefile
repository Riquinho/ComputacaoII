#
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - Turma 2018/1
# Prof. Marcelo Luiz Drumond Lanza
#
# $Author$
# $Date$
# $Log$

CC = gcc # CC = /opt/intel/bin/icc
LD = gcc

CFLAGS = -Wall -ansi -D_MY_DEBUG_
LFLAGS = -Wall -ansi

EXE001OBJS = exemplo_001.o
EXE002OBJS = exemplo_002.o
EXE003OBJS = exemplo_003.o
EXE004OBJS = exemplo_004.o
EXE005OBJS = exemplo_005.o
EXE006OBJS = exemplo_006.o
EXE007OBJS = exemplo_007.o
EXE008OBJS = exemplo_008.o
EXE009OBJS = exemplo_009.o
EXE010OBJS = exemplo_010.o
EXE011OBJS = exemplo_011.o
EXE012OBJS = exemplo_012.o
EXE013OBJS = exemplo_013.o
EXE014OBJS = exemplo_014.o
EXE015OBJS = exemplo_015.o
EXE016OBJS = exemplo_016.o
EXE017OBJS = exemplo_017.o
EXE018OBJS = exemplo_018.o
EXE025AOBJS = exemplo_024a.o exemplo_025.o
EXE025BOBJS = exemplo_024b.o exemplo_025.o
EXE025COBJS = exemplo_024c.o exemplo_025.o
EXE025DOBJS = exemplo_024d.o exemplo_025.o

EXECS = exemplo_001\
        exemplo_002\
        exemplo_003\
        exemplo_004\
        exemplo_005\
        exemplo_006\
        exemplo_007\
        exemplo_008\
        exemplo_009\
        exemplo_010\
        exemplo_011\
        exemplo_012\
        exemplo_013\
        exemplo_014\
        exemplo_015\
        exemplo_016\
        exemplo_017\
        exemplo_018\
				exemplo_025a\
				exemplo_025b\
				exemplo_025c\
				exemplo_025d
 

# Regra Implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(EXECS)

exemplo_001: $(EXE001OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE001OBJS)

exemplo_002: $(EXE002OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE002OBJS)

exemplo_003: $(EXE003OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE003OBJS)

exemplo_004: $(EXE004OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE004OBJS)

exemplo_005: $(EXE005OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE005OBJS)

exemplo_006: $(EXE006OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE006OBJS)

exemplo_007: $(EXE007OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE007OBJS)

exemplo_008: $(EXE008OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE008OBJS)

exemplo_009: $(EXE009OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE009OBJS)

exemplo_010: $(EXE010OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE010OBJS)

exemplo_011: $(EXE011OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE011OBJS)

exemplo_012: $(EXE012OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE012OBJS)

exemplo_013: $(EXE013OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE013OBJS)

exemplo_014: $(EXE014OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE014OBJS)

exemplo_015: $(EXE015OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE015OBJS)

exemplo_016: $(EXE016OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE016OBJS)

exemplo_017: $(EXE017OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE017OBJS)

exemplo_018: $(EXE018OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE018OBJS)

exemplo_025a: $(EXE025AOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE025AOBJS)

exemplo_025b: $(EXE025BOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE025BOBJS)

exemplo_025c: $(EXE025COBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE025COBJS)

exemplo_025d: $(EXE025DOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE025DOBJS)

clean:
	rm -f *.o $(EXECS)
# $RCSfile$
