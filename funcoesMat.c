
/*
 Trabalho realizado pelos alunos:
 Davi Fontenele Meira Marçal
 Leonardo Holanda
 Natália Sales Aragão

 Cadeira de Introdução à Ciência da Computação 2017.2
 Professor Dr. Leonardo Sampaio
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoesMat.h"


//Verifica se uma matriz é simétrica ou não
void Simetria_Matriz(matriz m1, matriz m2){

    int i,j,ic,jc,cont = 0; // variáveis contadoras do loop
    //Tratamento de erro
    char escolhaMatrizS[10];
    int escolhaMatriz;

    //Verifica se as dimensões da matriz são diferentes
    //Condição de existência da Matriz
    if((m1.linhas != m1.colunas) && (m2.linhas != m2.colunas)){
        //Caso nenhuma seja simétrica
        printf("\n\n\tAs Matrizes [A] e [B] não são simétricas! \n\n");
    }else{
        //Imprime na tela as matrizes cadastradas na função LerMatrizes()
        Imprimir_Matrizes(m1,m2);
	
        do{
            //Printa as dimensões das duas matrizes cadastradas
            printf("\n\tMatriz [A] %d x %d - 1 ",m1.linhas,m1.colunas);
            printf("\n\tMatriz [B] %d x %d - 2 \n",m2.linhas,m2.colunas);
            printf("\n\tEscolha a Matriz para realizar a operação: ");
            //Solicita ao usuário qual matriz ele deseja verificar se é simétrica
            scanf("%s",escolhaMatrizS);
            //Transforma a string em um valor inteiro
            escolhaMatriz = atoi(escolhaMatrizS);
            //Limpa o buffer do teclado
            setbuf(stdin,NULL);

            if(escolhaMatriz == 1){

                if(m1.linhas == m1.colunas){
                    //Transposta de A // matriz A
                    for(i = 0,ic = 0; (i < m1.linhas) && (ic < m1.colunas); i++,ic++){
                        for(j = 0,jc = 0; (j < m1.linhas) && (jc < m1.colunas); j++,jc++){
                            if(m1.p[j][i] == m1.p[ic][jc]){
                                //Conta quantas vezes a condição é verdadeira
                                cont = cont + 1;
                            }else{
                                continue;
                            }
                        }
                    }
                    //Verifica a simetria
                    if(cont == (m1.linhas * m1.colunas)){ // total de elementos
                        printf("\n\n\tA Matriz [A] é simétrica:\n");
                        printf("\tMatriz [A]:%d x %d \n\n",m1.linhas,m1.colunas);
                    }else{
                        printf("\n\n\tA Matriz [A] não é simétrica:\n");
                        printf("\tMatriz [A]:%d x %d \n\n",m1.linhas,m1.colunas);
                    }
                }else{
                    printf("\n\n\tA Matriz [A] não é simétrica :\n");
                    printf("\tMatriz [A]:%d x %d \n\n",m1.linhas,m1.colunas);
                }

            }else{
                if(escolhaMatriz == 2){

                    if(m2.linhas == m2.colunas){
                        // Transposta de B // Matriz B :
                        for(i = 0,ic = 0; (i < m2.colunas) && (ic < m2.linhas); i++,ic++){
                            for(j = 0,jc = 0; (j < m2.linhas) && (jc < m2.colunas); j++,jc++){
                                // contar quantas vezes a condicao eh verdadeira :
                                if(m2.p[j][i] == m2.p[ic][jc]){
                                    cont = cont + 1;
                                }else{
                                    continue;
                                }
                            }
                        }
                        // verifica a simetria :
                        if(cont == (m2.linhas * m2.colunas)){
                            printf("\n\n\tA Matriz [B] é simétrica :\n");
                            printf("\tMatriz [B]:%d x %d \n\n",m2.linhas, m2.colunas);
                        }else{
                            printf("\n\n\tA Matriz [B] não é simétrica :\n");
                            printf("\tMatriz [B]:%d x %d \n\n",m2.linhas, m2.colunas);
                        }
                    }else{
                        printf("\n\n\tA Matriz [B] não é simétrica :\n");
                        printf("\tMatriz [B]:%d x %d \n\n",m2.linhas, m2.colunas);
                    }

                }else{
                    //Caso digite uma opção inválida no menu
                    printf("\n\t\tDigite uma opção válida\n\n");
                }
            }
        }while(escolhaMatriz!=1 && escolhaMatriz!=2); // loop caso nao digite 1 ou 2 :
    }
}

void Determinante_Matriz(matriz m1, matriz m2){
    // tratamento de erro
    char escolhaMatrizS[10];
    int escolhaMatriz;
    // armazenar valor da determinante de matriz terceira ordem :
    float det;

    if((m1.linhas != m1.colunas) && (m2.linhas != m2.colunas)){
        // condicao de existencia invalida tanto pra A quanto pra B :
        printf("\n\n\tNão é possível realizar a operação para as Matrizes [A] e [B] :\n");
        printf("\tMatriz [A]: %d x %d  \n\tMatriz [B]: %d x %d \n\n",m1.linhas,m1.colunas,m2.linhas,m2.colunas);
    }else{
        if((m1.linhas >= 4 && m1.colunas >= 4) && (m2.linhas >= 4 && m2.colunas >= 4)){
            // caso superior a ordem 3 :
            printf("\n\n\tNão é possível realizar a operação para as Matrizes [A] e [B] :\n");
            printf("\tMatrizes [A]: %d x %d  \n\tMatriz [B]: %d x %d \n\tMatrizes superiores a 3° ordem\n\n",m1.linhas,m1.colunas,m2.linhas,m2.colunas);
        }else{
            //Imprime as matrizes cadastradas na função Ler_Matrizes()
            Imprimir_Matrizes(m1,m2);

            do{
                printf("\n\t MATRIZ [A] %d x %d - - - - - - - - - - - - 1 -", m1.linhas, m1.colunas);
                printf("\n\t MATRIZ [B] %d x %d - - - - - - - - - - - - 2 -", m2.linhas, m2.colunas);
                printf("\n\t Escolha a Matriz para realizar a operação : ");
                scanf("%s",escolhaMatrizS);
                escolhaMatriz = atoi(escolhaMatrizS);
                //Limpa o buffer do teclado
                setbuf(stdin,NULL);

                if(escolhaMatriz == 1){

                    if(m1.linhas != m1.colunas){
                        // caso invalido somente para matriz A
                        printf("\n\n\tOperação inválida para a Matriz [A]:\n");
                        printf("\tMatriz [A]:%d x %d \n\n",m1.linhas,m1.colunas);
                    }else{
                        if(m1.linhas == 1){
                            // caso matriz de tamanho 1x1
                            printf("\n\tDeterminante da Matriz [A] = %5.2f\n\n",m1.p[0][0]);
                        }else{
                            if(m1.linhas == 2){
                                // caso matriz de tamanho 2x2
                                printf("\n\tDeterminante da Matriz [A] = %5.2f\n\n",(m1.p[0][0] * m1.p[1][1]) - (m1.p[0][1] * m1.p[1][0]) );
                            }else{
                                if(m1.linhas == 3){
                                    // caso matriz 3x3
                                    det =     (m1.p[0][0] * m1.p[1][1] * m1.p[2][2]) + // diagonal principal
                                    (m1.p[2][0] * m1.p[0][1] * m1.p[1][2]) +    // paralelas
                                    (m1.p[1][0] * m1.p[2][1] * m1.p[0][2]) +    // paralelas
                                    ((m1.p[2][0] * m1.p[1][1] * m1.p[0][2])*(-1)) + // diagonal secundaria
                                    ((m1.p[0][0] * m1.p[2][1] * m1.p[1][2])*(-1)) + // paralelas
                                    ((m1.p[1][0] * m1.p[0][1] * m1.p[2][2])*(-1)); // paralelas
                                    printf("\n\tDeterminante da Matriz [A] = %5.2f \n\n", det);
                                }else{
                                    if(m1.linhas >= 4){
                                        // caso superior a ordem 3
                                        printf("\n\n\tOperação inválida para a Matriz [A]:\n");
                                        printf("\tMatriz [A]: %d x %d \n\tMatriz de ordem superior a 3\n\n",m1.linhas,m1.colunas);
                                    }
                                }
                            }
                        }
                    }

                }else{

                    if(escolhaMatriz == 2){
                        if(m2.colunas != m2.colunas){
                            // caso so a matriz B invalida
                            printf("\n\n\tOperação inválida para a Matriz [B] :\n");
                            printf("\tMatriz [B]: %d x %d \n\n",m2.linhas,m2.colunas);
                        }else{
                            if(m2.linhas == 1){
                                // caso matriz de tamanho 1x1
                                printf("\n\tDeterminante da Matriz [B] = %5.2f\n\n",m2.p[0][0]);
                            }else{
                                if(m2.linhas == 2){
                                    // caso matriz de tamanho 2x2
                                    printf("\n\tDeterminante da Matriz [B] = %5.2f \n\n",(m2.p[0][0] * m2.p[1][1]) - (m2.p[0][1] * m2.p[1][0]) );
                                }else{
                                    if(m2.linhas == 3){
                                        // caso matriz 3x3
                                        det =     (m2.p[0][0] * m2.p[1][1] * m2.p[2][2]) + // diagonal principal (i==j)
                                        (m2.p[2][0] * m2.p[0][1] * m2.p[1][2]) +    // paralelas
                                        (m2.p[1][0] * m2.p[2][1] * m2.p[0][2]) +    // paralelas
                                        ((m2.p[2][0] * m2.p[1][1] * m2.p[0][2])*(-1)) + // diagonal secundaria
                                        ((m2.p[0][0] * m2.p[2][1] * m2.p[1][2])*(-1)) + // paralelas
                                        ((m2.p[1][0] * m2.p[0][1] * m2.p[2][2])*(-1)); // paralelas
                                        printf("\n\tDeterminante da Matriz [B] = %5.2f \n\n", det);
                                    }else{
                                        if(m2.linhas >= 4){
                                            // caso superior a ordem 3
                                            printf("\n\n\tOperação inválida para a Matriz [B]:\n");
                                            printf("\tMatriz [B]: %d x %d \n\tMatriz de ordem superior a 3\n\n",m1.linhas,m1.colunas);
                                        }
                                    }
                                }
                            }
                        }

                    }else{
                        //Caso seja digitada uma opção
                        printf("\n\t\tDigite uma opção válida! (1 ou 2)\n\n");
                    }
                }
            }while(escolhaMatriz!=1 && escolhaMatriz!=2); // loop caso não digite 1 ou 2

        }
    }
}

//Calcula a transposta de uma das duas matrizes cadastradas na função "Ler_Matrizes();"
void Transposta_Matriz(matriz m1, matriz m2){
    int i,j; // Variáveis contadoras do loop
    //Tratamento de erro
    char escolhaMatrizS[10];
    int escolhaMatriz;

    //Printa na tela as duas matrizes cadastradas na função Ler_Matrizes()
    Imprimir_Matrizes(m1,m2);	

    do{
        //Printa na tela as dimensões das duas matrizes cadastradas
        printf("\n\t Matriz [A] %d x %d - 1 ",m1.linhas,m1.colunas);
        printf("\n\t Matriz [B] %d x %d - 2 \n",m2.linhas,m2.colunas);
        printf("\n\t Escolha a Matriz para realizar a operação : ");
        //Solicita ao usuário a matriz que ele deseja calcular a transposta
        scanf("%s",escolhaMatrizS);
        //Transforma o valor de string para inteiro
        escolhaMatriz = atoi(escolhaMatrizS);
        //Limpa o buffer do teclado
        setbuf(stdin,NULL);

        if(escolhaMatriz == 1){
            // transposta de [A]: inverte linha e coluna :
            printf("\n\tMatriz [A\']: \n");
            for(i = 0; i < m1.colunas; i++){
                printf("\t|");
                for(j = 0; j < m1.linhas; j++){
                    printf(" %5.2f",m1.p[j][i]);
                }
                printf("|\n");
            }
            printf("\n");
        }else{
            if(escolhaMatriz == 2){
                // transposta de [B]: inverte linha e coluna :
                printf("\n\tMatriz [B\']: \n");
                for(i = 0; i < m2.colunas; i++){
                    printf("\t|");
                    for(j = 0; j < m2.linhas; j++){
                        printf(" %5.2f",m2.p[j][i]);
                    }
                    printf("|\n");
                }
                printf("\n");
            }else{
                printf("\n\t\tDigite uma opção válida (1 ou 2)\n\n");
            }
        }
    }while(escolhaMatriz != 1 && escolhaMatriz != 2);
}

void Ler_Matrizes(matriz *m1,matriz *m2){
    int linhas = 0, colunas = 0;
    puts("\nDigite o número de linhas da primera matriz.");
    printf("Linhas: ");

    scanf("%d", &linhas);
    m1->linhas = linhas;
    puts("\nDigite o numero de colunas da primeira matriz.");
    printf("Colunas: ");
    scanf("%d", &colunas);
    m1->colunas = colunas;
    m1->p = (float **) malloc(m1->linhas*sizeof(float));

    for(int i = 0; i < m1->linhas ; i++){
        m1->p[i] = (float *) malloc(m1->colunas * sizeof(float));
        for(int j = 0; j < m1->colunas; j++){
            printf("Digite o valor do elemento da matriz 1 [%d][%d]: ",i,j);
            scanf("%f", &m1->p[i][j]);
        }
    }
    puts("\nDigite o número de linhas da segunda matriz.\n");
    printf("Linhas: ");
    scanf("%d",&linhas);
    m2->linhas = linhas;
    puts("\nDigite o número de colunas da segunda matriz.\n");
    printf("Colunas: ");
    scanf("%d", &colunas);
    m2->colunas = colunas;
    m2->p = (float **) malloc(m2->linhas*sizeof(float));
    for(int i = 0; i < m2->linhas; i++){
        m2->p[i] = (float *) malloc(m2->colunas*sizeof(float));
        for(int j = 0; j < m2->colunas; j++){
            printf("Digite o valor do elemento da matriz 2 [%d][%d]: ", i,j);
            scanf("%f", &m2->p[i][j]);
        }
    }
}
//Imprime as matrizes cadastradas na função lerMatrizes()
void Imprimir_Matrizes(matriz m1, matriz m2){
    int i,j;
     printf("\n\n\tMatriz [A] : \n");
    for(i = 0; i < m1.linhas ; i++){
        printf("\t| ");
        for(j = 0; j < m1.colunas; j++){
            printf(" %5.2f",m1.p[i][j]);
        }
        printf(" |\n");
    }

    printf("\n\n\tMatriz [B] : \n");
    for(i = 0; i < m2.linhas; i++){
        printf("\t| ");
        for(j = 0; j < m2.colunas; j++){
            printf(" %5.2f",m2.p[i][j]);
        }
        printf(" |\n");
    }
    printf("\n");
}

//Realiza a soma entre duas matrizes de mesmas dimensões
void Somar_Matrizes(matriz m1, matriz m2){
    int i = 0 ,j = 0;
    // matriz resultante :
    float **mSoma;

    if(m1.linhas != m2.linhas || m1.colunas != m2.colunas){
        // condicao de existencia da soma :
        printf("\n\n\tAs matrizes [A] e [B] precisam ter a mesma dimensão\n");
      //  return Menu_matrizes();
    }else{
        //Imprime na tela as matrizes cadastradas na função LerMatrizes()
        Imprimir_Matrizes(m1,m2);	

        // Operação da soma:
        mSoma = (float **) malloc(m1.linhas * sizeof(float));
        for(i = 0; i < m1.linhas; i++){
            mSoma[i] = (float *)malloc(m1.linhas * sizeof(float));
            for(j = 0; j < m1.colunas; j++){
                mSoma[i][j] = m1.p[i][j] + m2.p[i][j];
            }
        }

        //Imprime matriz resultante :
        printf("\tMatriz Resultante [A] + [B] :\n\t");
        for(i = 0; i < m1.linhas; i++){
            printf("|");
            for(j = 0; j < m1.colunas; j++){
                printf(" %5.2f", mSoma[i][j]);
            }
            printf(" |\n\t");
        }
        free(mSoma);

    }
    printf("\n");
}

//Realiza a subtração entre duas matrizes de mesmas dimensões
void Subtracao_Matrizes(matriz m1, matriz m2){
    int i = 0,j = 0;
    // matriz resultante :
    float **mSub;

    if(m1.linhas != m1.colunas || m2.linhas != m2.colunas){
        // condição de existência da subtração :
        printf("\n\n\tAs matrizes [A] e [B] precisam ter a mesma dimensão\n");
    }else{
        //Imprime na tela as matrizes cadastradas na função LerMatrizes()
        Imprimir_Matrizes(m1,m2);	
        //Operação da soma:
        mSub = (float **) malloc(m1.linhas * sizeof(float));
        for(i = 0; i < m1.linhas; i++){
            mSub[i] = (float *) malloc(m1.linhas * sizeof(float));
            for(j = 0; j < m1.colunas; j++){
                mSub[i][j] = m1.p[i][j] - m2.p[i][j];
            }
        }

        //Imprime a Matriz resultante
        printf("\tMatriz Resultante [A] - [B] :\n\t");
        for(i = 0; i < m1.linhas; i++){
            printf("|");
            for(j = 0; j < m1.colunas; j++){
                printf(" %5.2f ",mSub[i][j]);
            }
            printf(" |\n\t");
        }
        free(mSub);
    }
    printf("\n");
}


//Realiza uma Multiplicaçãotiplicação entre duas matrizes de mesma dimensão
void Multiplicar_Matrizes(matriz m1, matriz m2){
    int i, j, l;
    float **mMult;
    float armazenar = 0;
    //Conndição de existência da Multiplicaçã-o
    if(m1.linhas != m1.colunas || m2.linhas != m2.colunas){
        printf("\n\n\tAs matrizes [A] e [B] precisam ter a mesma dimensão\n");
    }else{
        //Imprime na tela as matrizes cadastradas na função LerMatrizes()
        Imprimir_Matrizes(m1,m2);	

        printf("\tMatriz Resultante [A] * [B] :\n");
        mMult = (float **) malloc(m1.linhas * sizeof(float));
        for(i = 0; i < m1.linhas; i++){
            printf("\t|");
            mMult[i] = (float *) malloc(m1.linhas * sizeof(float));
            for(j = 0; j < m1.linhas; j++){
                for(l = 0; l < m1.linhas; l++){
                    armazenar += m1.p[i][l] * m2.p[l][j];
                }
                mMult[i][j] = armazenar;
                printf(" %5.2f ",armazenar);
                armazenar = 0;

            }
            printf("|\n");
        }
    }
}
