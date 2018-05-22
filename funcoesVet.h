/*
 Trabalho realizado pelos alunos:
 Davi Fontenele Meira Marçal
 Leonardo Holanda
 Natália Sales Aragão

 Cadeira de Introdução à Ciência da Computação 2017.2
 Professor Dr. Leonardo Sampaio
 */

#ifndef funcoesVet_h
#define funcoesVet_h

#include <stdio.h>

#endif /* funcoesVet_h */


//cria a struct com as variáveis utilizadas nas funções de vetores
typedef struct {
    int tamanho;
    int *p;
}vetor;


void Ler_Vetores(vetor *v1, vetor *v2);
void Imprimir_Vetores(vetor v1, vetor v2);
void Somar_Vetores(vetor v1, vetor v2);
void Subtrair_Vetores(vetor v1, vetor v2);
void Produto_Escalar(vetor v1, vetor v2);
void Multiplicar_Vetores(vetor v1, vetor v2);


