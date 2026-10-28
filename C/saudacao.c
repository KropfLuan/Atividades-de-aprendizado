#include <stdio.h>
#include <locale.h>

void saudacao() {
    printf("Saudações!\n");
}

int  main(){
    setlocale(LC_ALL, "Portuguese");

    saudacao();
    //void (*ptr)() = saudacao;
    //ptr();
    return 0;
}