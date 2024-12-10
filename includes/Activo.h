//
// Created by herberthreyes on 7/12/24.
//

#ifndef ACTIVO_H
#define ACTIVO_H
#include <string>

class Activo {
private:
    std::string id;
    std::string nombre;
    std::string descripcion;
    //bool estaRentado

public:
    Activo();

    ~Activo();

    Activo(std::string id, std::string nombre, std::string descripcion);

    std::string getId();

    std::string getNombre();

    std::string getDescripcion();

    void setId(std::string id);

    void setNombre(std::string nombre);

    void setDescripcion(std::string descripcion);
};

#endif //ACTIVO_H
