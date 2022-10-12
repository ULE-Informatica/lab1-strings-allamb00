#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

/*
10/10
*/
void optionOne(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

/*
reserva 100 bytes y no se liberan en ningún momento
*/
void optionTwo(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}

/*
Reserva 100 bytes, libera ese espacio de memoria y luego intenta almacenar un valor
*/
void optionThree(){
    char *s = (char *) malloc(100);
    free(s);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}

/*
Reserva 18 bytes para una cadena de 18 caracteres en la que no se cuenta el \0
*/
void optionFour(){
    char *s = (char *) malloc(18);
    strcpy(s,  "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

int main(int argc, const char *argv[]) {

    int expression;
    char* p;
    errno = 0; 
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        exit(1);
    }

    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) {
        return 1; 
    }

    if (arg < INT_MIN || arg > INT_MAX) {
        return 1;
    }

    expression = arg;
 

    switch (expression)
    {
        case 1:
            optionOne();
            break;
        case 2:
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        default:
            printf("\n");
            break;
    }

    return 0;
}