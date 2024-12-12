#include "../../includes/listaCircularDoblementeEnlazada/ListaCircularDoble.h"
//
// Created by herberthreyes on 11/12/24.
//
ListaCircularDoble::ListaCircularDoble() {
    this->cabeza = nullptr;
    this->cola = nullptr;
}

ListaCircularDoble::~ListaCircularDoble() {
}

NodoLCDE *ListaCircularDoble::getCabeza() {
    return this->cabeza;
}

NodoLCDE *ListaCircularDoble::getCola() {
    return this->cola;
}

void ListaCircularDoble::setCabeza(NodoLCDE *cabeza) {
    this->cabeza = cabeza;
}

void ListaCircularDoble::setCola(NodoLCDE *cola) {
    this->cola = cola;
}

void ListaCircularDoble::agregarTransaccion(Transaccion *transaccion) {
    NodoLCDE *nodoTransaccion = new NodoLCDE(transaccion);
    if (this->cabeza == nullptr) {
        this->cabeza = nodoTransaccion;
        this->cola = nodoTransaccion;
        return;
    }
    cola->setSiguiente(nodoTransaccion);
    nodoTransaccion->setAnterior(cola);
    this->cola = nodoTransaccion;
    this->cabeza->setAnterior(this->cola);
    this->cola->setSiguiente(this->cabeza);
}
