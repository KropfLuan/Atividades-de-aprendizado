#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next; // Ponteiro para o próximo nó (encadeamento simples)
    struct Node* prev; // Ponteiro para o nó anterior (encadeamento duplo)
} Node;

void listar(Node* head) {
    Node* current = head; // Ponteiro para percorrer a lista a partir do head

    while (current != NULL) { // Enquanto não chegar ao final da lista
        printf("%d ", current -> data); // Imprime o valor do nó atual
        current = current -> next; // Avança para o próximo nó
    }
    printf("\n"); // Imprime uma nova linha após listar todos os elementos
}

void inserirInicio(Node** head, int dado) {
    struct Node* novo = (struct Node*) malloc(sizeof(struct Node)); // Aloca memória para o novo nó

    if (novo == NULL) {
        printf("Error allocating memory.\n");
        return;
    }
    
    novo -> data = dado; // Atribui o valor ao campo data do novo nó

    novo -> next = *head; // O próximo do novo nó aponta para o atual head (primeiro nó da lista)

    novo -> prev = NULL; // O anterior do novo nó é NULL, pois ele será o primeiro nó da lista

    *head = novo; // Atualiza o head para apontar para o novo nó, tornando-o o primeiro nó da lista
}

void removerInicio(Node** head){
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
}

    struct Node* temp = *head; // Armazena o nó a ser removido

    *head = (*head) -> next; // Atualiza o ponteiro head para o próximo nó

    free(temp); // Libera a memória do nó removido
}

void BuscaLinear (Node* head, int valor) {
    int posicao = 0; // Variável para armazenar a posição do elemento encontrado
    Node* current = head; // Ponteiro para percorrer a lista a partir do head
    while (current != NULL) { // Enquanto não chegar ao final da lista
        if (current -> data == valor) { // Verifica se o valor do nó atual é igual ao valor buscado
            printf("Value %d found at position %d.\n", valor, posicao); // Imprime a posição do elemento encontrado
            return; // Encerra a função após encontrar o elemento
        }
        current = current -> next; // Avança para o próximo nó
        posicao++; // Incrementa a posição para o próximo nó
    }
    printf("Value %d not found in the list.\n", valor); // Imprime mensagem se o elemento não for encontrado
}

int main (){

    struct Node* primeiro = (struct Node*) malloc(sizeof(struct Node));
    struct Node* segundo = (struct Node*) malloc(sizeof(struct Node));
    struct Node* terceiro = (struct Node*) malloc(sizeof(struct Node));

    primeiro -> data = 10;
    primeiro -> next = segundo;
    primeiro -> prev = NULL;

    segundo -> data = 20;
    segundo -> next = terceiro;
    segundo -> prev = primeiro;

    terceiro -> data = 30;
    terceiro -> next = NULL;
    terceiro -> prev = segundo;

    inserirInicio(&primeiro, 5); // Inserir no início
    inserirInicio(&primeiro, 1); // Inserir no início

    printf("List after insertions:\n");
    listar(primeiro); // Listar os elementos da lista
    printf("Press Enter to continue...\n");
    getchar(); // Aguarda o usuário pressionar Enter para continuar

    removerInicio(&primeiro); // Remover do início

    printf("List after removal:\n");
    listar(primeiro); // Listar os elementos da lista
    printf("Press Enter to continue...\n");
    getchar(); // Aguarda o usuário pressionar Enter para continuar


    BuscaLinear(primeiro, 60); // Buscar um valor que não existe
    printf("Press Enter to continue...\n");
    getchar(); // Aguarda o usuário pressionar Enter para continuar

    BuscaLinear(primeiro, 20); // Buscar um valor que existe
    printf("Press Enter to continue...\n");
    getchar(); // Aguarda o usuário pressionar Enter para continuar
}