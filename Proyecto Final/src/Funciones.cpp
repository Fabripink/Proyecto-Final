#include "Funciones.h"

bool validacion(int escenario[][17],Posicion pos,char tecla){
        if(tecla == IZQUIERDA)
            if(escenario[pos.get_y()][pos.get_x()-1]==3 || escenario[pos.get_y()][pos.get_x()-1]==2 || escenario[pos.get_y()][pos.get_x()-1]==4){return false;}

        if(tecla == DERECHA)
            if(escenario[pos.get_y()][pos.get_x()+1]==3 || escenario[pos.get_y()][pos.get_x()+1]==2 || escenario[pos.get_y()][pos.get_x()+1]==4){return false;}

        if(tecla == ABAJO)
            if(escenario[pos.get_y()+1][pos.get_x()]==3 || escenario[pos.get_y()+1][pos.get_x()]==2 || escenario[pos.get_y()+1][pos.get_x()]==4){return false;}

        if(tecla == ARRIBA)
            if(escenario[pos.get_y()-1][pos.get_x()]==3 || escenario[pos.get_y()-1][pos.get_x()]==2 || escenario[pos.get_y()-1][pos.get_x()]==4){return false;}

        return true;
}
void gotoxy ( int x, int y ) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition (hcon,dwPos);
}

int finalizar(char tecla){
    if(tecla==ESCAPE){
           return EXIT_SUCCESS;
    }
}
