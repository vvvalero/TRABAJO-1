#include <stdio.h>
#include <unistd.h>
#include "cleanbuffer.c"

void main(){
    int hijo;
    if (getuid()!=0){
        //Si NO es usuario root...
        for (int i = 0; i < 9; i++)
        {    
            hijo = fork();
            if(hijo != 0) {break;}
            printf("Soy proceso %d",i);
            printf("Mi",);
            fflush(stdout); // Limpia el buffer de salida (*1)
        }
        printf("\n");
    }
    else{//Si es usuario root...
        printf("Soy el proceso PADRE\n");
        for (int i = 1; i < 9; i++)
        {       
            hijo = fork();
            if(hijo == 0) break;
            printf("Soy proceso hijo %d\n",i);
        }
    }
}

/*
(*1)
PROBLEMA:
Sin fflush al NO poner /n al final del printf este se imprime varias veces
creando una escalera (probar para entenderlo)

Explicacion de porque de StackOverflow:

The reason why is that without the \n at the end of the format string the value 
is not immediately printed to the screen. Instead it is buffered within the process.
This means it is not actually printed until after the fork operation hence you get 
it printed twice.

Adding the \n though forces the buffer to be flushed and outputted to the screen. 
This happens before the fork and hence is only printed once.
You can force this to occur by using the fflush method
casa
prueba2
*/