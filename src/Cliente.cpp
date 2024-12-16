//
// Created by herberthreyes on 7/12/24.
//

#include "../includes/Cliente.h"
#include "../includes/Transaccion.h"
#include <ctime>
#include <limits>

using namespace std;

Cliente::Cliente() {
};

Cliente::~Cliente() {
};

Cliente::Cliente(NodoMD *usuario, MatrizDispersa *matriz, ListaCircularDoble *listaCircularDoble) {
    this->usuario = usuario;
    this->matriz = matriz;
    this->listaCircularDoble = listaCircularDoble;
}

NodoMD *Cliente::getUsuario() {
    return this->usuario;
}

void Cliente::setUsuario(NodoMD *usuario) {
    this->usuario = usuario;
}

MatrizDispersa *Cliente::getMatriz() {
    return this->matriz;
}

void Cliente::setMatriz(MatrizDispersa *matriz) {
    this->matriz = matriz;
}

void Cliente::menu() {
    bool sesionCerrada = false;
    while (true) {
        cout << "\n$$$$$$$$$$$$$$$$$$$$     Renta de Activos       $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$       " << this->usuario->getUsuario()->getUsername() <<
                "          $$$$$$$$$$$$$$$$$$$$" <<
                endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   1. Agregar Activo        $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   2. Eliminar Activo       $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   3. Modificar Activo      $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   4. Rentar Activo         $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   5. Activos Rentados      $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   6. Mis Activos Rentados  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   7. Cerrar Sesión         $$$$$$$$$$$$$$$$$$$$\n" << endl;

        int opcion;

        try {
            cout << "Ingresar opción: ";
            cin >> opcion;
            if (!cin) {
                throw invalid_argument("Entrada inválida, porfavor intentelo denuevo.");
            }
            cin.ignore();
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                agregarActivo();
                break;
            }
            case 2: {
                eliminarActivo();
                break;
            }
            case 3: {
                modificarActivo();
                break;
            }
            case 4: {
                rentarActivo();
                break;
            }
            case 5: {
                activosRentados();
                break;
            }
            case 6: {
                misActivosRentados();
                break;
            }
            case 7: {
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

void Cliente::agregarActivo() {
    cout << "\n$$$$$$$$$$$$$$$$$$$$      Agregar Activo        $$$$$$$$$$$$$$$$$$$$\n" << endl;
    //Activo *activo = new Activo();
    string nombre;
    cout << "Ingresar Nombre: ";
    getline(cin, nombre);

    string descripcion;
    cout << "Ingresar Descripcion: ";
    getline(cin, descripcion);

    int diasMaxRenta;

    while (true) {
        try {
            cout << "Ingresar maximo de dias para rentar el activo: ";
            cin >> diasMaxRenta;
            if (!cin) {
                throw invalid_argument("Entrada inválida, porfavor intentelo denuevo.");
            }
            cin.ignore();
            break;
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    Activo *activo = new Activo(generarAlfanumerico(), nombre, descripcion, diasMaxRenta, false);
    usuario->getUsuario()->getActivos()->insertar(activo);
}

void Cliente::eliminarActivo() {
    cout << "\n$$$$$$$$$$$$$$$$$$$$      Eliminar Activo        $$$$$$$$$$$$$$$$$$$$\n" << endl;
    usuario->getUsuario()->getActivos()->recorrer();

    cout << endl;
    string id;
    cout << "Ingresar ID del activo a eliminar: ";
    getline(cin, id);
    //cin.ignore();

    cout << "\n$$$$$$$$$$$$$$$$$$$$     Eliminando Activo       $$$$$$$$$$$$$$$$$$$$\n" << endl;
    usuario->getUsuario()->getActivos()->eliminar(id);
}

void Cliente::modificarActivo() {
    cout << "\n$$$$$$$$$$$$$$$$$$$$      Modificar Activo      $$$$$$$$$$$$$$$$$$$$\n" << endl;
    usuario->getUsuario()->getActivos()->recorrer();

    cout << endl;
    string id;
    cout << "Ingresar ID del activo a modificar: ";
    getline(cin, id);

    cout << "\n$$$$$$$$$$$$$$$$$$$$     Modificando Activo       $$$$$$$$$$$$$$$$$$$$\n" << endl;

    string descripcion;
    cout << "Ingresar descripción nueva: ";
    getline(cin, descripcion);

    Activo *activo = usuario->getUsuario()->getActivos()->buscar(id);
    if (activo != nullptr) {
        if (activo->getEstaRentado() == false) {
            activo->setDescripcion(descripcion);
            cout << "\nActivo Modificado;"
                    "\nID = " << activo->getId() <<
                    "\nNombre = " << activo->getNombre() <<
                    "\nDescripcion = " << activo->getDescripcion() << endl;
        } else {
            cout << "No se puede modificar el activo con el id: " << id << " ya que esta rentado" << endl;
        }
    } else {
        cout << "No se puede modificar el activo con el id: " << id <<
                " ya que no se encontro. Por favor verifique el id ingresado" << endl;
    }
}

void Cliente::rentarActivo() {
    bool regresarMenu = false;
    while (true) {
        cout << "\n$$$$$$$$$$$$$$$$$$$$     Catálogo de Activos     $$$$$$$$$$$$$$$$$$$$\n" << endl;

        verCatalogo();

        cout << "\n$$$$$$$$$$$$$$$$$$$$   1. Rentar Activo        $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   2. Regresar al menú     $$$$$$$$$$$$$$$$$$$$\n" << endl;

        int opcion;
        try {
            cout << "Ingresar opción: ";
            cin >> opcion;
            if (!cin) {
                throw invalid_argument("Entrada inválida, porfavor intentelo denuevo.");
            }
            cin.ignore();
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                cout << "\n$$$$$$$$$$$$$$$$$$$$     Renta de Activo     $$$$$$$$$$$$$$$$$$$$\n" << endl;

                string id;
                cout << "Ingresar id del activo a rentar: ";
                getline(cin, id);

                Activo *activo = buscarActivo(id);

                if (activo != nullptr) {
                    if (activo->getEstaRentado() == false) {
                        cout << "\nActivo a Rentar;"
                                "\nID = " << activo->getId() <<
                                "\nNombre = " << activo->getNombre() <<
                                "\nDescripcion = " << activo->getDescripcion() <<
                                "\nTiempo maximo de renta = " << activo->getTiempoMaxRenta() << endl;

                        cout << endl;
                        int diasRenta;

                        try {
                            cout << "Ingresar dias por rentar: ";
                            cin >> diasRenta;
                            if (!cin) {
                                throw invalid_argument("Entrada inválida, porfavor intentelo denuevo.");
                            }
                            cin.ignore();
                        } catch (const invalid_argument &e) {
                            cout << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }

                        if (diasRenta <= activo->getTiempoMaxRenta()) {
                            Transaccion *transaccion = new Transaccion(generarAlfanumerico(), "Renta", diasRenta,
                                                                       usuario->getUsuario(), activo, obtenerFecha());
                            listaCircularDoble->agregarTransaccion(transaccion);
                            activo->setEstaRentado(true);
                            cout << "Transaccion realizada con exito!" << endl;
                        } else {
                            cout << "No puede rentar el activo con el id: " << id <<
                                    " ya que excede el máximo de días que puede rentarse (" << activo->
                                    getTiempoMaxRenta() << ")" << endl;
                        }
                    } else {
                        cout << "No se puede rentar el activo con el id: " << id << " ya que esta rentado" << endl;
                    }
                } else {
                    cout << "No se puede rentar el activo con el id: " << id <<
                            " ya que no se encontro. Por favor verifique el id ingresado" << endl;
                }

                break;
            }
            case 2: {
                regresarMenu = true;
                break;
            }
            default: {
                cout << "Error!. Por favor ingrese una opción válida\n" << endl;
                break;
            }
        }
        if (regresarMenu) {
            //regresarMenu = false;
            break;
        }
    }
}

void Cliente::verCatalogo() {
    NodoMD *nodoV = matriz->getCV();

    while (nodoV != nullptr) {
        NodoMD *nodoU = nodoV->getSiguiente();
        while (nodoU != nullptr) {
            NodoMD *nodoUA = nodoU;
            while (nodoUA != nullptr) {
                if (nodoUA != usuario) {
                    nodoUA->getUsuario()->getActivos()->recorrer();
                }
                nodoUA = nodoUA->getAtras();
            }
            nodoU = nodoU->getSiguiente();
        }
        nodoV = nodoV->getAbajo();
    }
}

Activo *Cliente::buscarActivo(std::string id) {
    NodoMD *nodoV = matriz->getCV();

    while (nodoV != nullptr) {
        NodoMD *nodoU = nodoV->getSiguiente();
        while (nodoU != nullptr) {
            NodoMD *nodoUA = nodoU;
            while (nodoUA != nullptr) {
                if (nodoUA != usuario) {
                    Activo *activo = nodoUA->getUsuario()->getActivos()->buscar(id);
                    if (activo != nullptr) {
                        return activo;
                    }
                }
                nodoUA = nodoUA->getAtras();
            }
            nodoU = nodoU->getSiguiente();
        }
        nodoV = nodoV->getAbajo();
    }
    return nullptr;
}

void Cliente::activosRentados() {
    bool regresarMenu = false;
    while (true) {
        cout << "\n$$$$$$$$$$$$$$$$$$$$     Activos rentados     $$$$$$$$$$$$$$$$$$$$\n" << endl;

        verCatalogoActivosRentados();

        cout << "\n$$$$$$$$$$$$$$$$$$$$   1. Devolver Activo      $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   2. Regresar al menú     $$$$$$$$$$$$$$$$$$$$\n" << endl;

        int opcion;

        try {
            cout << "Ingresar opción: ";
            cin >> opcion;
            if (!cin) {
                throw invalid_argument("Entrada inválida, porfavor intentelo denuevo.");
            }
            cin.ignore();
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                cout << "\n$$$$$$$$$$$$$$$$$$$$     Devolución de Activo     $$$$$$$$$$$$$$$$$$$$\n" << endl;

                string id;
                cout << "Ingresar id del activo a devolver: ";
                getline(cin, id);
                //verificar que el id exista
                Activo *activo = buscarActivo(id);

                if (activo != nullptr) {
                    if (activo->getEstaRentado() == true) {
                        cout << "\nActivo a Devuelto;"
                                "\nID = " << activo->getId() <<
                                "\nNombre = " << activo->getNombre() <<
                                "\nDescripcion = " << activo->getDescripcion() << endl;

                        Transaccion *transaccion = new Transaccion(generarAlfanumerico(), "Devolucion",
                                                                   activo->getTiempoMaxRenta(), usuario->getUsuario(),
                                                                   activo, obtenerFecha());
                        listaCircularDoble->agregarTransaccion(transaccion);
                        activo->setEstaRentado(false);
                        cout << "Activo devuelto exitosamente!\n" << endl;
                    } else {
                        cout << "No se puede devolver el activo con el id: " << id << " ya que no esta rentado" << endl;
                    }
                } else {
                    cout << "No se puede devolver el activo con el id: " << id <<
                            " ya que no se encontro. Por favor verifique el id ingresado" << endl;
                }

                break;
            }
            case 2: {
                regresarMenu = true;
                break;
            }
            default: {
                cout << "Error!. Por favor ingrese una opción válida\n" << endl;
                break;
            }
        }
        if (regresarMenu) {
            //regresarMenu = false;
            break;
        }
    }
}

void Cliente::verCatalogoActivosRentados() {
    NodoLCDE *transActual = listaCircularDoble->getCabeza();
    if (transActual == nullptr) {
        return;
    }
    while (true) {
        if (transActual->getTransaccion()->getUsuario() == usuario->getUsuario() && transActual->getTransaccion()->
            getTipo() == "Renta") {
            NodoLCDE *transSiguiente = transActual->getSiguiente();
            bool enRenta = true;
            while (true) {
                if (transSiguiente == listaCircularDoble->getCabeza()) {
                    break;
                }
                if (transSiguiente->getTransaccion()->getTipo() == "Devolucion"
                    && transSiguiente->getTransaccion()->getUsuario() == transActual->getTransaccion()->getUsuario()
                    && transSiguiente->getTransaccion()->getActivo() == transActual->getTransaccion()->getActivo()) {
                    enRenta = false;
                    break;
                }
                transSiguiente = transSiguiente->getSiguiente();
            }
            if (enRenta) {
                cout << "ID = " << transActual->getTransaccion()->getActivo()->getId()
                        << " ; Nombre = " << transActual->getTransaccion()->getActivo()->getNombre()
                        << " ; Descripcion = " << transActual->getTransaccion()->getActivo()->getDescripcion()
                        << " ; Tiempo rentado = " << transActual->getTransaccion()->getTiempoRenta() << endl;
            }
        }
        transActual = transActual->getSiguiente();
        if (transActual == listaCircularDoble->getCabeza()) {
            break;
        }
    }
}

void Cliente::misActivosRentados() {
    cout << "\n$$$$$$$$$$$$$$$$$$$$     Mis Activos rentados     $$$$$$$$$$$$$$$$$$$$\n" << endl;

    recorrerMisActivosRentados();

    while (true) {
        int opcion;
        try {
            cout << "Ingresar 1 para regresar al menú: ";
            cin >> opcion;
            if (!cin) {
                throw invalid_argument("Entrada inválida, porfavor intentelo denuevo.");
            }
            cout << endl;
            cin.ignore();
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(opcion == 1) {
            break;
        } else {
            cout << "Error!. Por favor ingrese una opción válida\n" << endl;
        }
    }
}

void Cliente::recorrerMisActivosRentados() {
    recorrerMisActivosRentados(usuario->getUsuario()->getActivos()->getRaiz());
}

void Cliente::recorrerMisActivosRentados(NodoAVL *&raiz) {
    if (raiz == nullptr) {
        return;
    }
    if (raiz->getActivo()->getEstaRentado() == true) {
        NodoLCDE *transaccion = listaCircularDoble->getCola();
        while (true) {
            if (transaccion->getTransaccion()->getActivo() == raiz->getActivo()) {
                cout << "ID = " << raiz->getActivo()->getId() << "; Nombre = " << raiz->getActivo()->getNombre()
                        << "; Descripcion = " << raiz->getActivo()->getDescripcion()
                        << "; Tiempo rentado = " << transaccion->getTransaccion()->getTiempoRenta() << endl;
                break;
            }
            transaccion = transaccion->getAnterior();
            if (transaccion == nullptr) {
                return;
            }
        }
    }
    recorrerMisActivosRentados(raiz->getIzquierda());
    recorrerMisActivosRentados(raiz->getDerecha());
}

std::string Cliente::generarAlfanumerico() {
    string id = "";
    for (int i = 0; i < 15; i++) {
        int opcion = rand() % 2;
        if (opcion == 0) {
            id += to_string(rand() % 10);
        } else {
            char letra = 97 + rand() % 26;
            id += letra;
        }
    }
    return id;
}

std::string Cliente::obtenerFecha() {
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);

    char output[50];
    strftime(output, 50, "%d/%m/%Y", &datetime);

    string fecha = string(output);
    return fecha;
}
