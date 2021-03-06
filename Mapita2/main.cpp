/*#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Nivel.h"

using namespace std;

int main(){
    Posicion pos(1,1);
    Jugador yo(1,pos,"Player");
    Nivel uno;
    uno.imprimir(yo);
    return 0;
}*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

void gotoxy ( int x, int y ) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition (hcon,dwPos);
}

int main () {
    ///oculta el cursor
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon,&cci);
    ///ocultar cursor

    int mapa[15][17] = {
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    };
///imprimir matriz
    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < 17; x++) {
            cout<<mapa[y][x];
        }
        cout<<endl;
    }
///
    int x = 0;
    int y = 14;
    int cx = 0;
    int cy = 0;

    gotoxy (0,14); /// T inicia en x=0; y=16
    printf ("T");

    int ch;
    while ((ch = _getch())){///_getch() es para detectar eventos del teclado
        if(ch == 27){///si pulsas ESC, termina el proceso
            return 0;
        }
        if(ch==72){///si pulsas flecha arriba
            //cout << "up" << endl;
            if ( y > 0 ){///si no esta en la 1ra fila
                gotoxy ( x, y );///posicion incial
                cout<<mapa[y][x];///imprime el vacio que dej� al moverse
                y = y - 1;///cambia y
                gotoxy ( x, y );///se mueve
                printf ( "T" );///imprime T en la nueva posicion
            }
        }
        else if(ch==75){///si pulsas flecha izquierda
            //cout << "left" << endl;
            if ( x > 0 ){///si no esta en la primera columna
                gotoxy ( x, y );
                cout<<mapa[y][x];
                x = x - 1;
                gotoxy ( x, y );
                printf ( "T" );
            }
        }
        else if(ch==77){///si pulsas flecha derecha
            //cout << "right" << endl;
            if ( x <= 15 ) {///si no esta en la ultima columna
                gotoxy ( x, y );
                cout<<mapa[y][x];
                x = x + 1;
                gotoxy ( x, y );
                printf ( "T" );
            }
        }
        else if (ch==80){///si pulsas flecha abajo
            //cout << "down" << endl;
            if ( y <= 13 ) {///si no esta en la ultima fila
                gotoxy ( x, y );
                cout<<mapa[y][x];
                y = y + 1;
                gotoxy ( x, y );
                printf ( "T" );
            }
        }
        else{
            gotoxy ( x, y );
            printf ( "+" );
            cx = x;
            cy = y;
            gotoxy ( x, y );
            printf ( "T" );
            x = cx;
            y = cy;
        }
    }
    cin.ignore();///io que se,solo soy una paloma
    return 0;
}
