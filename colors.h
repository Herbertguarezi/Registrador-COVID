#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED

void corVerde(){
    printf("\033[0;32m");
}

void corVermelha(){
    printf("\033[0;31m");
}

void corPadrao(){
    printf("\033[0m");
}

void corAmarelo(){
    printf("\033[1;33m");
}

void piscando(){
    printf("\033[5;30m");
}

#endif // COLORS_H_INCLUDED
