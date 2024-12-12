//
// Created by herberthreyes on 11/12/24.
//

#ifndef NODOLCDE_H
#define NODOLCDE_H
#include "../Transaccion.h"

class NodoLCDE {
private:
    Transaccion *transaccion;
    NodoLCDE *siguiente;
    NodoLCDE *anterior;

public:
    NodoLCDE();

    ~NodoLCDE();

    NodoLCDE(Transaccion *transaccion);

    Transaccion *getTransaccion();

    NodoLCDE *getSiguiente();

    NodoLCDE *getAnterior();

    void setTransaccion(Transaccion *transaccion);

    void setSiguiente(NodoLCDE *siguiente);

    void setAnterior(NodoLCDE *anterior);
};
#endif //NODOLCDE_H
