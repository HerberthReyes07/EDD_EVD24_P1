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

Administrador::Administrador(MatrizDispersa *matriz, ListaCircularDoble *listaCircularDoble) {
    this->matriz = matriz;
    this->listaCircularDoble = listaCircularDoble;
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
                reporteTransacciones(listaCircularDoble, "Historial de transacciones",
                                     "../reporteTransacciones/transacciones.svg");
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
                int orden;
                bool opcionValida = false;
                string nombreOrden;

                while (true) {
                    cout << "\n$$$$$$$$$$$$   1. Ordenar Ascendentemente        $$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$   2. Ordenar Descendentemente       $$$$$$$$$$$$\n" << endl;

                    try {
                        cout << "Opcion: ";
                        cin >> orden;
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
                    switch (orden) {
                        case 1: {
                            nombreOrden = "ascendentemente";
                            opcionValida = true;
                            break;
                        }
                        case 2: {
                            nombreOrden = "descendentemente";
                            opcionValida = true;
                            break;
                        }
                        default: {
                            cout << "Error!. Por favor ingrese una opción válida\n" << endl;
                            break;
                        }
                    }
                    if (opcionValida) {
                        break;
                    }
                }
                ordenarTransacciones(nombreOrden, orden);
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
    cout << "\n$$$$$$$$$$$$$$$$$$$$      Registrar Usuario        $$$$$$$$$$$$$$$$$$$$\n" << endl;

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
            ArbolAVL *activos = new ArbolAVL();
            usuario->setActivos(activos);
            matriz->insertarUsuario(usuario);
            cout << "El usuario ha sido registrado exitosamente!\n" << endl;
            break;
        }
    }
}

void Administrador::reporteMatrizDispersa() {
    Usuario *admin = new Usuario();
    admin->setUsersname("Administrador");
    NodoMD *nodoAdmin = new NodoMD(admin);
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
        NodoMD *auxAdmin = nodoAdmin;
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
}

void Administrador::reporteActivosDisponiblesDepartamento() {
    cout << "\n$$$$$$$$$$$$$$$$$$$$      Reporte Activos Disponibles de un Departamento    $$$$$$$$$$$$$$$$$$$$" <<
            endl;
    cout << "$$$$$$$$$$$$$$$$$$$$      Departamentos        $$$$$$$$$$$$$$$$$$$$\n" << endl;

    NodoMD *aux = matriz->getCH();
    while (aux != nullptr) {
        cout << aux->getUsuario()->getDepartamento() << ";" << endl;
        aux = aux->getSiguiente();
    }
    cout << endl;

    string departamento;
    cout << "Ingresar departamento: ";
    getline(cin, departamento);
    NodoMD *nodoDepartamento = matriz->getCabezaHorizontal(departamento);

    if (nodoDepartamento == nullptr) {
        cout << "Departamento inexistente" << endl;
        return;
    }

    NodoMD *usuario = nodoDepartamento->getAbajo();
    string grafico = "digraph G {\n fontcolor=black;\nlabel=\"Activos disponibles " + departamento +
                     " \";\nlabelloc=\"t\";\n";
    while (usuario != nullptr) {
        NodoMD *usuarioAtras = usuario;
        while (usuarioAtras != nullptr) {
            grafico += "n" + to_string(usuarioAtras->getIdNodo()) + "[label=\"" + usuarioAtras->getUsuario()->
                    getUsername() + "\" shape=\"box\"];\n";
            grafico += "n" + to_string(usuarioAtras->getIdNodo()) + "->n" + usuarioAtras->getUsuario()->getActivos()->
                    getRaiz()->getActivo()->getId() + ";\n";
            grafico += usuarioAtras->getUsuario()->getActivos()->generarGrafico();
            usuarioAtras = usuarioAtras->getAtras();
        }
        usuario = usuario->getAbajo();
    }
    grafico += "\n}";
    //cout << grafico << endl;
    graficar("../reporteActivosDisponiblesDepartamento/activos_" + departamento + ".svg", grafico);
}

