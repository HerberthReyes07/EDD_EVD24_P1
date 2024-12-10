//
// Created by herberthreyes on 7/12/24.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "Nodo.h"
#include "../Usuario.h"

class MatrizDispersa {
private:
    Nodo *cabezaHorizontal;
    Nodo *cabezaVertical;

public:
    MatrizDispersa();

    ~MatrizDispersa();

    Nodo *getCabezaHorizontal(std::string departamento);

    Nodo *getCabezaVertical(std::string empresa);

    Nodo *setCabezaHorizontal(std::string departamento);

    Nodo *setCabezaVertical(std::string empresa);

    Nodo *buscarCabezaHorizontal(Nodo *usuario);

    Nodo *buscarCabezaVertical(Nodo *usuario);

    Nodo *buscarUsuario(Usuario *usuario);

    bool estaVacia();

    bool masAbajo(Nodo *cabeceraVertical, Nodo* empresa);

    bool masDerecha(Nodo *cabeceraHorizontal, Nodo*departamento);

    void insertarUsuario(Usuario *usuarioNuevo);

    void insertarUsuarioAlFinalHorizontal(Nodo *usuarioNuevo, Nodo *cabeceraHorizontal);

    void insertarUsuarioAlFinalVertical(Nodo *usuarioNuevo, Nodo *cabeceraVertical);

    void insertarUsuarioEnMedioHorizontal(Nodo *usuario, Nodo *arriba, Nodo *abajo);

    void insertarUsuarioEnMedioVertical(Nodo *usuario, Nodo *siguiente, Nodo *anterior);

    void insertarUsuarioAtrasAdelante(Nodo *usuarioNuevo, Nodo *usuarioActual, bool insertarAtras);

    void insertarUsuarioAlFinal(Nodo *usuarioNuevo, Nodo *cabeceraHorizontal, Nodo *cabeceraVertical);
};
#endif //MATRIZDISPERSA_H
