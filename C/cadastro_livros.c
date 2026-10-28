#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100

typedef struct { //Estrutura para armazenar informacoes sobre um livro
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para disponivel, 0 para emprestado
} Livro;

typedef struct { //Estrutura para armazenar informacoes sobre um emprestimo
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
} Emprestimo;

void limparBuffer() { // Funcao para limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main (){
    setlocale(LC_ALL, "Portuguese");

    Livro *biblioteca;
    Emprestimo *emprestimos;

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    biblioteca = (Livro *)calloc(MAX_LIVROS, sizeof(Livro)); // Alocação de memória para a biblioteca

    emprestimos = (Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(Emprestimo)); // Alocação de memória para os empréstimos

    if (biblioteca == NULL || emprestimos == NULL) { // Verificação de alocação de memória
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Loop principal do programa
    do {
        printf("Menu de cadastro de livros:\n");
        printf("1. Cadastrar um novo livro\n");
        printf("2. Listar todos os livros cadastrados\n");
        printf("3. Emprestar um livro\n");
        printf("4. Listar empréstimos\n");
        printf("5. Sair\n");
        printf("---------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao){
            case 1: //Cadastrar livro
                printf("Cadastro de um novo livro:\n");
                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o autor do livro: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite a editora do livro: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    printf("Digite a edição do livro: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBuffer();

                    biblioteca[totalLivros].disponivel = 1;

                    totalLivros++;
                    
                    printf("Livro cadastrado com sucesso!\n");
                    
                    printf("Pressione Enter para continuar...");
                    getchar();
                } else {
                    printf("Capacidade máxima de livros atingida. Não é possível cadastrar mais livros.\n");
                }
                break;

            case 2: //Listar livro
                printf("Lista de livros cadastrados:\n");

                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado.\n");
                } else {
                    for (int i = 0; i < totalLivros; i++) {
                        printf("---------------------------\n");
                        printf("Livro %d\n" , i + 1);
                        printf("Nome: %s", biblioteca[i].nome);
                        printf("Autor: %s", biblioteca[i].autor);
                        printf("Editora: %s", biblioteca[i].editora);
                        printf("Edição: %d\n", biblioteca[i].edicao);
                    }
                    printf("---------------------------\n");
                    printf("Pressione Enter para continuar...");
                    getchar();
                }
                break;

            case 3: //Emprestar livro
                printf("Empréstimo de um livro:\n");
                if(totalEmprestimos >= MAX_EMPRESTIMOS){ // Verificar se a capacidade máxima de empréstimos foi atingida
                    printf("Capacidade máxima de empréstimos atingida.\n");
                } else {
                    printf("Livros disponíveis para empréstimo:\n"); // Listar apenas os livros disponíveis para empréstimo
                    int disponivel = 0;
                    for (int i = 0; i < totalLivros; i++) {
                        if (biblioteca[i].disponivel) {
                            printf("%d - %s", i + 1, biblioteca[i].nome);
                            disponivel++;
                        }
                    }

                    if(disponivel == 0){ // Verificar se há livros disponíveis para empréstimo
                        printf("Nenhum livro disponível para empréstimo.\n");
                            } else {
                                printf("Digite o número do livro que deseja emprestar: ");
                                int escolha;
                                scanf("%d", &escolha);
                                limparBuffer();

                            int indice = escolha - 1; // Ajuste para índice baseado em 0

                            if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) { // Verificar se a escolha a válida e o livro está disponível
                                printf("Digite o nome do usuário que está emprestando o livro: ");
                                fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);

                                // Marcar o livro como emprestado
                                emprestimos[totalEmprestimos].indiceLivro = indice;

                                biblioteca[indice].disponivel = 0; // Marcar como emprestado
                                totalEmprestimos++;
                                printf("Livro emprestado com sucesso!\n");
                            } else {
                                printf("Opção inválida ou livro não disponível para empréstimo.\n");
                            }
                        }
                    }
            
                printf("Pressione Enter para continuar...");
                getchar();
                break;      

            case 4: //Listar empréstimos
                printf("Lista de empréstimos:\n");
                    if (totalEmprestimos == 0) {
                        printf("Nenhum empréstimo realizado.\n");
                        } else {
                            for (int i = 0; i < totalEmprestimos; i++){
                                int indiceLivro = emprestimos[i].indiceLivro;
                                    printf("---------------------------\n");
                                    printf("Empréstimo %d\n", i + 1);
                                    printf("Livro: %s", biblioteca[indiceLivro].nome);
                                    printf("Usuário: %s", emprestimos[i].nomeUsuario);
                                }
                                printf("---------------------------\n");
                                printf("Pressione Enter para continuar...");
                                getchar();
                            }
                break;


            case 5: //Sair
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                getchar();
                break;
        }
    }   while (opcao != 5);

    // Liberar memória alocada

    free(biblioteca);
    free(emprestimos);

    printf("Memória liberada. Programa encerrado.\n");

    return 0;
}