void Administrador::reporteActivosDisponiblesEmpresa() {
    cout << "\n$$$$$$$$$$$$$$$$$$$$      Reporte Activos Disponibles de una Empresa        $$$$$$$$$$$$$$$$$$$$" <<
            endl;
    cout << "$$$$$$$$$$$$$$$$$$$$      Empresas       $$$$$$$$$$$$$$$$$$$$\n" << endl;

    NodoMD *aux = matriz->getCV();
    while (aux != nullptr) {
        cout << aux->getUsuario()->getEmpresa() << ";" << endl;
        aux = aux->getAbajo();
    }
    cout << endl;

    string empresa;
    cout << "Ingresar empresa: ";
    getline(cin, empresa);
    NodoMD *nodoEmpresa = matriz->getCabezaVertical(empresa);

    if (nodoEmpresa == nullptr) {
        cout << "Empresa inexistente" << endl;
        return;
    }

    NodoMD *usuario = nodoEmpresa->getSiguiente();
    string grafico = "digraph G {\nfontcolor=black;\nlabel=\"Activos disponibles " + empresa +
                     " \";\nlabelloc=\"t\";\n";
    while (usuario != nullptr) {
        NodoMD *usuarioAtras = usuario;
        while (usuarioAtras != nullptr) {
            grafico += "n" + to_string(usuarioAtras->getIdNodo()) + "[label=\"" + usuarioAtras->getUsuario()->
                    getUsername() + "\" shape=\"box\"];\n";
            grafico += "n" + to_string(usuarioAtras->getIdNodo()) + "->n" + usuarioAtras->getUsuario()->getActivos()->
                    getRaiz()->getActivo()->getId() + ";\n";
            grafico += usuarioAtras->getUsuario()->getActivos()->generarGrafico();
            usuarioAtras = usuarioAtras->getAtras();
        }
        usuario = usuario->getSiguiente();
    }
    grafico += "\n}";
    //cout << grafico << endl;
    graficar("../reporteActivosDisponiblesEmpresa/activos_" + empresa + ".svg", grafico);
}

void Administrador::reporteTransacciones(ListaCircularDoble *lcde, std::string titulo, std::string path) {
    string config =
            "bgcolor=\"#F5F5F5\";fontcolor=black;\nlabel=\"" + titulo +
            "\";\nlabelloc=\"t\";\nnodesep=0.5;\nnode [fontsize = 5 shape=box style=filled fillcolor=\"#004488\" fontcolor=\"#F5F5F5\" color=transparent];\nedge [fontcolor=white color=\"#ff5722\"];\n";

    string defNodo;
    string relNodo;
    string encuadre = "{ rank=same; ";

    NodoLCDE *aux = lcde->getCabeza();

    int id = 1;
    while (true) {
        string nodoActual = "n" + to_string(id);
        defNodo += nodoActual + "[label=\"id = " + aux->getTransaccion()->getActivo()->getId()
                + "\\nTipo = " + aux->getTransaccion()->getTipo()
                + "\\nUsuario = " + aux->getTransaccion()->getUsuario()->getUsername()
                + "\\nActivo = " + aux->getTransaccion()->getActivo()->getNombre()
                + "\\nTiempo renta = " + to_string(aux->getTransaccion()->getTiempoRenta())
                + "\\nFecha = " + aux->getTransaccion()->getFecha() + "\"];\n";

        if (aux->getSiguiente() != nullptr && aux != lcde->getCola()) {
            relNodo += nodoActual + "->n" + to_string((id + 1)) + ";\n";
        }
        if (aux->getAnterior() != nullptr && aux != lcde->getCabeza()) {
            relNodo += nodoActual + "->n" + to_string((id - 1)) + ";\n";
        }
        encuadre += nodoActual + "; ";
        id++;
        aux = aux->getSiguiente();
        if (aux == lcde->getCabeza() || aux == nullptr) {
            break;
        }
    }
    relNodo += "n" + to_string(id - 1) + "->n1[tailport=n headport=n];\n";
    relNodo += "n1->n" + to_string(id - 1) + "[tailport=s headport=s];\n";
    encuadre += "}\n";

    string grafico = "digraph G {\n" + config + defNodo + relNodo + encuadre + "}";
    //cout << grafico;
    //graficar("../reporteTransacciones/" + nombreArchivo + ".svg", grafico);
    graficar(path, grafico);
}

void Administrador::reporteActivosUsuario() {
    cout << "\n$$$$$$$$$$$$$$$$$$$$        Reporte Activos de un Usuario        $$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$       Usuarios         $$$$$$$$$$$$$$$$$$$$$\n" << endl;
    verUsuarios();
    cout << endl;

    Usuario *usuario = new Usuario();

    string username;
    cout << "Ingresar Usuario: ";
    getline(cin, username);
    usuario->setUsersname(username);

    string departamento;
    cout << "Ingresar Departamento: ";
    getline(cin, departamento);
    usuario->setDepartamento(departamento);

    string empresa;
    cout << "Ingresar Empresa: ";
    getline(cin, empresa);
    usuario->setEmpresa(empresa);

    NodoMD *nodoUsuario = matriz->buscarUsuario(usuario);
    if (nodoUsuario == nullptr) {
        cout << "No se encontro el usuario!. Porfavor intentelo denuevo\n" << endl;
    } else {
        string grafico = "digraph G {\nfontcolor=black;\nlabel=\"Activos " + username + " \";\nlabelloc=\"t\";\n";
        grafico += "n" + to_string(nodoUsuario->getIdNodo()) + "[label=\"" + nodoUsuario->getUsuario()->getUsername() +
                "\" shape=\"box\"];\n";
        grafico += "n" + to_string(nodoUsuario->getIdNodo()) + "->n" + nodoUsuario->getUsuario()->getActivos()->
                getRaiz()->getActivo()->getId() + ";\n";
        grafico += nodoUsuario->getUsuario()->getActivos()->generarGrafico();
        grafico += "\n}";
        //cout << grafico << endl;
        graficar("../reporteActivosUsuario/activos_" + username + ".svg", grafico);
    }
}

