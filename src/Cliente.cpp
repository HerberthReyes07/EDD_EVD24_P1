//
// Created by herberthreyes on 7/12/24.
//

#include "../includes/Cliente.h"


using namespace std;

Cliente::Cliente() {
};

Cliente::~Cliente() {
};

Cliente::Cliente(NodoMD *usuario, MatrizDispersa *matriz) {
    this->usuario = usuario;
    this->matriz = matriz;
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
        cout << "$$$$$$$$$$$$$$$$$$$$     Renta de Activos       $$$$$$$$$$$$$$$$$$$$" << endl;
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
        cout << "Ingresar opción: ";
        cin >> opcion;

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
    cout << "$$$$$$$$$$$$$$$$$$$$      Agregar Activo        $$$$$$$$$$$$$$$$$$$$\n" << endl;
    /*
     * Activo activo = new activo();
     * cout << "Ingresar nombre: ";
     * cin >> activo.nombre;
     * cout << "Ingresar descripción: ";
     */
}

void Cliente::eliminarActivo() {
    cout << "$$$$$$$$$$$$$$$$$$$$      Eliminar Activo        $$$$$$$$$$$$$$$$$$$$\n" << endl;
    /*
     * // Lista de activos
     * string id;
     * cout << "Ingresar ID del activo a eliminar: ";
     * cin >> id;
     * // Buscar y eliminar
     * cout << "$$$$$$$$$$$$$$$$$$$$     Eliminando Activo       $$$$$$$$$$$$$$$$$$$$\n" << endl;
     * cout << "Activo eliminado;";
     * // mostrar (usando un activoTemp)
     */
}

void Cliente::modificarActivo() {
    cout << "$$$$$$$$$$$$$$$$$$$$      Modificar Activo      $$$$$$$$$$$$$$$$$$$$\n" << endl;
    /*
     * // Lista de activos
     * string id;
     * cout << "Ingresar ID del activo a modificar: ";
     * cin >> id;
     * cout << "$$$$$$$$$$$$$$$$$$$$     Modificando Activo       $$$$$$$$$$$$$$$$$$$$\n" << endl;
     * cout << "Ingresar descripción nueva: ";
     * // Buscar, modificar y mostrar
     */
}

void Cliente::rentarActivo() {
    bool regresarMenu = false;
    while (true) {
        cout << "$$$$$$$$$$$$$$$$$$$$     Catálogo de Activos     $$$$$$$$$$$$$$$$$$$$\n" << endl;
        /*
         * Lista de activos disponibles para rentar
         *
         */
        cout << "$$$$$$$$$$$$$$$$$$$$   1. Rentar Activo        $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   2. Regresar al menú     $$$$$$$$$$$$$$$$$$$$" << endl;

        int opcion;
        cout << "Ingresar opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: {
                cout << "$$$$$$$$$$$$$$$$$$$$     Renta de Activo     $$$$$$$$$$$$$$$$$$$$\n" << endl;

                string id;
                cout << "Ingresar id del activo a rentar: ";
                cin >> id;

                /*
                 * Mostrar info del activo a rentar
                 */

                int diasRenta;
                cout << "Ingresar dias por rentar: ";
                cin >> diasRenta;

                /*
                 * Verificar que los dias a rentar no excendan el maximo
                 */

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

void Cliente::activosRentados() {
    bool regresarMenu = false;
    while (true) {
        cout << "$$$$$$$$$$$$$$$$$$$$     Activos rentados     $$$$$$$$$$$$$$$$$$$$\n" << endl;
        /*
         * Lista de activos rentados
         *
         */
        cout << "$$$$$$$$$$$$$$$$$$$$   1. Devolver Activo      $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$   2. Regresar al menú     $$$$$$$$$$$$$$$$$$$$" << endl;

        int opcion;
        cout << "Ingresar opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: {
                cout << "$$$$$$$$$$$$$$$$$$$$     Devolución de Activo     $$$$$$$$$$$$$$$$$$$$\n" << endl;

                string id;
                cout << "Ingresar id del activo a devolver: ";
                cin >> id;
                //verificar que el id exista
                cout << "Activo devuelto exitosamente!\n" << endl;
                /*
                 * Mostrar info del activo a rentar
                 */
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

void Cliente::misActivosRentados() {
    bool regresarMenu = false;
    cout << "$$$$$$$$$$$$$$$$$$$$     Mis Activos rentados     $$$$$$$$$$$$$$$$$$$$\n" << endl;
    /*
     * Lista de activos rentados
     */
    while (true) {
        int opcion;
        cout << "Ingresar 1 para regresar al menú: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
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

std::string Cliente::generarAlfanumerico() {
    string id = "";
    //srand(time(nullptr));
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

