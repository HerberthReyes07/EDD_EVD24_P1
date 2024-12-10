//
// Created by herberthreyes on 7/12/24.
//
#include "../includes/Administrador.h"

using namespace std;

Administrador::Administrador() {
};

Administrador::~Administrador() {
};

Administrador::Administrador(MatrizDispersa *matriz) {
    this->matriz = matriz;
}

MatrizDispersa *Administrador::getMatriz() {
    return this->matriz;
}

void Administrador::setMatriz(MatrizDispersa *matriz) {
    this->matriz = matriz;
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

    while (true) {
        string username;
        cout << "Ingresar Usuario: ";
        cin >> username;

        string password;
        cout << "Ingresar Contraseña: ";
        cin >> password;

        string nombre;
        cout << "Ingresar Nombre: ";
        cin >> nombre;

        string departamento;
        cout << "Ingresar Departamento: ";
        cin >> departamento;

        string empresa;
        cout << "Ingresar Empresa: ";
        cin >> empresa;

        Usuario *usuario = new Usuario(username, password, nombre, departamento, empresa);
        if (this->matriz->buscarUsuario(usuario) != nullptr) {
            cout << "Error!. Ya existe un usuario con mismos: username, departamento y empresa\n" << endl;
        } else {
            this->matriz->insertarUsuario(usuario);
            break;
        }
    }
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

bool Administrador::insertarAtras(string username) {
    while (true) {
        cout << "$$$$$$$$$$$$$$$$$$$$      1. Insertar adelante de usuario: " << username <<
                "        $$$$$$$$$$$$$$$$$$$$\n" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$      2. Insertar atrás de usuario: " << username <<
                "        $$$$$$$$$$$$$$$$$$$$\n"
                << endl;

        int opcion;
        cout << "Ingresar opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                return false;
            }
            case 2: {
                return true;
            }
            default: {
                cout << "Error!. Por favor ingrese una opción válida\n" << endl;
                break;
            }
        }
    }
}