void Administrador::verUsuarios() {
    NodoMD *nodoV = matriz->getCV();

    while (nodoV != nullptr) {
        NodoMD *nodoU = nodoV->getSiguiente();
        while (nodoU != nullptr) {
            NodoMD *nodoUA = nodoU;
            while (nodoUA != nullptr) {
                cout << "Usuario = " + nodoUA->getUsuario()->getUsername() + "; "
                        + "Departamento = " + nodoUA->getUsuario()->getDepartamento() + "; "
                        + "Empresa = " + nodoUA->getUsuario()->getEmpresa() + ";\n";
                nodoUA = nodoUA->getAtras();
            }
            nodoU = nodoU->getSiguiente();
        }
        nodoV = nodoV->getAbajo();
    }
}

void Administrador::activosRentadosUsuario() {
    cout << "\n$$$$$$$$$$$$$$$$$$$$        Reporte Activos Rentados por un Usuario        $$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$       Usuarios        $$$$$$$$$$$$$$$$$$$$\n" << endl;
    verUsuarios();
    cout << endl;

    Usuario *usuario = new Usuario();

    string username;
    cout << "Ingresar Usuario: ";
    getline(cin, username);
    usuario->setUsersname(username);

    string departamento;
    cout << "Ingresar Departamento: ";
    getline(cin, departamento);
    usuario->setDepartamento(departamento);

    string empresa;
    cout << "Ingresar Empresa: ";
    getline(cin, empresa);
    usuario->setEmpresa(empresa);

    NodoMD *nodoUsuario = matriz->buscarUsuario(usuario);
    if (nodoUsuario == nullptr) {
        cout << "No se encontro el usuario!. Porfavor intentelo denuevo\n" << endl;
    } else {
        ListaCircularDoble *auxLcde = new ListaCircularDoble();
        NodoLCDE *transActual = listaCircularDoble->getCabeza();
        if (transActual == nullptr) {
            return;
        }
        while (true) {
            if (transActual->getTransaccion()->getUsuario() == nodoUsuario->getUsuario()
                && transActual->getTransaccion()->getTipo() == "Renta") {
                /*NodoLCDE *transSiguiente = transActual->getSiguiente();
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
                }*/
                //if (enRenta) {
                auxLcde->agregarTransaccion(transActual->getTransaccion());
                //}
            }
            transActual = transActual->getSiguiente();
            if (transActual == listaCircularDoble->getCabeza()) {
                break;
            }
        }
        reporteTransacciones(auxLcde, "Activos rentados " + nodoUsuario->getUsuario()->getUsername(),
                             "../reporteActivosRentadosUsuario/activos_rentados_" + nodoUsuario->getUsuario()->
                             getUsername() + ".svg");
    }
}

void Administrador::ordenarTransacciones(std::string nombreOrden, int orden) {
    ListaCircularDoble *lcde = new ListaCircularDoble();
    lcde->agregarTransaccion(listaCircularDoble->getCabeza()->getTransaccion());
    NodoLCDE *aux = listaCircularDoble->getCabeza()->getSiguiente();

    while (true) {
        if (aux == listaCircularDoble->getCabeza()) {
            break;
        }
        lcde->agregarTransaccion(aux->getTransaccion());
        aux = aux->getSiguiente();
    }

    bool cambiado;
    do {
        cambiado = false;
        NodoLCDE *actual = lcde->getCabeza();
        do {
            NodoLCDE *siguiente = actual->getSiguiente();
            // < descendentemente // > ascendentemente
            if ((actual->getTransaccion()->getId().compare(siguiente->getTransaccion()->getId()) > 0 && orden == 1)
                || (actual->getTransaccion()->getId().compare(siguiente->getTransaccion()->getId()) < 0 && orden ==
                    2)) {
                // Intercambio de datos (solo datos, no nodos completos)
                Transaccion *auxTrans = actual->getTransaccion();
                actual->setTransaccion(siguiente->getTransaccion());
                siguiente->setTransaccion(auxTrans);
                cambiado = true;
            }
            actual = siguiente;
        } while (actual->getSiguiente() != lcde->getCabeza()); // Recorrer toda la lista circular
    } while (cambiado);
    reporteTransacciones(lcde, "Historial de transacciones ordenadas " + nombreOrden,
                         "../reporteTransacciones/transacciones_ordenadas_" + nombreOrden + ".svg");
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
        cout << "Se ha graficado correctamente!" << endl;
    } catch (const exception &e) {
        cerr << "Error al generar la imagen para el archivo aux_grafico.dot: " << e.what() << endl;
    }
}
