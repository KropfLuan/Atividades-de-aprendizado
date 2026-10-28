#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main () {

    setlocale(LC_ALL, "Portuguese");

    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));

    printf("Digite o nome da pessoa: ");
    scanf("%s", p -> nome);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &p -> idade);

    printf("%s tem %d anos.\n", p -> nome, p -> idade);

    free(p);
    
    return 0;
}