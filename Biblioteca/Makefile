CC=gcc
CFLAGS=-I. -O2
DEPS=linalg.h
OBJ=main.o ler.o imprime.o troca.o triangula.o substituicao.o determinante.o inversa.o transposta.o copia.o multiplica.o precisao.o jacobi.o
TARGET=main
LIBS=-lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm $(OBJ)
