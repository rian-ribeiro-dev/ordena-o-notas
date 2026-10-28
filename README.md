# Ordenação de notas — Bubble Sort e Quick Sort

Atividade da disciplina sobre algoritmos de ordenação. O programa foi feito em C e ordena as notas de uma turma usando dois métodos diferentes: Bubble Sort e Quick Sort.

## Objetivo

Aplicar os dois algoritmos num problema do dia a dia e comparar o funcionamento deles. Os dois recebem exatamente os mesmos dados. Assim dá para ver, na prática, quantas comparações e trocas cada um precisou fazer para chegar ao mesmo resultado.

## Situação-problema

Escolhi a classificação de notas de alunos porque é um caso bem comum. No fim do bimestre, as notas vão sendo lançadas conforme as provas são corrigidas, então a lista fica fora de ordem.

Com as notas desorganizadas, fica trabalhoso responder perguntas simples, como:

- qual foi a menor e a maior nota da turma?
- quem ficou abaixo da média e vai precisar de recuperação?
- como montar um ranking da turma?

Depois de ordenar, essas respostas saem quase de graça. A menor nota fica na primeira posição e a maior na última. Quem ficou abaixo da média está todo agrupado no começo da lista. O programa aproveita isso e mostra um pequeno resumo da turma no final.

Usei uma turma de **12 alunos**, com notas de 0 a 10 e média 6,0 para aprovação.

## Como executar

### Pelo OnlineGDB (sem instalar nada)

1. Acesse <https://www.onlinegdb.com/>
2. Em *Language*, no canto superior direito, selecione **C**
3. Apague o código de exemplo e cole o conteúdo do arquivo `ordenacao.c`
4. Clique em **Run**

### No computador (com gcc)

```bash
gcc -Wall -Wextra -std=c99 -o ordenacao ordenacao.c
./ordenacao
```

No Windows, o executável gerado é o `ordenacao.exe`.

## Como os algoritmos funcionam

### Bubble Sort

Ele percorre a lista comparando cada nota com a vizinha da direita. Se a da esquerda for maior, as duas trocam de lugar. No fim de cada passada, a maior nota que ainda estava fora do lugar chega até o final, como uma bolha subindo. Daí vem o nome.

Como a última posição já fica certa depois de cada passada, a passada seguinte vai um passo a menos. É fácil de entender e de implementar. O problema é que ele compara muito: com *n* notas são n·(n−1)/2 comparações, ou seja, o custo cresce na ordem de **O(n²)**.

### Quick Sort

Ele usa a ideia de dividir para conquistar. Primeiro escolhe uma nota como **pivô**; neste código é sempre a última do trecho. Depois reorganiza a lista para que as notas menores ou iguais ao pivô fiquem à esquerda e as maiores fiquem à direita. Essa etapa se chama particionamento, e usei o esquema de **Lomuto**.

Terminada a partição, o pivô já está na posição definitiva. Aí o algoritmo chama a si mesmo (recursão) para o lado esquerdo e para o lado direito. Isso se repete até sobrarem pedaços com 0 ou 1 nota, que já estão ordenados.

Na média ele faz por volta de **O(n log n)** comparações, bem menos que o Bubble quando a lista cresce. O pior caso é O(n²) e acontece quando o pivô escolhido é sempre o menor ou o maior valor, por exemplo com uma lista que já chega ordenada.

## Resultado

Notas lançadas: `7.5  4.0  9.2  6.1  3.5  8.8  5.5  10.0  6.0  2.7  7.0  8.3`

Notas ordenadas: `2.7  3.5  4.0  5.5  6.0  6.1  7.0  7.5  8.3  8.8  9.2  10.0`

| | Comparações | Trocas |
|---|---|---|
| Bubble Sort | 66 | 33 |
| Quick Sort | 33 | 26 |

O Quick Sort precisou da metade das comparações. O Bubble fez exatamente 66, que é 12·11/2: ele sempre faz todas as passadas, mesmo quando a lista já está pronta. Na saída dá para ver que ela já estava ordenada na 9ª passada, mas ele continuou até a 11ª.

Uma melhoria possível seria parar o Bubble quando uma passada inteira não fizer nenhuma troca. Deixei sem essa otimização para mostrar a versão clássica do algoritmo.

Resumo que o programa mostra no final:

```
Menor nota: 2.7
Maior nota: 10.0
Alunos abaixo da media (6.0): 4
Notas em recuperacao: 2.7  3.5  4.0  5.5
```

O programa também imprime o vetor depois de cada passada do Bubble e depois de cada pivô do Quick. Assim dá para acompanhar o passo a passo de cada um.

## Deploy

Toda vez que há um push na branch `main`, o GitHub Actions compila o programa, executa e publica a saída numa página do GitHub Pages:

**https://SEU_USUARIO.github.io/ordena-o-notas/**

## Autor

Rian do Nascimento Ribeiro — Engenharia de Software, UDF
