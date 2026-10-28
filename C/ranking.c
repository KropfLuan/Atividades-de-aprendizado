#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//busca sequencial iterativa

int buscaSequencialIterativa (const char *vetor[], int tamanho, const char *valor) {
    for (int i = 0; i < tamanho; i++) { // Loop para percorrer o vetor
        if (strcmp(vetor[i], valor) == 0) { // Verifica se o valor no índice atual é igual ao valor buscado
            return i; // Retorna o índice do valor encontrado
        }
    }
    return -1; // Retorna -1 caso o valor não seja encontrado
}

//busca sequencial recursiva

int buscaSequencialRecursivaAux (const char *vetor[], int tamanho, const char *valor, int indice);

int buscaSequencialRecursiva (const char *vetor[], int tamanho, const char *valor) {
    return buscaSequencialRecursivaAux(vetor, tamanho, valor, 0); // Chama a função auxiliar para iniciar a busca recursiva a partir do índice 0
}

int buscaSequencialRecursivaAux (const char *vetor[], int tamanho, const char *valor, int indice) {
    if (indice >= tamanho) { // Verifica se o índice ultrapassou o tamanho do vetor
        return -1; // Retorna -1 caso o valor não seja encontrado
    }
    if (strcmp(vetor[indice], valor) == 0) { // Verifica se o valor no índice atual é igual ao valor buscado
        return indice; // Retorna o índice do valor encontrado
    }
    return buscaSequencialRecursivaAux(vetor, tamanho, valor, indice + 1); // Chama a função recursivamente para o próximo índice
}

//busca binaria iterativa

int buscaBinariaIterativa(const char *vetor[], int tamanho, const char *valor) {
        int inicio = 0; // Índice inicial do vetor
        int fim = tamanho - 1; // Índice final do vetor

        while (inicio <= fim) { // Loop enquanto o início for menor ou igual ao fim
            int meio = inicio + (fim - inicio) / 2; // Calcula o índice do meio do vetor
            int cmp = strcmp(vetor[meio], valor); // Compara strings no meio e o valor buscado

            if (cmp == 0) { // Verifica se o valor no meio é igual ao valor buscado
                return meio; // Retorna o índice do valor encontrado
            } 
            else if (cmp < 0) { // Se o valor no meio for menor que o valor buscado
                inicio = meio + 1; // Move o início para a próxima posição após o meio
            } 
            else { // Se o valor no meio for maior que o valor buscado cmp > 0
                fim = meio - 1; // Move o fim para a posição anterior ao meio
            }
        }
        return -1; // Retorna -1 caso o valor não seja encontrado
    }

//busca binaria recursiva (função auxiliar)

int buscaBinariaRecursivaAux(const char *vetor[], int inicio, int fim, const char *valor) {

    if (inicio > fim) { // Verifica se o início ultrapassou o fim
        return -1; // Retorna -1 caso o valor não seja encontrado
    }
    int meio = inicio + (fim - inicio) / 2; // Calcula o índice do meio do vetor
    int cmp = strcmp(vetor[meio], valor); // Compara strings no meio e o valor buscado

    if (cmp == 0) { // Verifica se o valor no meio é igual ao valor buscado
        return meio; // Retorna o índice do valor encontrado
    } 
    else if (cmp < 0) { // Se o valor no meio for menor que o valor buscado
        return buscaBinariaRecursivaAux(vetor, meio + 1, fim, valor); // Busca na metade superior
    } 
    else { // Se o valor no meio for maior que o valor buscado
        return buscaBinariaRecursivaAux(vetor, inicio, meio - 1, valor); // Busca na metade inferior
    }
}

int buscaBinariaRecursiva (const char *vetor[], int tamanho, const char *valor) {
    return buscaBinariaRecursivaAux(vetor, 0, tamanho - 1, valor);
}

void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado) {
    printf("[%s] buscando por '%s': ", nomeDaBusca, item); // Imprime o nome da busca entre colchetes
    if (resultado != -1) {
        printf("Result on index %d.\n",resultado);
    } else {
        printf("Item not found in the list.\n");
    }
}

int main (){

    const char * listaCompras[] = {
        "arroz",
        "batata",
        "cebola",
        "detergente",
        "feijao",
        "leite",
        "macarrao",
        "oleo",
        "sal",
        "tomate"
    };

    int tamanhoLista = sizeof(listaCompras) / sizeof(listaCompras[0]); // Calcula o tamanho da lista de compras

    const char * itemExistente = "leite"; // Item a ser buscado na lista de compras
    const char * itemInexistente = "queijo"; // Item a ser buscado na lista de compras

    printf("Demonstracao\n");
    printf("Lista utilizada para a busca: \n");
    for (int i = 0; i < tamanhoLista; i++) {
        printf("%s ", listaCompras[i]); // Imprime cada item da lista de compras
    }
    printf("\n\n");
    //Busca sequencial 

    //Busca sequencial iterativa
    int Res1 = buscaSequencialIterativa(listaCompras, tamanhoLista, itemExistente); // Chama a função de busca sequencial iterativa para encontrar o item existente na lista de compras
    imprimirResultado("Busca Sequencial Iterativa", itemExistente, Res1);

    int Res2 = buscaSequencialIterativa(listaCompras, tamanhoLista, itemInexistente); // Chama a função de busca sequencial iterativa para encontrar o item inexistente na lista de compras
    imprimirResultado("Busca Sequencial Iterativa", itemInexistente, Res2);

    printf("\n");
    //Busca sequencial recursiva

    int res3 = buscaSequencialRecursiva(listaCompras, tamanhoLista, itemExistente); // Chama a função de busca sequencial recursiva para encontrar o item existente na lista de compras
    imprimirResultado("Busca Sequencial Recursiva", itemExistente, res3);

    int res4 = buscaSequencialRecursiva(listaCompras, tamanhoLista, itemInexistente); // Chama a função de busca sequencial recursiva para encontrar o item inexistente na lista de compras 
    imprimirResultado("Busca Sequencial Recursiva", itemInexistente, res4);
    
    printf("\n");
    //Busca binaria

    //Busca binaria iterativa
    int res5 = buscaBinariaIterativa(listaCompras, tamanhoLista, itemExistente); // Chama a função de busca binária iterativa para encontrar o item existente na lista de compras
    imprimirResultado("Busca Binaria Iterativa", itemExistente, res5);

    int res6 = buscaBinariaIterativa(listaCompras, tamanhoLista, itemInexistente); // Chama a função de busca binária iterativa para encontrar o item inexistente na lista de compras
    imprimirResultado("Busca Binaria Iterativa", itemInexistente, res6);

    printf("\n");
    //Busca binaria recursiva
    int res7 = buscaBinariaRecursiva(listaCompras, tamanhoLista, itemExistente); // Chama a função de busca binária recursiva para encontrar o item existente na lista de compras
    imprimirResultado("Busca Binaria Recursiva", itemExistente, res7);

    int res8 = buscaBinariaRecursiva(listaCompras, tamanhoLista, itemInexistente); // Chama a função de busca binária recursiva para encontrar o item inexistente na lista de compras
    imprimirResultado("Busca Binaria Recursiva", itemInexistente, res8);

    return 0;
}
