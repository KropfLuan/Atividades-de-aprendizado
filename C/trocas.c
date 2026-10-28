#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void ListaOrdenada(int vector[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vector[i] = i + 1; // Preenche o vetor com números de 1 a tamanho
    }
}

void ListaInversa(int vector[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vector[i] = tamanho - i; // Preenche o vetor com números de tamanho a 1
    }
}

void ListaAleatoria(int vector[], int tamanho) {
    srand(time(NULL)); // Inicializa a semente para geração de números aleatórios

    for (int i = 0; i < tamanho; i++) {
        vector[i] = rand() % 100 + 1; // Preenche o vetor com números aleatórios entre 1 e 100
    }
}

void troca(int *a, int *b) {
    int temp = *a; // Armazena o valor de a em uma variável temporária

    *a = *b; // Atribui o valor de b para a

    *b = temp; // Atribui o valor armazenado em temp (original de a) para b
}

void bubleSort(int vector[], int tamanho) { // Mesmo para listas pequenas, mas geralmente é mais lento que o insertSort
    for (int i = 0; i < tamanho - 1; i++) { // Percorre o vetor do início até o penúltimo elemento
        for (int j = 0; j < tamanho - i - 1; j++) { // Percorre o vetor até o elemento antes do último elemento já ordenado
            if (vector[j] > vector[j + 1]) { // Compara o elemento atual com o próximo elemento
                troca(&vector[j], &vector[j + 1]);
            }
        }
    }
}

void insertSort(int vector[], int tamanho) { // Melhor para listas pequenas ou quase ordenadas
    for (int i = 1; i < tamanho; i++) { // Começa a partir do segundo elemento
        int key = vector[i]; // Armazena o elemento atual como chave
        int j = i - 1; // Inicializa j para o elemento anterior

        // Move os elementos do vetor[0..i-1], que são maiores que a chave, para uma posição à frente de sua posição atual
        while (j >= 0 && vector[j] > key) {
            vector[j + 1] = vector[j]; // Move o elemento para a direita
            j--; // Decrementa j para continuar comparando com os elementos anteriores
        }
        vector[j + 1] = key; // Insere a chave na posição correta
    }
}

void selectionSort(int vector[], int tamanho) { // Geralmente mais lento que o insertSort, mas tem a vantagem de fazer menos trocas
    for (int i = 0; i < tamanho - 1; i++) { // Percorre o vetor do início até o penúltimo elemento
        int min_index = i; // Assume que o elemento atual é o mínimo

        for (int j = i + 1; j < tamanho; j++) { // Percorre o vetor a partir do próximo elemento
            if (vector[j] < vector[min_index]) { // Compara o elemento atual com o mínimo encontrado
                min_index = j; // Atualiza o índice do mínimo
            }
        }
        troca(&vector[min_index], &vector[i]); // Troca o mínimo encontrado com o elemento atual
    }
}

void imprimirLista(int vector[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vector[i]); // Imprime cada elemento do vetor seguido de um espaço
    }
    printf("\n"); // Imprime uma nova linha após imprimir todos os elementos
}

int main () {
    int listaOrdenada[SIZE];
    int listaInversa[SIZE];
    int listaAleatoria[SIZE];

    printf("--------------------\n");
    printf("---Gerando Listas---\n");
    printf("--------------------\n\n");
    ListaOrdenada(listaOrdenada, SIZE);
    ListaInversa(listaInversa, SIZE);
    ListaAleatoria(listaAleatoria, SIZE);


    printf("---Lista Ordenada---\n");
    imprimirLista(listaOrdenada, SIZE);

    printf("---Lista Inversa---\n");
    imprimirLista(listaInversa, SIZE);

    printf("---Lista Aleatoria---\n");
    imprimirLista(listaAleatoria, SIZE);


    printf("\n---Bubble Sort---\n");

    //Melhor caso: O(n) - Lista já ordenada
    bubleSort(listaOrdenada, SIZE); //
    imprimirLista(listaOrdenada, SIZE);

    //Pior caso: O(n^2) - Lista em ordem inversa
    bubleSort(listaInversa, SIZE);
    imprimirLista(listaInversa, SIZE);

    //Caso médio: O(n^2) - Lista aleatória
    bubleSort(listaAleatoria, SIZE);
    imprimirLista(listaAleatoria, SIZE);


    printf("\n---Insertion Sort---\n");

    //Melhor caso: O(n) - Lista já ordenada
    insertSort(listaOrdenada, SIZE);
    imprimirLista(listaOrdenada, SIZE);

    //Pior caso: O(n^2) - Lista em ordem inversa
    insertSort(listaInversa, SIZE);
    imprimirLista(listaInversa, SIZE);

    //Caso médio: O(n^2) - Lista aleatória
    insertSort(listaAleatoria, SIZE);
    imprimirLista(listaAleatoria, SIZE);


    printf("\n---Selection Sort---\n");

    //Melhor caso: O(n^2) - Lista já ordenada
    selectionSort(listaOrdenada, SIZE);
    imprimirLista(listaOrdenada, SIZE);

    //Pior caso: O(n^2) - Lista em ordem inversa
    selectionSort(listaInversa, SIZE);
    imprimirLista(listaInversa, SIZE);

    //Caso médio: O(n^2) - Lista aleatória
    selectionSort(listaAleatoria, SIZE);
    imprimirLista(listaAleatoria, SIZE);

    return 0;
}