#!/bin/bash

# Script de build - compila arquivos C e coloca executável em bin/

# Cria pasta bin se não existir
mkdir -p bin

# Função para compilar um arquivo
compilar() {
    local arquivo="$1"
    local nome=$(basename "$arquivo" .c)
    echo "Compilando: $arquivo -> bin/$nome"
    gcc "$arquivo" -o "bin/$nome"
}

# Se nenhum argumento for passado, compila todos os .c do diretório atual e subdirs
if [ $# -eq 0 ]; then
    # Compila arquivos .c no diretório atual
    for arquivo in *.c; do
        [ -f "$arquivo" ] && compilar "$arquivo"
    done
    
    # Compila arquivos .c em subdirectórios (leetcode, pratica01, etc)
    for dir in */; do
        if [ -d "$dir" ] && [ "$dir" != "bin/" ]; then
            for arquivo in "$dir"*.c; do
                [ -f "$arquivo" ] && compilar "$arquivo"
            done
        fi
    done
else
    # Compila arquivo específico passado como argumento
    arquivo="$1.c"
    if [ -f "$arquivo" ]; then
        compilar "$arquivo"
    else
        # Tenta encontrar em subdirectórios
        for dir in */; do
            if [ -f "$dir$arquivo" ]; then
                compilar "$dir$arquivo"
                exit 0
            fi
        done
        echo "Erro: arquivo $arquivo não encontrado"
        exit 1
    fi
fi

echo "Compilação concluída!"