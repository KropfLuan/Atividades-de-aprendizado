#include <stdio.h>

void buscaBinariaRecursiva (int vector[], int inicio, int fim, int valor) {
    if (inicio > fim) { // Caso base: se o início for maior que o fim, o valor não foi encontrado
        printf("Value not found.\n");
        return; // Encerra a função 
    }

    int meio = inicio + (fim - inicio) / 2; // Calcula o índice do meio do vetor

    if (vector[meio] == valor) { // Verifica se o valor no meio é igual ao valor buscado
        printf("Value found: %d\n", meio);
        return; // Retorna o índice do valor encontrado
    } 
    else if (vector[meio] < valor) { // Se o valor no meio for menor que o valor buscado
        buscaBinariaRecursiva(vector, meio + 1, fim, valor); // Chama a função recursivamente para a metade direita do vetor
    } 
    else { // Se o valor no meio for maior que o valor buscado
        buscaBinariaRecursiva(vector, inicio, meio - 1, valor); // Chama a função recursivamente para a metade esquerda do vetor
    }
}