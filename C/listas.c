#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 50

//Lista estática

#define TAM_MAX 10

typedef struct {
    char dado[TAM_MAX][MAX_STRING_SIZE]; // Matriz para armazenar os dados da lista
    int quantidade; // Variável para armazenar a quantidade de elementos atualmente na lista (contador)
} ListaEstatica;

void inicializarLista(ListaEstatica* lista) {
    lista -> quantidade = 0; // Inicializa a quantidade de elementos da lista como 0
}

void inserirElemento(ListaEstatica* lista, const char* texto) {
    if (lista -> quantidade < TAM_MAX) { // Verifica se há espaço disponível na lista
        strncpy(lista -> dado[lista -> quantidade], texto, MAX_STRING_SIZE - 1); // Copia o texto para a posição atual da lista
        lista -> dado[lista -> quantidade][MAX_STRING_SIZE - 1] = '\0'; // Garante que a string seja terminada com null
        lista -> quantidade++; // Incrementa a quantidade de elementos na lista
        printf("Element '%s' inserted successfully.\n", texto); // Mensagem de sucesso após a inserção do elemento
    } else {
        printf("List is full. Cannot insert more elements.\n"); // Mensagem de erro caso a lista esteja cheia
    }
}

void removerElemento(ListaEstatica* lista, const char* texto) {
    int i, pos = -1; // Variáveis para controle do loop e posição do elemento a ser removido

    for (i = 0; i < lista -> quantidade; i++) { // Loop para encontrar a posição do último elemento da lista
        if (strcmp(lista -> dado[i], texto) == 0) { // Compara o elemento atual com o último elemento da lista
            pos = i; // Armazena a posição do elemento encontrado
            break; // Encerra o loop após encontrar o elemento
        }
    }
    if (pos == -1) { // Verifica se o elemento foi encontrado
        printf("Element '%s' not found in the list.\n", texto); // Mensagem de erro caso o elemento não seja encontrado
        return; // Encerra a função
    }
    for (i = pos; i < lista -> quantidade - 1; i++) { // Loop para deslocar os elementos após a posição do elemento removido
        strncpy(lista -> dado[i], lista -> dado[i + 1], MAX_STRING_SIZE); // Desloca o próximo elemento para a posição atual
    }
    lista -> quantidade--; // Decrementa a quantidade de elementos na lista
    printf("Element '%s' removed successfully.\n", texto); // Mensagem de sucesso após a remoção do elemento
}



void listarListaEstatica(const ListaEstatica* lista) {
    if (lista -> quantidade == 0) { // Verifica se a lista está vazia
        printf("List is empty.\n"); // Mensagem de aviso caso a lista esteja vazia
        return; // Encerra a função
    }
    printf("Elements in the list:\n"); // Cabeçalho para a listagem dos elementos
    for (int i = 0; i < lista -> quantidade; i++) { // Loop para percorrer os elementos da lista
        printf("%d: %s\n", i + 1, lista -> dado[i]); // Imprime o índice e o valor de cada elemento na lista
    }
    printf("\n"); // Imprime uma nova linha após listar todos os elementos
}

//Lista dinâmica

typedef struct Node {
    char* dado; // Campo para armazenar o dado do nó
    struct Node* next; // Ponteiro para o próximo nó da lista
} Node;

typedef Node* ListaEncadeada; // Definição de ListaDinamica como um ponteiro para Node

void inicializarListaDinamica(ListaEncadeada* lista) {
    *lista = NULL; // Inicializa a lista dinâmica como NULL, indicando que está vazia
}

void inserirListaEncadeada(ListaEncadeada* lista, const char* texto) {
    Node* novo = (Node*) malloc(sizeof(Node)); // Aloca memória para um novo nó

    if (novo == NULL) { // Verifica se a alocação de memória foi bem-sucedida
        printf("Error allocating memory.\n"); // Mensagem de erro caso a alocação falhe
        return; // Encerra a função
    }

    novo -> dado = (char*) malloc(strlen(texto) + 1); // Aloca memória para o campo de dado do nó

    if (novo -> dado == NULL) { // Verifica se a alocação de memória para o campo de dado foi bem-sucedida
        printf("Error allocating memory for node data.\n"); // Mensagem de erro caso a alocação falhe
        free(novo); // Libera a memória alocada para o nó
        return; // Encerra a função
    }

    strcpy(novo -> dado, texto); // Copia o texto para o campo de dado do nó
    novo -> next = *lista; // O próximo do novo nó aponta para o atual head da lista
    *lista = novo; // Atualiza o head da lista para apontar para o novo nó, tornando-o o primeiro elemento da lista
    printf("Element '%s' inserted successfully.\n", texto); // Mensagem de sucesso após a inserção do elemento
}

