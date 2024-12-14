//
// Created by herberthreyes on 13/12/24.
//

#ifndef NODOAAVL_H
#define NODOAAVL_H
#include "../Activo.h"

class NodoAVL {
private:
    Activo *activo;
    int factorEquilibrio;
    NodoAVL *izquierda;
    NodoAVL *derecha;

public:
    NodoAVL();

    ~NodoAVL();

    NodoAVL(Activo *activo);

    Activo *getActivo();

    int getFactorEquilibrio();

    NodoAVL *&getIzquierda();

    NodoAVL *&getDerecha();

    void setActivo(Activo *activo);

    void setFactorEquilibrio(int factorEquilibrio);

    void setIzquierda(NodoAVL *izquierda);

    void setDerecha(NodoAVL *derecha);
};
#endif //NODOAAVL_H
