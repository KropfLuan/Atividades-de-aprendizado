#include <stdio.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "Portuguese");

    int x = 10;
    int* p = &x;

    printf("O valor de x é %d\n", x);
    printf("O endereço de x é %p\n", &x);
    printf("O valor de p é  %p\n", p);
    printf("O valor apontado por p é %d\n", *p);

    *p = 20;

    printf("O valor de x agora é %d\n", x);
}