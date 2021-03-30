/* Copyright 2021 Priscila Angel Rodrigues Silva */
#include <iostream>
#include <string>
#include "romano.hpp"
using std::string;
using std::invalid_argument;

/* Retorna o caractere romano correspondente em inteiro */
int valueInInt(char roman) {
    switch (roman) {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        throw invalid_argument("Argumento invalido.");
        break;
    }
}

int romanToInt(string input) {
    int i, size, answer = 0, prev = 0, current = 0;
    int pPrev = 0, ppPrev = 0;

    size = input.length()-1;
    /* Verifica se a string e maior que 30 caracteres(instrucao do exercicio) */
    if (input.length() > 30) {
        return -1;
    }
    /* Percore a string da esquerda para direita */
    for (i = size; i>= 0; i--) {
        try {
            current = valueInInt(input[i]);
        }
        /* Verifica se o valor digitado eh I, V, X, L, C, D, M */
        catch (invalid_argument &excecao) {
            return -1;
        }
        /* O I so pode vir antes do V e do X */
        if (current == 1 && prev > 10) {
            return -1;
        }
        /* O X so pode vir antes do I, V, X, L e do C */
        if (current == 10 && (prev == 500 || prev == 1000)) {
            return -1;
        }
        /* Os algarismos V, L e D nao podem ser repetidos */
        if (current == 5 || current == 50 || current == 500) {
            if (current == prev) {
                return -1;
            }
        }
        /* Verifica se ha mais de 3 repeticoes de I, X, C e M */
        if (current == 1 && prev == 1 && pPrev == 1 && ppPrev == 1) {
            return -1;
        }
        if (current == 10 && prev == 10 && pPrev == 10 && ppPrev == 10) {
            return -1;
        }
        if (current == 100 && prev == 100 && pPrev == 100 && ppPrev == 100) {
            return -1;
        }
        if (current == 1000 && prev == 1000) {
            if (pPrev == 1000 && ppPrev == 1000) {
                return -1;
            }
        }
        /* o V não pode vir antes do X */
        if (current == 5 && prev == 10) {
            return -1;
        }
        /* Se o atual for maior ou igual que o anterior soma */
        if (current >= prev) {
            answer += current;
        } else {
            /* Se for menor, subtrai */
            answer -= current;
        }
        /* Armazena o valor anterior do anterior do anterior */
        ppPrev = pPrev;
        /* Armazena o valor anterior do anterior */
        pPrev = prev;
        /* Armazena o valor atual */
        prev = current;
    }
    /* Verifica se o resultado eh maior que 3000 (instrucao do exercicio) */
    if (answer > 3000) {
        return -1;
    }
    return answer;
}
