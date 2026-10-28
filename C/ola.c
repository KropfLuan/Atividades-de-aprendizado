#include <stdio.h>
#include <locale.h>
int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("Olá, mundo!\n");
    return 0;
};