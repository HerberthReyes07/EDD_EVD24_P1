//
// Created by herberthreyes on 7/12/24.
//
#include "../includes/Administrador.h"

using namespace std;

Administrador::Administrador() {
};

Administrador::~Administrador() {
};

Administrador::Administrador(Usuario *usuario) {
    this->usuario = usuario;
}

Usuario *Administrador::getUsuario() {
    return this->usuario;
}

void Administrador::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

void Administrador::menu() {
    bool sesionCerrada = false;

    while (true) {
        cout << "$$$$$$$$$$$$$$$$$$$$                    Renta de Activos                    $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$                      Administrador                     $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   1. Registrar Usuario                                 $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   2. Reporte Matriz Dispersa                           $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   3. Reporte Activos Disponibles de un Departamento    $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   4. Reporte Activos Disponibles de una Empresa        $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   5. Reporte Transacciones                             $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   6. Reporte Activos de un Usuario                     $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   7. Activos Rentados por un Usuario                   $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   8. Ordenar Transacciones                             $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   9. Cerrar sesión                                     $$$$$$$$$$$$$$$$$$$$\n" <<
                endl;

        int opcion;
        cout << "Ingresar opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                registrarUsuario();
                break;
            }
            case 2: {
                reporteMatrizDispersa();
                break;
            }
            case 3: {
                reporteActivosDisponiblesDepartamento();
                break;
            }
            case 4: {
                reporteActivosDisponiblesEmpresa();
                break;
            }
            case 5: {
                reporteTransacciones();
                break;
            }
            case 6: {
                reporteActivosUsuario();
                break;
            }
            case 7: {
                activosRentadosUsuario();
                break;
            }
            case 8: {
                ordenarTransacciones();
                break;
            }
            case 9: {
                sesionCerrada = true;
                break;
            }
            default: {
                cout << "Error!. Por favor ingrese una opción válida\n" << endl;
                break;
            }
        }
        if (sesionCerrada) {
            break;
        }
    }
}

void Administrador::registrarUsuario() {
    cout << "$$$$$$$$$$$$$$$$$$$$      Registrar Usuario        $$$$$$$$$$$$$$$$$$$$\n" << endl;
    /*//Usuario usuario = new Usuario();
    //cin >> usuario.usuario; ...
    cout << "Ingresar Usuario: ";
    cout << "Ingresar Contraseña: ";
    cout << "Ingresar Departamento: ";
    cout << "Ingresar Empresa: ";*/
}

void Administrador::reporteMatrizDispersa() {
}

void Administrador::reporteActivosDisponiblesDepartamento() {
}

void Administrador::reporteActivosDisponiblesEmpresa() {
}

void Administrador::reporteTransacciones() {
}

void Administrador::reporteActivosUsuario() {
}

void Administrador::activosRentadosUsuario() {
}

void Administrador::ordenarTransacciones() {
}
