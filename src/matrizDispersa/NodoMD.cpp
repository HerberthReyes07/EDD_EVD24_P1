//
// Created by herberthreyes on 8/12/24.
//
#include "../../includes/matrizDispersa/NodoMD.h"

NodoMD::NodoMD(){};

NodoMD::~NodoMD(){};

NodoMD::NodoMD(Usuario *usuario) {
    this->usuario = usuario;
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}

Usuario *NodoMD::getUsuario() {
    return this->usuario;
}

NodoMD *NodoMD::getSiguiente() {
    return this->siguiente;
}

NodoMD *NodoMD::getAnterior() {
    return this->anterior;
}

NodoMD *NodoMD::getArriba() {
    return this->arriba;
}

NodoMD *NodoMD::getAbajo() {
    return this->abajo;
}

NodoMD *NodoMD::getAdelante() {
    return this->adelante;
}

NodoMD *NodoMD::getAtras() {
    return this->atras;
}

int NodoMD::getIdNodo() {
    return this->idNodo;
}

int NodoMD::getGrupoVertical() {
    return this->grupoVertical;
}

void NodoMD::setSiguiente(NodoMD *siguiente) {
    this->siguiente = siguiente;
}

void NodoMD::setAnterior(NodoMD *anterior) {
    this->anterior = anterior;
}

void NodoMD::setArriba(NodoMD *arriba) {
    this->arriba = arriba;
}

void NodoMD::setAbajo(NodoMD *abajo) {
    this->abajo = abajo;
}

void NodoMD::setAdelante(NodoMD *adelante) {
    this->adelante = adelante;
}

void NodoMD::setAtras(NodoMD *atras) {
    this->atras = atras;
}

void NodoMD::setIdNodo(int idNodo) {
    this->idNodo = idNodo;
}

void NodoMD::setGrupoVertical(int grupoVertical) {
    this->grupoVertical = grupoVertical;
}

