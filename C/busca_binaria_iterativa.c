#include <stdio.h>

void buscaBinaria (int vetor[], int tamanho, int valor) {
        int inicio = 0; // Índice inicial do vetor
        int fim = tamanho - 1; // Índice final do vetor

        while (inicio <= fim) { // Loop enquanto o início for menor ou igual ao fim
            int meio = inicio + (fim - inicio) / 2; // Calcula o índice do meio do vetor

            if (vetor[meio] == valor) { // Verifica se o valor no meio é igual ao valor buscado
                printf("Value found: %d\n", meio);
                return; // Retorna o índice do valor encontrado
            } 
            else if (vetor[meio] < valor) { // Se o valor no meio for menor que o valor buscado
                inicio = meio + 1; // Move o início para a próxima posição após o meio
            } 
            else { // Se o valor no meio for maior que o valor buscado
                fim = meio - 1; // Move o fim para a posição anterior ao meio
            }
        }
        printf("Value not found.\n"); // Mensagem caso o valor não seja encontrado no vetor
    }

int main(){

    int vector[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Vetor ordenado para a busca binária
    buscaBinaria(vector, 10, 5); // Chama a função de busca binária para encontrar o valor 5 no vetor


   
}