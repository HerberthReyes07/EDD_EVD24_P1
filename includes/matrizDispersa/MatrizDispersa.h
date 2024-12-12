//
// Created by herberthreyes on 7/12/24.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "NodoMD.h"
#include "../Usuario.h"

class MatrizDispersa {
private:
    int cont;
    NodoMD *cabezaHorizontal;
    NodoMD *cabezaVertical;

public:
    MatrizDispersa();

    ~MatrizDispersa();

    int getCont();

    void setCont(int cont);

    NodoMD* getCH();

    NodoMD *getCV();

    NodoMD *getCabezaHorizontal(std::string departamento);

    NodoMD *getCabezaVertical(std::string empresa);

    NodoMD *setCabezaHorizontal(std::string departamento);

    NodoMD *setCabezaVertical(std::string empresa);

    NodoMD *buscarCabezaHorizontal(NodoMD *usuario);

    NodoMD *buscarCabezaVertical(NodoMD *usuario);

    NodoMD *buscarUsuario(Usuario *usuario);

    bool estaVacia();

    bool masAbajo(NodoMD *cabeceraVertical, NodoMD* empresa);

    bool masDerecha(NodoMD *cabeceraHorizontal, NodoMD*departamento);

    void insertarUsuario(Usuario *usuarioNuevo);

    void insertarUsuarioAlFinalHorizontal(NodoMD *usuarioNuevo, NodoMD *cabeceraHorizontal);

    void insertarUsuarioAlFinalVertical(NodoMD *usuarioNuevo, NodoMD *cabeceraVertical);

    void insertarUsuarioEnMedioHorizontal(NodoMD *usuario, NodoMD *arriba, NodoMD *abajo);

    void insertarUsuarioEnMedioVertical(NodoMD *usuario, NodoMD *siguiente, NodoMD *anterior);

    void insertarUsuarioAtrasAdelante(NodoMD *usuarioNuevo, NodoMD *usuarioActual, bool insertarAtras);

    void insertarUsuarioAlFinal(NodoMD *usuarioNuevo, NodoMD *cabeceraHorizontal, NodoMD *cabeceraVertical);
};
#endif //MATRIZDISPERSA_H
