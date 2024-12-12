//
// Created by herberthreyes on 11/12/24.
//

#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include "NodoLCDE.h"

class ListaCircularDoble {
private:
    NodoLCDE *cabeza;
    NodoLCDE *cola;

public:
    ListaCircularDoble();

    ~ListaCircularDoble();

    NodoLCDE *getCabeza();

    NodoLCDE *getCola();

    void setCabeza(NodoLCDE *cabeza);

    void setCola(NodoLCDE *cola);

    void agregarTransaccion(Transaccion *transaccion);
};
#endif //LISTACIRCULARDOBLE_H
