#include <iostream>
#include<string>
using namespace std;

int main() {
    int opcion;
    bool regresarMenu = false;

    //ver lo de cuando se ingresa una letra cuando se espera un int

    while (true) {
        cout << "$$$$$$$$$$$$$$$$$$$$  Renta de Activos  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 1. Iniciar sesión  $$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$ 2. Cerrar programa $$$$$$$$$$$$$$$$$$$$\n" << endl;

        cout << "Ingresar opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                /*cout << "$$$$$$$$$$$$$$$$$$$$ Renta de Activos $$$$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$      Login       $$$$$$$$$$$$$$$$$$$$\n" << endl;
                //Usuario usuario = new Usuario();
                //cin >> usuario.usuario; ...
                cout << "Ingresar Usuario: ";
                cout << "Ingresar Contraseña: ";
                cout << "Ingresar Departamento: ";
                cout << "Ingresar Empresa: ";*/

                //Usuario encontrado, sigue la ejecucion
                while (true) {
                    bool sesionCerrada = false;

                    cout << "$$$$$$$$$$$$$$$$$$$$     Renta de Activos       $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$       Usuario 123          $$$$$$$$$$$$$$$$$$$$" << endl;

                    //El usuario no es admin
                    cout << "$$$$$$$$$$$$$$$$$$$$   1. Agregar Activo        $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   2. Eliminar Activo       $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   3. Modificar Activo      $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   4. Rentar Activo         $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   5. Activos Rentados      $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   6. Mis Activos Rentados  $$$$$$$$$$$$$$$$$$$$" << endl;
                    cout << "$$$$$$$$$$$$$$$$$$$$   7. Cerrar Sesión         $$$$$$$$$$$$$$$$$$$$\n" << endl;

                    cout << "Ingresar opción: ";
                    cin >> opcion;

                    switch (opcion) {
                        case 1: {
                            cout << "$$$$$$$$$$$$$$$$$$$$      Agregar Activo        $$$$$$$$$$$$$$$$$$$$\n" << endl;
                            /*
                             * Activo activo = new activo();
                             * cout << "Ingresar nombre: ";
                             * cin >> activo.nombre;
                             * cout << "Ingresar descripción: ";
                             */
                            break;
                        }
                        case 2: {
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
                        }
                        case 3: {
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
                        }
                        case 4: {
                            while (true) {
                                cout << "$$$$$$$$$$$$$$$$$$$$     Catálogo de Activos     $$$$$$$$$$$$$$$$$$$$\n" <<
                                        endl;
                                /*
                                 * Lista de activos disponibles para rentar
                                 *
                                 */
                                cout << "$$$$$$$$$$$$$$$$$$$$   1. Rentar Activo        $$$$$$$$$$$$$$$$$$$$" << endl;
                                cout << "$$$$$$$$$$$$$$$$$$$$   2. Regresar al menú     $$$$$$$$$$$$$$$$$$$$" << endl;

                                cout << "Ingresar opción: ";
                                cin >> opcion;
                                cout << endl;

                                switch (opcion) {
                                    case 1: {
                                        cout << "$$$$$$$$$$$$$$$$$$$$     Renta de Activo     $$$$$$$$$$$$$$$$$$$$\n" <<
                                                endl;

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
                                    regresarMenu = false;
                                    break;
                                }
                            }
                            break;
                        }
                        case 5: {
                            while (true) {
                                cout << "$$$$$$$$$$$$$$$$$$$$     Activos rentados     $$$$$$$$$$$$$$$$$$$$\n" << endl;
                                /*
                                 * Lista de activos rentados
                                 *
                                 */
                                cout << "$$$$$$$$$$$$$$$$$$$$   1. Devolver Activo      $$$$$$$$$$$$$$$$$$$$" << endl;
                                cout << "$$$$$$$$$$$$$$$$$$$$   2. Regresar al menú     $$$$$$$$$$$$$$$$$$$$" << endl;

                                cout << "Ingresar opción: ";
                                cin >> opcion;
                                cout << endl;

                                switch (opcion) {
                                    case 1: {
                                        cout <<
                                                "$$$$$$$$$$$$$$$$$$$$     Devolución de Activo     $$$$$$$$$$$$$$$$$$$$\n"
                                                << endl;

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
                                    regresarMenu = false;
                                    break;
                                }
                            }
                            break;
                        }
                        case 6: {
                            cout << "$$$$$$$$$$$$$$$$$$$$     Mis Activos rentados     $$$$$$$$$$$$$$$$$$$$\n" << endl;
                            /*
                             * Lista de activos rentados
                             */
                            while (true) {
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
                                    regresarMenu = false;
                                    break;
                                }
                            }
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

                    //El usuario es admin
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   1. Registrar Usuario                                 $$$$$$$$$$$$$$$$$$$$"
                            << endl;
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   2. Reporte Matriz Dispersa                           $$$$$$$$$$$$$$$$$$$$"
                            << endl;
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   3. Reporte Activos Disponibles de un Departamento    $$$$$$$$$$$$$$$$$$$$"
                            << endl;
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   4. Reporte Activos Disponibles de una Empresa        $$$$$$$$$$$$$$$$$$$$"
                            << endl;
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   5. Reporte Transacciones                             $$$$$$$$$$$$$$$$$$$$"
                            << endl;
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   6. Reporte Activos de un Usuario                     $$$$$$$$$$$$$$$$$$$$"
                            << endl;
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   7. Activos Rentados por un Usuario                   $$$$$$$$$$$$$$$$$$$$"
                            << endl;
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   8. Ordenar Transacciones                             $$$$$$$$$$$$$$$$$$$$"
                            << endl;
                    cout <<
                            "$$$$$$$$$$$$$$$$$$$$   9. Cerrar sesión                                     $$$$$$$$$$$$$$$$$$$$\n"
                            << endl;

                    cout << "Ingresar opción: ";
                    cin >> opcion;

                    switch (opcion) {
                        case 1: {
                            cout << "$$$$$$$$$$$$$$$$$$$$      Registrar Usuario        $$$$$$$$$$$$$$$$$$$$\n" << endl;
                            /*//Usuario usuario = new Usuario();
                            //cin >> usuario.usuario; ...
                            cout << "Ingresar Usuario: ";
                            cout << "Ingresar Contraseña: ";
                            cout << "Ingresar Departamento: ";
                            cout << "Ingresar Empresa: ";*/
                            break;
                        }
                        case 2: {
                            break;
                        }
                        case 3: {
                            break;
                        }
                        case 4: {
                            break;
                        }
                        case 5: {
                            break;
                        }
                        case 6: {
                            break;
                        }
                        case 7: {
                            break;
                        }
                        case 8: {
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
                break;
            }
            case 2: {
                cout << "Opcion 2" << endl;
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
