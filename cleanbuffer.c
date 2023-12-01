#include <termios.h>
#include <unistd.h>
/*
INTENTO DE LIMPIADOR DE BUFFER
Con gcc no funciona fflush(stdin)
Podemos usar esto en su lugar

fflush(stdout) si funciona para liberar
el buffer de salida
*/

void bufferEntrada(){
    int c;
    do {
        c = getchar();
    } while (c != '\n');
}
