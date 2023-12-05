#!/bin/bash

clear

# Navegar até o diretório do projeto
cd ~/Desktop/Projeto/Compilador/

# Entrar no diretório src/
cd src/

# Verificar se o arquivo parser.y está presente
if [ -e "parser.y" ]; then
    echo "Arquivo parser.y encontrado."
else
    echo "Erro: Arquivo parser.y não encontrado."
    exit 1
fi

# Executar o comando bison
bison parser.y

# Verificar se o comando bison foi executado com sucesso
if [ $? -eq 0 ]; then
    echo "Comando bison executado com sucesso."
else
    echo "Erro ao executar o comando bison."
    exit 1
fi

# Voltar para o diretório principal do projeto
cd ..

# Compilar o código usando make
make -s

# Verificar se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida."
else
    echo "Erro durante a compilação."
    exit 1
fi

# Executar o programa com o arquivo de teste
./exec testes/testelex.c-
