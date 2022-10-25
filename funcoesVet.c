/*
 Trabalho realizado pelos alunos:
 Davi Fontenele Meira Marçal
 Leonardo Holanda
 Natália Sales Aragão

 Cadeira de Introdução à Ciência da Computação 2017.2
 Professor Dr. Leonardo Sampaio.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoesVet.h"

//Cadastra vetores para serem usados em outras operações
void Ler_Vetores(vetor *v1, vetor *v2){
    int j;
    int tamanho = 0;
    puts("\nO número de linhas de um vetor é sempre 1.");
    v1->tamanho = tamanho;
    puts("\Escreva o tamanho do vetor.");
    printf("Tamanho: ");
    scanf("%d", &tamanho);
    v1->tamanho = tamanho;
 
   v1->p = (float *) malloc(v1->tamanho * sizeof(float));

    for(j = 0; j < v1->tamanho; j++){
        printf("\Escreva o valor dos elementos do vetor 1 [%d]: ",j);
        scanf("%f", &v1->p[j]);
    }

    v2->tamanho = tamanho;
    puts("\Escreva o tamanho do vetor.");
    printf("Tamanho: ");
    scanf("%d", &tamanho);
    v2->tamanho = tamanho;
    v2->p = (float *) malloc(v2->tamanho * sizeof(float));

    for(j = 0; j < v2->tamanho; j++){
        printf("\Escreva o valor dos elementos do vetor 2 [%d]: ",j);
        scanf("%f", &v2->p[j]);

    }
}	

//Imprime os vetores cadastrados na leitura:
void Imprimir_Vetores(vetor v1, vetor v2){
    int j;
    printf("\n\tVetor [A]: [");

    for(j = 0; j < v1.tamanho; j++){
        printf(" %5.2f",v1.p[j]);
    }
    printf("]\n");

    printf("\n\tVetor [B]: [");

    for(j = 0; j < v2.tamanho; j++){
        printf(" %5.2f", v2.p[j]);
    }
    printf("]\n"); 
}

//Realiza a soma entre dois vetores de mesma dimensão:
void Somar_Vetores(vetor v1, vetor v2){
    int j;
    //Vetor resultante:
    float *vSoma;

    if(v1.tamanho != v2.tamanho){
        //condição de existência da soma:
        printf("\n\n\tOs vetores [A] e [B] precisam ter a mesma dimensão\n");
    }else{
        // Operação da soma:
        vSoma = (float*) malloc(v1.tamanho * sizeof(float));
        for(j = 0; j < v1.tamanho; j++){
            vSoma[j] = v1.p[j] + v2.p[j];
        }

        Imprimir_Vetores(v1,v2);
        //Imprime o resultado
        printf("\tVetor [A] + [B] = [");
        for(j = 0; j < v1.tamanho; j++){
            printf(" %5.2f",vSoma[j]);
        }
        printf("]\n\n");
        free(vSoma);
    }
    printf("\n");
}
//Realiza a soma entre dois vetores de mesma dimensão:
void Subtrair_Vetores(vetor v1, vetor v2){
    int j;
    //Vetor resultante:
    float *vSub;

    if(v1.tamanho != v2.tamanho){
        //condição de existência da subtração:
        printf("\n\n\tOs vetores [A] e [B] precisam ter a mesma dimensão\n");
        
    }else{
        // Operação da subtração:
        vSub = (float*) malloc(v1.tamanho * sizeof(float));
        for(j = 0; j < v1.tamanho; j++){
            vSub[j] = v1.p[j] - v2.p[j];
        }

        Imprimir_Vetores(v1,v2);
        //Imprime o resultado
        printf("\tVetor [A] - [B] = [");
        for(j = 0; j < v1.tamanho; j++){
            printf(" %5.2f",vSub[j]);
        }
        printf("]\n\n");
        free (vSub);
    }
    printf("\n");

}


void Multiplicar_Vetores(vetor v1, vetor v2){
    int j;
    float escalar;
    //Vetor resultante:
    float *vMult;

    printf("Digite o valor da escalar\n");
    scanf("%f", &escalar);

    Imprimir_Vetores(v1,v2);
	
    // Operação da multiplicação:
    vMult = (float*) malloc(v1.tamanho * sizeof(float));
    for(j = 0; j < v1.tamanho; j++){
        vMult[j] = v1.p[j] * escalar;
    }
    //Imprime o resultado
    printf("\tVetor [A] * escalar = [");
    for(j = 0; j < v1.tamanho; j++){
        printf(" %5.2f",vMult[j]);
    }
    printf("]\n\n");
    vMult = (float*) malloc(v2.tamanho * sizeof(float));
    for(j = 0; j < v2.tamanho; j++){
        vMult[j] = v2.p[j] * escalar;
    }


    printf("\tVetor [B] * escalar = [");
    for(j = 0; j < v2.tamanho; j++){
        printf(" %5.2f",vMult[j]);
    }
    printf("]\n\n");
    free (vMult);

    printf("\n");
}

void Produto_Escalar(vetor v1, vetor v2){
    int j;
    //Vetor resultante:
    float *vMult;

    float resultado = 0;

    if(v1.tamanho != v2.tamanho){
        //condição de existência:
        printf("\n\n\tOs vetores [A] e [B] precisam ter a mesma dimensão\n");
    }else{
        Imprimir_Vetores(v1,v2);
	
        // Operação do produto:
        vMult = (float*) malloc(v1.tamanho * sizeof(float));
        for(j = 0; j < v1.tamanho; j++){
            vMult[j] = v1.p[j] * v2.p[j];
        }
        //Imprime o resultado
        printf("\n\tEscalar = [");
        for(j = 0; j < v1.tamanho; j++){
            resultado += vMult[j];

        }
        printf(" %f",resultado);
        printf(" ]\n\n");
        free (vMult);

        printf("\n");
    }
}