void removerListaEncadeada(ListaEncadeada* lista, const char* texto) {
    Node* current = *lista; // Ponteiro para percorrer a lista a partir do head
    Node* previous = NULL; // Ponteiro para armazenar o nó anterior durante a busca

    while (current != NULL && strcmp(current -> dado, texto) != 0) { // Loop para encontrar o nó com o dado correspondente
        previous = current; // Atualiza o ponteiro anterior para o nó atual
        current = current -> next; // Avança para o próximo nó
    }

    if (current == NULL) { // Verifica se o nó com o dado correspondente foi encontrado
        printf("Element '%s' not found in the list.\n", texto); // Mensagem de erro caso o elemento não seja encontrado
        return; // Encerra a função
    }

    if (previous == NULL) {
        *lista = current -> next;
    } else {
        previous -> next = current -> next;
    }
    
    free(current -> dado); // Libera a memória alocada para o campo de dado do nó
    free(current); // Libera a memória alocada para o nó
    printf("Element '%s' removed successfully.\n", texto); // Mensagem de sucesso após a remoção do elemento
    return; // Encerra a função após remover o elemento
}

void listarListaEncadeada(const ListaEncadeada* lista) {
    Node* current = *lista; // Ponteiro para percorrer a lista a partir do head
    if (*lista == NULL) { // Verifica se a lista está vazia
        printf("List is empty.\n"); // Mensagem de aviso caso a lista esteja vazia
        return; // Encerra a função
    }
    printf("Elements in the list:\n"); // Cabeçalho para a listagem dos elementos

    while (current != NULL) { // Enquanto não chegar ao final da lista
        printf("%s\n", current -> dado); // Imprime o valor do nó atual
        current = current -> next; // Avança para o próximo nó
    }
}

void liberarListaEncadeada(ListaEncadeada* lista) {
    Node* current = *lista; // Ponteiro para percorrer a lista a partir do head
    while (current != NULL) { // Enquanto não chegar ao final da lista
        Node* temp = current; // Armazena o nó atual em uma variável temporária
        current = current -> next; // Avança para o próximo nó
        free(temp -> dado); // Libera a memória alocada para o campo de dado do nó
        free(temp); // Libera a memória alocada para o nó
    }
    *lista = NULL; // Define o head da lista como NULL, indicando que a lista está vazia
}

int main (){

    ListaEstatica listaEstatica;
    ListaEncadeada listaDinamica;
    int choice; // Variável para armazenar a escolha do usuário no menu
    int choice1; // Variável para armazenar a escolha do usuário no submenu da lista estática
    int choice2; // Variável para armazenar a escolha do usuário no submenu da lista dinâmica
    inicializarLista(&listaEstatica);
    inicializarListaDinamica(&listaDinamica);

    do {
        printf("Select the type of list to work with:\n");
        printf("1. Static List\n");
        printf("2. Dynamic List\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        getchar(); // Limpa o buffer de entrada

        switch (choice) {
            case 1: {
                do {
                char texto[MAX_STRING_SIZE];
                printf("Menu Static list...\n");
                printf("1. Inserting elements into the static list...\n");
                printf("2. Removing elements from the static list...\n");
                printf("3. Listing elements in the static list...\n");
                printf("0. Back to main menu...\n");
                scanf("%d", &choice1);
                getchar(); // Limpa o buffer de entrada
                
                switch (choice1) {
                    case 1:
                        printf("Enter text to insert: ");
                        fgets(texto, MAX_STRING_SIZE, stdin);
                        texto[strcspn(texto, "\n")] = '\0';
                        inserirElemento(&listaEstatica, texto);
                        break;
                    case 2:
                        printf("Enter text to remove: ");
                        fgets(texto, MAX_STRING_SIZE, stdin);
                        texto[strcspn(texto, "\n")] = '\0';
                        removerElemento(&listaEstatica, texto);
                        break;
                    case 3:
                        listarListaEstatica(&listaEstatica);
                        printf("Press Enter to continue...\n");
                        getchar(); // Aguarda o usuário pressionar Enter para continuar
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid choice. Please select again.\n");
                }
            } while (choice1 != 0); // Loop para permitir múltiplas operações na lista estática até que o usuário escolha voltar ao menu principal
            }
                break;
            case 2:{
                do {
                char texto[MAX_STRING_SIZE];
                printf("Menu Dynamic list...\n");
                printf("1. Inserting elements into the dynamic list...\n");
                printf("2. Removing elements from the dynamic list...\n");
                printf("3. Listing elements in the dynamic list...\n");
                printf("0. Back to main menu...\n");
                scanf("%d", &choice2);
                getchar();

                switch (choice2) {
                    case 1:
                        printf("Enter text to insert: ");
                        fgets(texto, MAX_STRING_SIZE, stdin);
                        texto[strcspn(texto, "\n")] = '\0';
                        inserirListaEncadeada(&listaDinamica, texto);
                        break;
                    case 2:
                        printf("Enter text to remove: ");
                        fgets(texto, MAX_STRING_SIZE, stdin);
                        texto[strcspn(texto, "\n")] = '\0';
                        removerListaEncadeada(&listaDinamica, texto);
                        break;
                    case 3:
                        listarListaEncadeada(&listaDinamica);
                        printf("Press Enter to continue...\n");
                        getchar(); // Aguarda o usuário pressionar Enter para continuar
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid choice. Please select again.\n");
                }
            } while (choice2 != 0); // Loop para permitir múltiplas operações na lista dinâmica até que o usuário escolha voltar ao menu principal
            }
                break;
            case 3:
                liberarListaEncadeada(&listaDinamica);
                printf("Exiting the program.\n");
                return 0; // Encerra o programa
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 3); // Loop infinito para permitir múltiplas operações até que o usuário escolha sair

}