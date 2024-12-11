//
// Created by herberthreyes on 7/12/24.
//

#ifndef NODO_H
#define NODO_H
#include "../Usuario.h"

class Nodo {
private:
    Usuario *usuario;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo *arriba;
    Nodo *abajo;
    Nodo *adelante;
    Nodo *atras;
    int idNodo;
    int grupoVertical;

public:
    Nodo();

    ~Nodo();

    Nodo(Usuario *usuario);

    Usuario *getUsuario();

    Nodo *getSiguiente();

    Nodo *getAnterior();

    Nodo *getArriba();

    Nodo *getAbajo();

    Nodo *getAdelante();

    Nodo *getAtras();

    int getIdNodo();

    int getGrupoVertical();

    void setUsuario(Usuario *usuario);

    void setSiguiente(Nodo *siguiente);

    void setAnterior(Nodo *anterior);

    void setArriba(Nodo *arriba);

    void setAbajo(Nodo *abajo);

    void setAdelante(Nodo *adelante);

    void setAtras(Nodo *atras);

    void setIdNodo(int idNodo);

    void setGrupoVertical(int grupoVertical);
};
#endif //NODO_H
