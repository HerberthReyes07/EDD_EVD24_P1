//
// Created by herberthreyes on 7/12/24.
//

#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <string>
#include "Usuario.h"
#include "Activo.h"

class Transaccion {
private:
    std::string id;
    int tiempoRenta;
    Usuario *usuario;
    Activo *activo;
    //fecha

public:
    Transaccion();

    ~Transaccion();

    Transaccion(std::string id, int tiempoRenta, Usuario *usuario, Activo *activo);

    std::string getId();

    int getTiempoRenta();

    Usuario *getUsuario();

    Activo *getActivo();

    void setId(std::string id);

    void setTiempoRenta(int tiempoRenta);

    void setUsuario(Usuario *usuario);

    void setActivo(Activo *activo);
};
#endif //TRANSACCION_H
