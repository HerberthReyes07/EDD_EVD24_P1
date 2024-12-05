#include <iostream>
using namespace std;

int main() {
    int opcion;
    while (true) {
        cout << "$$$$$$$$$$$$$$$$$$$$  Renta de Activos  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 1. Iniciar sesión  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 2. Cerrar programa $$$$$$$$$$$$$$$$$$$$\n" << endl;

        cout << "Ingresar opción: ";
        //int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                /*cout << "Opcion 1" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$ Renta de Activos $$$$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$      Login       $$$$$$$$$$$$$$$$$$$$\n" << endl;
                //Usuario usuario = new Usuario();
                //cin >> usuario.usuario; ...
                cout << "Ingresar Usuario: ";
                cout << "Ingresar Contraseña: ";
                cout << "Ingresar Departamento: ";
                cout << "Ingresar Empresa: ";*/

                //Coincide con un usuario y no es admin
                while (true) {
                    bool logoutFlag = false;
                    cout << "$$$$$$$$$$$$$$$$$$$$     Renta de Activos       $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$       Usuario 123          $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   1. Agregar Activo        $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   2. Eliminar Activo       $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   3. Modificar Activo      $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   4. Rentar Activo         $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   5. Activos Rentados      $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   6. Mis Activos Rentados  $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   7. Cerrar sesión         $$$$$$$$$$$$$$$$$$$$\n" << endl;

                    cout << "Ingresar opción: ";
                    cin >> opcion;

                    switch (opcion) {
                        case 1:
                            cout << "$$$$$$$$$$$$$$$$$$$$      Agregar Activo        $$$$$$$$$$$$$$$$$$$$\n" << endl;
                        /*
                         * Activo activo = new activo();
                         * cout << "Ingresar nombre: ";
                         * cin >> activo.nombre;
                         * cout << "Ingresar descripción: ";
                         */
                            break;
                        case 2:
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
                            break;
                        case 3:
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
                            break;
                        case 4:
                            cout << "Opcion 4" << endl;
                            break;
                        case 5:
                            cout << "Opcion 5" << endl;
                            break;
                        case 6:
                            cout << "Opcion 6" << endl;
                            break;
                        case 7:
                            cout << "Opcion 7" << endl;
                            logoutFlag = true;
                            break;
                        default:
                            cout << "Error!. Por favor ingrese una opción válida\n" << endl;
                            break;
                    }
                    if (logoutFlag) {
                        break;
                    }
                }
                break;
            case 2:
                cout << "Opcion 2" << endl;
                exit(0);
            default:
                cout << "Error!. Por favor ingrese una opción válida\n" << endl;
                break;
        }
    }

    return 0;
}
