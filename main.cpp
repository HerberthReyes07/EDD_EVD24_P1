#include <iostream>
#include "includes/Usuario.h"
#include "includes/Cliente.h"
#include "includes/Administrador.h"

using namespace std;

int main() {
    int opcion;
    //ver lo de cuando se ingresa una letra cuando se espera un int

    while (true) {
        cout << "$$$$$$$$$$$$$$$$$$$$  Renta de Activos  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 1. Iniciar sesión  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 2. Cerrar programa $$$$$$$$$$$$$$$$$$$$\n" << endl;

        cout << "Ingresar opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "$$$$$$$$$$$$$$$$$$$$ Renta de Activos $$$$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$      Login       $$$$$$$$$$$$$$$$$$$$\n" << endl;

                Usuario *usuario = new Usuario();
                bool esAdmin = true;

                string username;
                cout << "Ingresar Usuario: ";
                cin >> username;
                usuario->setUsersname(username);

                string password;
                cout << "Ingresar Contraseña: ";
                cin >> password;
                usuario->setPassword(password);

                if (username != "admin" && password != "admin") {
                    esAdmin = false;
                    string departamento;
                    cout << "Ingresar Departamento: ";
                    cin >> departamento;
                    usuario->setDepartamento(departamento);

                    string empresa;
                    cout << "Ingresar Empresa: ";
                    cin >> empresa;
                    usuario->setEmpresa(empresa);
                }

                /*if (!esAdmin) {
                    //buscar usuario
                    //si no existe -> break;
                }*/

                //Usuario encontrado, sigue la ejecucion

                if (!esAdmin) {
                    //El usuario no es admin
                    Cliente *cliente = new Cliente(usuario);
                    cliente->menu();
                } else {
                    //El usuario es admin
                    Administrador *administrador = new Administrador(usuario);
                    administrador->menu();
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

    return 0;
}
