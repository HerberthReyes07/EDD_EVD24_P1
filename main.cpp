#include <iostream>
#include "includes/Usuario.h"
#include "includes/Cliente.h"
#include "includes/Administrador.h"
#include "includes/listaCircularDoblementeEnlazada/ListaCircularDoble.h"
#include "includes/matrizDispersa/MatrizDispersa.h"

using namespace std;

int main() {
    srand(time(nullptr));
    int opcion;
    MatrizDispersa *matriz = new MatrizDispersa();
    ListaCircularDoble *listaCircularDoble = new ListaCircularDoble();
    /*Usuario *usuario1 = new Usuario("U1", "U1", "U1", "Guatemala", "Max");
    Usuario *usuario2 = new Usuario("U2", "U2", "U2", "Xela", "Max");
    Usuario *usuario6 = new Usuario("U6", "U6", "U6", "Alta Verapaz", "Cemaco");
    Usuario *usuario4 = new Usuario("U4", "U4", "U4", "Guatemala", "Cemaco");
    Usuario *usuario3 = new Usuario("U3", "U3", "U3", "Alta Verapaz", "Max");
    Usuario *usuario8 = new Usuario("U8", "U8", "U8", "Xela", "Campero");
    Usuario *usuario5 = new Usuario("U5", "U5", "U5", "Xela", "Cemaco");
    //Usuario *usuario51 = new Usuario("U51", "U51", "U51", "Xela", "Cemaco");

    matriz->insertarUsuario(usuario1);
    matriz->insertarUsuario(usuario2);
    matriz->insertarUsuario(usuario6);
    matriz->insertarUsuario(usuario4);
    matriz->insertarUsuario(usuario3);
    matriz->insertarUsuario(usuario8);
    matriz->insertarUsuario(usuario5);
    //matriz->insertarUsuario(usuario51);*/
    //Administrador *administrador = new Administrador();
    //Usuario *usuario = new Usuario();
    Cliente *auxCliente = new Cliente();

    Usuario *usuario1 = new Usuario("U1", "U1", "U1", "Guatemala", "Max");
    Usuario *usuario2 = new Usuario("U2", "U2", "U2", "Xela", "Max");
    Usuario *usuario3 = new Usuario("U3", "U3", "U3", "Alta Verapaz", "Max");
    Usuario *usuario4 = new Usuario("U4", "U4", "U4", "Guatemala", "Cemaco");

    Activo *activo1 = new Activo("1", "A1", "A1", 1, false);
    Activo *activo2 = new Activo("2", "A2", "A2", 2, false);
    Activo *activo3 = new Activo("3", "A3", "A3", 3, false);
    Activo *activo4 = new Activo("4", "A4", "A4", 4, false);

    Transaccion *transaccion1 = new Transaccion(auxCliente->generarAlfanumerico(), "Renta", 1, usuario1, activo1, "1");
    Transaccion *transaccion2 = new Transaccion(auxCliente->generarAlfanumerico(),"Renta", 2, usuario2, activo2, "2");
    Transaccion *transaccion3 = new Transaccion(auxCliente->generarAlfanumerico(),"Renta", 3, usuario3, activo3, "3");
    Transaccion *transaccion4 = new Transaccion(auxCliente->generarAlfanumerico(), "Renta", 4, usuario4, activo4, "4");

    listaCircularDoble->agregarTransaccion(transaccion2);
    listaCircularDoble->agregarTransaccion(transaccion1);
    listaCircularDoble->agregarTransaccion(transaccion4);
    listaCircularDoble->agregarTransaccion(transaccion3);

    /*Administrador *administrador = new Administrador(matriz, listaCircularDoble);
    administrador->menu();
    administrador->menu();
    administrador->reporteTransacciones(listaCircularDoble, "transacciones1", 0);*/
    //Cliente *cliente = new Cliente();
    //cout << cliente->generarAlfanumerico() << endl;

    while (true) {
        cout << "$$$$$$$$$$$$$$$$$$$$  Renta de Activos  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 1. Iniciar sesión  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 2. Cerrar programa $$$$$$$$$$$$$$$$$$$$\n" << endl;

        cout << "Ingresar opción: ";
        cin >> opcion;
        cin.ignore();

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
                            cout << "No se encontro el usuario!. Porfavor intentelo denuevo\n" << endl;
                            //break;
                        } else {
                            cout << endl;
                            Cliente *cliente = new Cliente(nodoUsuario, matriz);
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
