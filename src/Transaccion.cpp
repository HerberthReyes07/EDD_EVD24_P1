//
// Created by herberthreyes on 7/12/24.
//
#include "../includes/Transaccion.h"

Transaccion::Transaccion() {
};

Transaccion::~Transaccion() {
};

Transaccion::Transaccion(std::string id, std::string tipo, int tiempoRenta, Usuario *usuario, Activo *activo, std::string fecha) {
    this->id = id;
    this->tipo = tipo;
    this->tiempoRenta = tiempoRenta;
    this->usuario = usuario;
    this->activo = activo;
    this->fecha = fecha;
}

std::string Transaccion::getId() {
    return this->id;
}

std::string Transaccion::getTipo() {
    return this->tipo;
}

int Transaccion::getTiempoRenta() {
    return this->tiempoRenta;
}

Usuario *Transaccion::getUsuario() {
    return this->usuario;
}

Activo *Transaccion::getActivo() {
    return this->activo;
}

std::string Transaccion::getFecha() {
    return this->fecha;
}

void Transaccion::setId(std::string id) {
    this->id = id;
}

void Transaccion::setTipo(std::string tipo) {
    this->tipo = tipo;
}

void Transaccion::setTiempoRenta(int tiempoRenta) {
    this->tiempoRenta = tiempoRenta;
}

void Transaccion::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

void Transaccion::setActivo(Activo *activo) {
    this->activo = activo;
}

void Transaccion::setFecha(std::string fecha) {
    this->fecha = fecha;
}