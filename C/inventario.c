#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 50

#define TAM_MAX 10

typedef struct {
    char nome[TAM_MAX][30];
    char tipo[TAM_MAX][MAX_STRING_SIZE];
    int quantidade[TAM_MAX];
    int total;
} ListaEstatica;

void inicializarInventario(ListaEstatica* lista) {
    lista->total = 0;
}

void inserirItem(ListaEstatica* lista) {
    if (lista->total < TAM_MAX) {
        printf("Digite o nome do item: ");
        scanf("%s", lista->nome[lista->total]);
        printf("Digite o tipo do item: ");
        scanf("%s", lista->tipo[lista->total]);
        printf("Digite a quantidade do item: ");
        scanf("%d", &lista->quantidade[lista->total]);
        lista->total++; 
    } else {
        printf("Inventario is full. Cannot add more items.\n");
    }
}

void removerItem(ListaEstatica* lista, const char* texto) {
    int i, pos = -1;

    for (i = 0; i < lista->total; i++) { // Loop para encontrar a posição do item a ser removido
        if (strcmp(lista->tipo[i], texto) == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Item '%s' not found in the inventory.\n", texto);
        return;
    }
    for (i = pos; i < lista->total - 1; i++) { // Loop para deslocar os elementos após a posição do item removido
        strcpy(lista->nome[i], lista->nome[i + 1]);
        strcpy(lista->tipo[i], lista->tipo[i + 1]);
        lista->quantidade[i] = lista->quantidade[i + 1];
    }

    lista->total--; // Decrementa a quantidade de itens no inventário
    printf("Item '%s' removed successfully.\n", lista->nome[pos]);
}

void listarInventario(const ListaEstatica* lista) {
    if (lista->total == 0) {
        printf("Inventario is empty.\n");
    } else {
        printf("-----------------------------------\n");
        printf("Nome        |Tipo       |Quantidade\n");
        printf("-----------------------------------\n");
        for (int i = 0; i < lista->total; i++) {
            printf("%-12s|%-11s|%d\n", lista->nome[i], lista->tipo[i], lista->quantidade[i]);
        }
    }
    printf("Pressione Enter para continuar...\n");
    getchar(); // Limpa o buffer de entrada
}

int main (){

    ListaEstatica inventario;
    inicializarInventario(&inventario);
    int opcao;


    do {
    printf("================================\n");
    printf("Mochila de Sobrevivencia\n");
    printf("================================\n");
    printf("Itens na mochila: %d/10\n", inventario.total);
    listarInventario(&inventario);

    printf("1. Adicionar item\n");
    printf("2. Remover item\n");
    printf("3. Listar itens\n");
    printf("0. Sair\n");
    scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("Adicionando item...\n");
                inserirItem(&inventario);
                printf("Item '%s' added successfully.\n", inventario.nome[inventario.total - 1]);
                printf("Pressione Enter para continuar...\n");
                getchar(); // Limpa o buffer de entrada
                break;
            }
            case 2: {
                char item[MAX_STRING_SIZE];
                printf("Digite o nome do item para remover: ");
                scanf("%s", item);
                removerItem(&inventario, item);
                break;
            }
            case 3:
                listarInventario(&inventario);
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}