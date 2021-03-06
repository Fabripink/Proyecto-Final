#ifndef JUGADOR_H
#define JUGADOR_H
#include "Individuo.h"
#include "Bomba.h"


//Clase Jugador -> SE APLICA HERENCIA:
//Es una clase derivada de Individuo cuya
//peculiaridad es que el movimiento y los ataques
//dependen de la pulsacion de las teclas.

class Jugador:public Individuo{
    Bomba bom;
    public:
        Jugador(int,Posicion,string,char);
        void movimiento(char,int[][17],Posicion&);
//      movimiento()->SE APLICA POLIMORFISMO
//      Implementacion individual de movimiento, el cual era un
//      metodo virtual en la clase padre Individuo.
        bool soltarBomba(char,int[][17],Posicion);
        void soltarBomba(int[][17],Posicion);
        Bomba *get_bomba(){return &bom;}
};

#endif // JUGADOR_H
