# Nome do seu projeto
TARGET = meu_programa

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -Iincludes

# Diretórios dos arquivos fonte, objetos e cabeçalhos
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Lista de todos os arquivos fonte
SRCS = $(wildcard $(SRCDIR)/*.c)

# Gera a lista de objetos correspondentes
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
# Regra padrão, compila todos os objetos e cria o executável
all: $(TARGET)

# Cria o diretório obj, se ele não existir
$(shell mkdir -p $(OBJDIR))

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $^ -o $@

# Regra para compilar os objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar os arquivos objetos e o executável
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
