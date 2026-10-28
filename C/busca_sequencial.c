#include <stdio.h>

void buscaSequencial (int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) { // Loop para percorrer o vetor
        if (vetor[i] == valor) { // Verifica se o valor no índice atual é igual ao valor buscado
            printf("Value found: %d\n", i);
            return; // Retorna o índice do valor encontrado
        }
    }
    printf("Value not found.\n"); // Mensagem caso o valor não seja encontrado no vetor
}