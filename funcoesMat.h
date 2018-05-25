/*
Trabalho realizado pelos alunos:
Davi Fontenele Meira Marçal
Leonardo Holanda
Natália Sales Aragão

Cadeira de Introdução à Ciência da Computação 2017.2
Professor Dr. Leonardo Sampaio
*/

#ifndef funcoesMat_h
#define funcoesMat_h

#include <stdio.h>


#endif /* funcoesMat_h */

//cria a struct com as variáveis utilizadas nas funções de matrizes
typedef struct {
    int linhas;
    int colunas;
    int **p;
}matriz;

void Ler_Matrizes(matriz *m1, matriz *m2);
void Imprimir_Matrizes(matriz m1, matriz m2);
void Somar_Matrizes(matriz m1, matriz m2);
void Subtracao_Matrizes(matriz m1, matriz m2);
void Transposta_Matriz(matriz m1, matriz m2);
void Determinante_Matriz(matriz m1, matriz m2);
void Simetria_Matriz(matriz m1, matriz m2);
void Multiplicar_Matrizes(matriz m1, matriz m2);

