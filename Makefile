
#Nome do compilador
CC = g++

#Opções de compilação
CFLAGS=-std=c++11 -Wall

#Listar os arquivos-fonte no diretório atual
FONTES = $(wildcard *.cpp)

#Gera a lista dos arquivos-objeto utilizando os arquivos-fonte
OBJETOS = $(FONTES:.cpp=.o)

#Nome do arquivo executável
EXECUTAVEL = ilhas


all:	$(EXECUTAVEL)

$(EXECUTAVEL):	$(OBJETOS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c $(CFLAGS) $^

clean_windows:
	del *.o
	del *.exe

clean_linux:
	rm -rf *.o

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)
