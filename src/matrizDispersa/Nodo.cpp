//
// Created by herberthreyes on 8/12/24.
//
#include "../../includes/matrizDispersa/Nodo.h"

Nodo::Nodo(){};

Nodo::~Nodo(){};

Nodo::Nodo(Usuario *usuario) {
    this->usuario = usuario;
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}

Usuario *Nodo::getUsuario() {
    return this->usuario;
}

Nodo *Nodo::getSiguiente() {
    return this->siguiente;
}

Nodo *Nodo::getAnterior() {
    return this->anterior;
}

Nodo *Nodo::getArriba() {
    return this->arriba;
}

Nodo *Nodo::getAbajo() {
    return this->abajo;
}

Nodo *Nodo::getAdelante() {
    return this->adelante;
}

Nodo *Nodo::getAtras() {
    return this->atras;
}

int Nodo::getIdNodo() {
    return this->idNodo;
}

int Nodo::getGrupoVertical() {
    return this->grupoVertical;
}

void Nodo::setSiguiente(Nodo *siguiente) {
    this->siguiente = siguiente;
}

void Nodo::setAnterior(Nodo *anterior) {
    this->anterior = anterior;
}

void Nodo::setArriba(Nodo *arriba) {
    this->arriba = arriba;
}

void Nodo::setAbajo(Nodo *abajo) {
    this->abajo = abajo;
}

void Nodo::setAdelante(Nodo *adelante) {
    this->adelante = adelante;
}

void Nodo::setAtras(Nodo *atras) {
    this->atras = atras;
}

void Nodo::setIdNodo(int idNodo) {
    this->idNodo = idNodo;
}

void Nodo::setGrupoVertical(int grupoVertical) {
    this->grupoVertical = grupoVertical;
}

