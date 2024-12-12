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
    std::string tipo;
    int tiempoRenta;
    Usuario *usuario;
    Activo *activo;
    std::string fecha;

public:
    Transaccion();

    ~Transaccion();

    Transaccion(std::string id, std::string tipo, int tiempoRenta, Usuario *usuario, Activo *activo, std::string fecha);

    std::string getId();

    std::string getTipo();

    int getTiempoRenta();

    Usuario *getUsuario();

    Activo *getActivo();

    std::string getFecha();

    void setId(std::string id);

    void setTipo(std::string tipo);

    void setTiempoRenta(int tiempoRenta);

    void setUsuario(Usuario *usuario);

    void setActivo(Activo *activo);

    void setFecha(std::string fecha);
};
#endif //TRANSACCION_H
