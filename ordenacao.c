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
#define MEDIA 6.0     /* media minima pra aprovacao */

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

/*
 * QUICK SORT
 *
 * Aqui a ideia e "dividir pra conquistar". Escolho uma nota como pivo
 * (nesse caso a ultima do trecho) e reorganizo o vetor pra que tudo
 * que for menor ou igual ao pivo fique a esquerda dele e o que for
 * maior fique a direita. Isso se chama particionar.
 *
 * Depois da particao o pivo ja esta na posicao final dele. Ai e so
 * repetir a mesma coisa (recursao) com o pedaco da esquerda e com o
 * pedaco da direita, ate sobrar trechos de 0 ou 1 nota, que ja estao
 * ordenados por si so.
 *
 * Usei o particionamento de Lomuto, que e o mais facil de acompanhar.
 * Na media o Quick Sort faz por volta de n*log(n) comparacoes, bem
 * menos que o Bubble quando a lista cresce.
 */

/* separa as notas em volta do pivo e devolve a posicao final dele */
int particionar(float v[], int inicio, int fim) {
    float pivo = v[fim];
    int i = inicio - 1;   /* ultima posicao da "area dos menores" */

    for (int j = inicio; j < fim; j++) {
        comparacoes++;
        if (v[j] <= pivo) {
            i++;                      /* abre espaco na area dos menores */
            trocar(&v[i], &v[j]);     /* e coloca essa nota la */
        }
    }
    /* o pivo vai pra logo depois do ultimo menor */
    trocar(&v[i + 1], &v[fim]);
    return i + 1;
}

void quickSort(float v[], int inicio, int fim) {
    if (inicio < fim) {   /* se tiver 0 ou 1 nota no trecho, para */
        int p = particionar(v, inicio, fim);
        printf("  pivo %.1f ficou na posicao %2d: ", v[p], p);
        mostrarNotas(v, TAM);

        quickSort(v, inicio, p - 1);   /* lado esquerdo (menores) */
        quickSort(v, p + 1, fim);      /* lado direito (maiores) */
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

    /* ---- Quick Sort ---- */
    /* volta pra copia original pra comparacao ser justa */
    printf("\n========== QUICK SORT ==========\n");
    copiarNotas(notas, copia, TAM);
    comparacoes = 0;
    trocas = 0;
    quickSort(copia, 0, TAM - 1);
    printf("Notas ordenadas: ");
    mostrarNotas(copia, TAM);
    printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);

    /* ---- Resumo da turma ----
       com as notas em ordem, a menor fica na primeira posicao e a maior
       na ultima. E quem ficou abaixo da media esta todo no comeco do
       vetor, entao da pra parar de contar assim que achar a primeira
       nota >= media */
    printf("\n========== RESUMO DA TURMA ==========\n");
    printf("Menor nota: %.1f\n", copia[0]);
    printf("Maior nota: %.1f\n", copia[TAM - 1]);

    int abaixo = 0;
    while (abaixo < TAM && copia[abaixo] < MEDIA) {
        abaixo++;
    }
    printf("Alunos abaixo da media (%.1f): %d\n", MEDIA, abaixo);
    printf("Notas em recuperacao: ");
    mostrarNotas(copia, abaixo);

    return 0;
}
