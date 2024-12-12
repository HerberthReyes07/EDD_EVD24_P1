#include "../../includes/listaCircularDoblementeEnlazada/NodoLCDE.h"
//
// Created by herberthreyes on 11/12/24.
//
NodoLCDE::NodoLCDE() {
}

NodoLCDE::~NodoLCDE() {
}

NodoLCDE::NodoLCDE(Transaccion *transaccion) {
    this->transaccion = transaccion;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Transaccion *NodoLCDE::getTransaccion() {
    return this->transaccion;
}

NodoLCDE *NodoLCDE::getAnterior() {
    return this->anterior;
}

NodoLCDE *NodoLCDE::getSiguiente() {
    return this->siguiente;
}

void NodoLCDE::setTransaccion(Transaccion *transaccion) {
    this->transaccion = transaccion;
}

void NodoLCDE::setAnterior(NodoLCDE *anterior) {
    this->anterior = anterior;
}

void NodoLCDE::setSiguiente(NodoLCDE *siguiente) {
    this->siguiente = siguiente;
}
