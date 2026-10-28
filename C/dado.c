#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h> // Para usar a função time() para gerar números aleatórios

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("Bem-vindo ao jogo de Dado!\n");
    printf("Role o dado para ver o resultado.\n");
    
    int resultado;
    srand(time(NULL)); // Inicializa a semente para números aleatórios
    // Simulação de rolar um dado de 6 faces
    resultado = (rand() % 6) + 1; // Gera um número entre 1 e 6

    printf("Você rolou um %d!\n", resultado);

    return 0;
}