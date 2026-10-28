#include <stdio.h>
#include <locale.h>

typedef struct {
    char nome [50]; // campo de dados
    int idade; // campo de dados
    float media; // campo de dados
} Aluno;

int main (){

    setlocale(LC_ALL, "Portuguese");

    Aluno aluno1 = {"João", 20, 8.5}; // inicialização do struct

    printf("Nome: %s\n", aluno1.nome); // acesso ao campo nome
    printf("Idade: %d\n", aluno1.idade); // acesso ao campo
    printf("Média: %.2f\n", aluno1.media); // acesso ao campo
}
