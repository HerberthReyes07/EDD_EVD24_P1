//
// Created by herberthreyes on 7/12/24.
//

#ifndef NODO_H
#define NODO_H
#include "../Usuario.h"

class NodoMD {
private:
    Usuario *usuario;
    NodoMD *siguiente;
    NodoMD *anterior;
    NodoMD *arriba;
    NodoMD *abajo;
    NodoMD *adelante;
    NodoMD *atras;
    int idNodo;
    int grupoVertical;

public:
    NodoMD();

    ~NodoMD();

    NodoMD(Usuario *usuario);

    Usuario *getUsuario();

    NodoMD *getSiguiente();

    NodoMD *getAnterior();

    NodoMD *getArriba();

    NodoMD *getAbajo();

    NodoMD *getAdelante();

    NodoMD *getAtras();

    int getIdNodo();

    int getGrupoVertical();

    void setUsuario(Usuario *usuario);

    void setSiguiente(NodoMD *siguiente);

    void setAnterior(NodoMD *anterior);

    void setArriba(NodoMD *arriba);

    void setAbajo(NodoMD *abajo);

    void setAdelante(NodoMD *adelante);

    void setAtras(NodoMD *atras);

    void setIdNodo(int idNodo);

    void setGrupoVertical(int grupoVertical);
};
#endif //NODO_H
