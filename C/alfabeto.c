#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
                        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; i < num; i++){
        printf("%c", alfabeto[i]);
    }
    return 0;
}

