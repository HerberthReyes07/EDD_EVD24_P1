//
// Created by herberthreyes on 7/12/24.
//
#include "../includes/Administrador.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // Para std::system
#include <filesystem>
#include <thread> // Para std::this_thread
#include <chrono> // Para std::chrono

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
        cout << "\n$$$$$$$$$$$$$$$$$$$$                    Renta de Activos                    $$$$$$$$$$$$$$$$$$$$" <<
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
        cin.ignore();

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
        getline(cin, username);

        string password;
        cout << "Ingresar Contraseña: ";
        getline(cin, password);

        string nombre;
        cout << "Ingresar Nombre: ";
        getline(cin, nombre);

        string departamento;
        cout << "Ingresar Departamento: ";
        getline(cin, departamento);

        string empresa;
        cout << "Ingresar Empresa: ";
        getline(cin, empresa);

        Usuario *usuario = new Usuario(username, password, nombre, departamento, empresa);
        if (matriz->buscarUsuario(usuario) != nullptr) {
            cout << "Error!. Ya existe un usuario con mismos: username, departamento y empresa\n" << endl;
        } else {
            matriz->insertarUsuario(usuario);
            cout << "El usuario ha sido registrado exitosamente!\n" << endl;
            break;
        }
    }
}

void Administrador::reporteMatrizDispersa() {
    Usuario *admin = new Usuario();
    admin->setUsersname("Administrador");
    Nodo *nodoAdmin = new Nodo(admin);
    nodoAdmin->setSiguiente(matriz->getCH());
    nodoAdmin->setAbajo(matriz->getCV());
    nodoAdmin->setIdNodo(0);
    nodoAdmin->setGrupoVertical(1);

    string config =
            "bgcolor=\"#F5F5F5\";fontcolor=black;\nlabel=\"Matriz Dispersa\";\nlabelloc=\"t\";\nnodesep=0.5;\nnode [shape=box width=1.2 style=filled fillcolor=\"#004488\" fontcolor=\"#F5F5F5\" color=transparent];\nedge [fontcolor=white color=\"#ff5722\"];\n";

    string defNodo;
    string relNodo = "n2->n0;\nn3->n0;\n";
    string encuadre;

    while (nodoAdmin != nullptr) {
        Nodo *auxAdmin = nodoAdmin;
        string auxEncuadre = "{ rank=same; ";
        while (auxAdmin != nullptr) {
            string nodoActual = "n" + to_string(auxAdmin->getIdNodo());
            defNodo += nodoActual + "[label=\"";

            if (auxAdmin->getUsuario()->getUsername() == "") {
                if (auxAdmin->getUsuario()->getDepartamento() != "") {
                    defNodo += auxAdmin->getUsuario()->getDepartamento();
                } else {
                    defNodo += auxAdmin->getUsuario()->getEmpresa();
                }
            } else {
                defNodo += auxAdmin->getUsuario()->getUsername();
            }
            defNodo += "\" group=" + to_string(auxAdmin->getGrupoVertical()) + "];\n";
            auxEncuadre += nodoActual + "; ";
            if (auxAdmin->getAnterior() != nullptr) {
                relNodo += nodoActual + "->n" + to_string(auxAdmin->getAnterior()->getIdNodo()) + ";\n";
            }
            if (auxAdmin->getSiguiente() != nullptr) {
                relNodo += nodoActual + "->n" + to_string(auxAdmin->getSiguiente()->getIdNodo()) + ";\n";
            }
            if (auxAdmin->getArriba() != nullptr) {
                relNodo += nodoActual + "->n" + to_string(auxAdmin->getArriba()->getIdNodo()) + ";\n";
            }
            if (auxAdmin->getAbajo() != nullptr) {
                relNodo += nodoActual + "->n" + to_string(auxAdmin->getAbajo()->getIdNodo()) + ";\n";
            }
            auxAdmin = auxAdmin->getSiguiente();
        }
        auxEncuadre += " }\n";
        encuadre += auxEncuadre;
        nodoAdmin = nodoAdmin->getAbajo();
    }
    string grafico = "digraph G {\n" + config + defNodo + relNodo + encuadre + "}";
    graficar("../reporteMatrizDispersa/matriz_dispersa.svg", grafico);
    cout << "SE HA GRAFICADO CORRECTAMENTE" << endl;
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
        cout << "\n$$$$$$$$$$$$$$$$$$$$      1. Insertar adelante de usuario: " << username <<
                "        $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$      2. Insertar atrás de usuario: " << username <<
                "        $$$$$$$$$$$$$$$$$$$$\n"
                << endl;

        int opcion;
        cout << "Ingresar opción: ";
        cin >> opcion;
        cin.ignore();

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

void Administrador::graficar(std::string path, std::string grafico) {
    std::ofstream fichero;
    try {
        // Abre el archivo para escritura
        fichero.open("aux_grafico.dot");
        if (!fichero.is_open()) {
            throw std::ios_base::failure("Error al abrir el archivo aux_grafico.dot");
        }
        // Escribe el contenido de "cadena" en el archivo
        fichero << grafico;
    } catch (const std::exception &e) {
        std::cerr << "Error al escribir el archivo aux_grafico.dot: " << e.what() << std::endl;
    }
    // Cierra el archivo si está abierto
    if (fichero.is_open()) {
        fichero.close();
    }

    try {
        // Ejecuta el comando para generar el gráfico

        string command = "dot -Tsvg -o " + path + " aux_grafico.dot";
        int result = system(command.c_str());

        if (result != 0) {
            throw runtime_error("Error al ejecutar el comando dot");
        }
        // Espera 500ms para dar tiempo a que el archivo de imagen se genere
        this_thread::sleep_for(chrono::milliseconds(500));
    } catch (const exception &e) {
        cerr << "Error al generar la imagen para el archivo aux_grafico.dot: " << e.what() << endl;
    }
}
