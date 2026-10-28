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

/* contadores pra comparar quanto trabalho cada algoritmo teve */
int comparacoes = 0;
int trocas = 0;

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
    trocas++;
}

/*
 * BUBBLE SORT
 *
 * Funciona comparando cada nota com a vizinha da direita. Se a da
 * esquerda for maior, as duas trocam de lugar. Fazendo isso do comeco
 * ao fim do vetor, a maior nota vai sendo "empurrada" ate a ultima
 * posicao, como uma bolha subindo (dai o nome).
 *
 * Depois de cada passada a ultima posicao ja esta certa, por isso o
 * laco de dentro vai ate n - 1 - i: nao precisa comparar de novo o
 * que ja foi pro lugar.
 *
 * E simples de entender, mas faz muitas comparacoes: com n notas sao
 * n*(n-1)/2, entao o custo cresce na base de n ao quadrado.
 */
void bubbleSort(float v[], int n) {
    for (int i = 0; i < n - 1; i++) {           /* cada volta e uma passada */
        for (int j = 0; j < n - 1 - i; j++) {   /* compara as vizinhas */
            comparacoes++;
            if (v[j] > v[j + 1]) {
                trocar(&v[j], &v[j + 1]);
            }
        }
        printf("  %2da passada: ", i + 1);
        mostrarNotas(v, n);
    }
}

int main() {
    /* notas na ordem em que foram lancadas no sistema */
    float notas[TAM] = {7.5, 4.0, 9.2, 6.1, 3.5, 8.8,
                        5.5, 10.0, 6.0, 2.7, 7.0, 8.3};

    printf("Notas lancadas (antes de ordenar):\n");
    mostrarNotas(notas, TAM);

    float copia[TAM];

    /* ---- Bubble Sort ---- */
    printf("\n========== BUBBLE SORT ==========\n");
    copiarNotas(notas, copia, TAM);
    comparacoes = 0;
    trocas = 0;
    bubbleSort(copia, TAM);
    printf("Notas ordenadas: ");
    mostrarNotas(copia, TAM);
    printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);

    return 0;
}
