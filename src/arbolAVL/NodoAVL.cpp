#include "../../includes/arbolAVL/NodoAVL.h"
//
// Created by herberthreyes on 13/12/24.
//
NodoAVL::NodoAVL() {
}

NodoAVL::~NodoAVL() {
}

NodoAVL::NodoAVL(Activo *activo) {
    this->activo = activo;
    this->factorEquilibrio = 0;
    this->izquierda = nullptr;
    this->derecha = nullptr;
}

Activo *NodoAVL::getActivo() {
    return this->activo;
}

int NodoAVL::getFactorEquilibrio() {
    return this->factorEquilibrio;
}

NodoAVL *&NodoAVL::getIzquierda() {
    return this->izquierda;
}

NodoAVL *&NodoAVL::getDerecha() {
    return this->derecha;
}

void NodoAVL::setActivo(Activo *activo) {
    this->activo = activo;
}

void NodoAVL::setFactorEquilibrio(int factorEquilibrio) {
    this->factorEquilibrio = factorEquilibrio;
}

void NodoAVL::setIzquierda(NodoAVL *izquierda) {
    this->izquierda = izquierda;
}

void NodoAVL::setDerecha(NodoAVL *derecha) {
    this->derecha = derecha;
}
