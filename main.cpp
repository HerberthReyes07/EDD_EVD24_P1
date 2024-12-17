#include <iostream>
#include "includes/Usuario.h"
#include "includes/Cliente.h"
#include "includes/Administrador.h"
#include "includes/arbolAVL/ArbolAVL.h"
#include "includes/listaCircularDoblementeEnlazada/ListaCircularDoble.h"
#include "includes/matrizDispersa/MatrizDispersa.h"
#include <limits>

using namespace std;

int main() {
    srand(time(nullptr));
    int opcion;
    MatrizDispersa *matriz = new MatrizDispersa();
    ListaCircularDoble *listaCircularDoble = new ListaCircularDoble();
    Cliente *auxCliente = new Cliente();

    /*Usuario *usuario1 = new Usuario("U1", "U1", "U1", "Xela", "Max");
    Activo *activo1 = new Activo(auxCliente->generarAlfanumerico(), "A11", "A11", 11, false);
    Activo *activo2 = new Activo(auxCliente->generarAlfanumerico(), "A21", "A21", 21, false);
    Activo *activo3 = new Activo(auxCliente->generarAlfanumerico(), "A31", "A31", 31, false);
    ArbolAVL *arbolAVL = new ArbolAVL();

    arbolAVL->insertar(activo1);
    arbolAVL->insertar(activo2);
    arbolAVL->insertar(activo3);
    usuario1->setActivos(arbolAVL);
    matriz->insertarUsuario(usuario1);

    Usuario *usuario2 = new Usuario("U2", "U2", "U2", "Guatemala", "Cemaco");
    Activo *activo12 = new Activo(auxCliente->generarAlfanumerico(), "A12", "A12", 12, false);
    Activo *activo14 = new Activo(auxCliente->generarAlfanumerico(), "A22", "A22", 22, false);
    Activo *activo11 = new Activo(auxCliente->generarAlfanumerico(), "A32", "A32", 32, false);
    ArbolAVL *arbolAVL2 = new ArbolAVL();

    arbolAVL2->insertar(activo12);
    arbolAVL2->insertar(activo14);
    arbolAVL2->insertar(activo11);
    usuario2->setActivos(arbolAVL2);
    matriz->insertarUsuario(usuario2);

    Usuario *usuario3 = new Usuario("U3", "U3", "U3", "Guatemala", "Max");
    Activo *activo10 = new Activo(auxCliente->generarAlfanumerico(), "A13", "A13", 13, false);
    Activo *activo5 = new Activo(auxCliente->generarAlfanumerico(), "A23", "A23", 23, false);
    Activo *activo4 = new Activo(auxCliente->generarAlfanumerico(), "A33", "A33", 33, false);
    ArbolAVL *arbolAVL3 = new ArbolAVL();

    arbolAVL3->insertar(activo10);
    arbolAVL3->insertar(activo5);
    arbolAVL3->insertar(activo4);
    usuario3->setActivos(arbolAVL3);
    matriz->insertarUsuario(usuario3);*/

    //Datos quemados
    Usuario* usuario1 = new Usuario("elian_estrada", "1234", "Elian Estrada", "guatemala", "igss");
    ArbolAVL* arbolAVL1 = new ArbolAVL();
    arbolAVL1->insertar(new Activo(auxCliente->generarAlfanumerico(), "madera", "madera para albañil", 20, false));
    arbolAVL1->insertar(new Activo(auxCliente->generarAlfanumerico(), "martillos", "martillos para madera", 10, false));
    arbolAVL1->insertar(new Activo(auxCliente->generarAlfanumerico(), "caladora", "caladora para cortar maderas prefabricadas", 15, false));
    arbolAVL1->insertar(new Activo(auxCliente->generarAlfanumerico(), "barreno", "barreno para concreto", 5, false));
    usuario1->setActivos(arbolAVL1);
    matriz->insertarUsuario(usuario1);

    Usuario* usuario6 = new Usuario("juanito", "4567", "Juan Perez", "jutiapa", "max");
    usuario6->setActivos(new ArbolAVL());
    matriz->insertarUsuario(usuario6);

    Usuario* usuario7 = new Usuario("pedrito", "48956", "Pedro Rodriguez", "jalapa", "usac");
    usuario7->setActivos(new ArbolAVL());
    matriz->insertarUsuario(usuario7);

    Usuario* usuario5 = new Usuario("mafer", "54312", "Maria Fernanda", "peten", "cinepolis");
    ArbolAVL* arbolAVL5 = new ArbolAVL();
    arbolAVL5->insertar(new Activo(auxCliente->generarAlfanumerico(), "audifonos", "audífonos para grabaciones de estudio", 10, false));
    arbolAVL5->insertar(new Activo(auxCliente->generarAlfanumerico(), "microfonos", "micrófonos de todo tipo", 8, false));
    arbolAVL5->insertar(new Activo(auxCliente->generarAlfanumerico(), "pedestales", "pedestales para micrófonos grandes y pequeños", 12, false));
    arbolAVL5->insertar(new Activo(auxCliente->generarAlfanumerico(), "atriles", "atriles para colocar hojas con gancho", 14, false));
    usuario5->setActivos(arbolAVL5);
    matriz->insertarUsuario(usuario5);

    Usuario* usuario8 = new Usuario("juanma", "32897", "Juan Manuel", "guatemala", "usac");
    usuario8->setActivos(new ArbolAVL());
    matriz->insertarUsuario(usuario8);

    Usuario* usuario2 = new Usuario("casimiro", "721896", "Carlos Perez", "guatemala", "max");
    ArbolAVL* arbolAVL2 = new ArbolAVL();
    arbolAVL2->insertar(new Activo(auxCliente->generarAlfanumerico(), "balanza", "balanza con maximo de 25kg", 15, false));
    arbolAVL2->insertar(new Activo(auxCliente->generarAlfanumerico(), "canastas", "canastas para frutas y verduras", 45, false));
    arbolAVL2->insertar(new Activo(auxCliente->generarAlfanumerico(), "linternas", "linternas para alumbrar cuartos oscuros", 10, false));
    arbolAVL2->insertar(new Activo(auxCliente->generarAlfanumerico(), "cargadores", "cargadores de telefonos tipo c", 5, false));
    arbolAVL2->insertar(new Activo(auxCliente->generarAlfanumerico(), "cables", "cables de todo tipo", 10, false));
    arbolAVL2->insertar(new Activo(auxCliente->generarAlfanumerico(), "lazos", "lazos para tender ropa", 20, false));
    usuario2->setActivos(arbolAVL2);
    matriz->insertarUsuario(usuario2);

    Usuario* usuario3 = new Usuario("fuego03", "891346", "Fernando Mendez", "jutiapa", "cinepolis");
    ArbolAVL* arbolAVL3 = new ArbolAVL();
    arbolAVL3->insertar(new Activo(auxCliente->generarAlfanumerico(), "termos", "pequeños termos para bebidas calientes", 10, false));
    arbolAVL3->insertar(new Activo(auxCliente->generarAlfanumerico(), "maletas", "maletas desde pequeñas a grandes", 15, false));
    arbolAVL3->insertar(new Activo(auxCliente->generarAlfanumerico(), "peliculas", "todo de películas de acción", 5, false));
    usuario3->setActivos(arbolAVL3);
    matriz->insertarUsuario(usuario3);

    Usuario* usuario9 = new Usuario("azurdia", "780145", "Alejandra Guzman", "jutiapa", "usac");
    usuario9->setActivos(new ArbolAVL());
    matriz->insertarUsuario(usuario9);

    Usuario* usuario4 = new Usuario("incrediboy", "201598", "Iraldo Martinez", "jutiapa", "max");
    ArbolAVL* arbolAVL4 = new ArbolAVL();
    arbolAVL4->insertar(new Activo(auxCliente->generarAlfanumerico(), "casets", "casets con música de todo tipo", 5, false));
    arbolAVL4->insertar(new Activo(auxCliente->generarAlfanumerico(), "pantallas", "pantallas para proyección", 10, false));
    arbolAVL4->insertar(new Activo(auxCliente->generarAlfanumerico(), "cañonera", "cañonera para proyección", 15, false));
    arbolAVL4->insertar(new Activo(auxCliente->generarAlfanumerico(), "toldo", "toldo para eventos al exterior", 5, false));
    usuario4->setActivos(arbolAVL4);
    matriz->insertarUsuario(usuario4);

    Usuario* usuario10 = new Usuario("alcachofa", "20435", "Antonio Lopez", "jalapa", "usac");
    usuario10->setActivos(new ArbolAVL());
    matriz->insertarUsuario(usuario10);

    while (true) {
        cout << "\n$$$$$$$$$$$$$$$$$$$$  Renta de Activos  $$$$$$$$$$$$$$$$$$$$\n" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 1. Iniciar sesión  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 2. Cerrar programa $$$$$$$$$$$$$$$$$$$$\n" << endl;

        try {
            cout << "Ingresar opción: ";
            cin >> opcion;
            if (cin.fail()) {
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
                while (true) {
                    cout << "\n$$$$$$$$$$$$$$$$$$$$ Renta de Activos $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$      Login       $$$$$$$$$$$$$$$$$$$$\n" << endl;

                    Usuario *usuario = new Usuario();

                    string username;
                    cout << "Ingresar Usuario: ";
                    getline(cin, username);
                    usuario->setUsersname(username);

                    string password;
                    cout << "Ingresar Contraseña: ";
                    getline(cin, password);
                    usuario->setPassword(password);

                    if (username != "admin" && password != "admin") {
                        //El usuario no es admin
                        string departamento;
                        cout << "Ingresar Departamento: ";
                        getline(cin, departamento);
                        usuario->setDepartamento(departamento);

                        string empresa;
                        cout << "Ingresar Empresa: ";
                        getline(cin, empresa);
                        usuario->setEmpresa(empresa);

                        //buscar usuario
                        NodoMD *nodoUsuario = matriz->buscarUsuario(usuario);
                        if (nodoUsuario == nullptr) {
                            cout << "\nNo se encontro el usuario!. Porfavor intentelo denuevo\n" << endl;
                        } else {
                            Cliente *cliente = new Cliente(nodoUsuario, matriz, listaCircularDoble);
                            cliente->menu();
                            break;
                        }
                    } else {
                        //El usuario es admin
                        cout << endl;
                        Administrador *administrador = new Administrador(matriz, listaCircularDoble);
                        administrador->menu();
                        break;
                    }
                }
                break;
            }
            case 2: {
                exit(0);
            }
            default: {
                cout << "Error!. Por favor ingrese una opción válida\n" << endl;
                break;
            }
        }
    }
}
