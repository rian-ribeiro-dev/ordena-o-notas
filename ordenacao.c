/*
 * Ordenacao das notas de uma turma
 * Rian do Nascimento Ribeiro - Engenharia de Software (UDF)
 *
 * De onde veio a ideia: no fim do bimestre as notas vao sendo lancadas
 * na ordem em que as provas sao corrigidas, entao a lista fica toda
 * misturada. Pra montar o ranking da turma, achar a menor e a maior nota
 * e ver quem ficou abaixo da media (e vai pra recuperacao), fica bem
 * mais facil trabalhar com as notas em ordem crescente.
 *
 * Testado no OnlineGDB (linguagem C).
 */

#include <stdio.h>

#define TAM 12        /* quantidade de alunos da turma */

/* imprime as notas numa linha so, com uma casa decimal */
void mostrarNotas(float v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.1f  ", v[i]);
    }
    printf("\n");
}

/* faz uma copia do vetor. uso isso pra que cada algoritmo
   comece com as notas na ordem original */
void copiarNotas(float origem[], float destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

/* troca duas notas de lugar usando uma variavel auxiliar */
void trocar(float *a, float *b) {
    float aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    /* notas na ordem em que foram lancadas no sistema */
    float notas[TAM] = {7.5, 4.0, 9.2, 6.1, 3.5, 8.8,
                        5.5, 10.0, 6.0, 2.7, 7.0, 8.3};

    printf("Notas lancadas (antes de ordenar):\n");
    mostrarNotas(notas, TAM);

    return 0;
}
