//
// Created by herberthreyes on 8/12/24.
//
#include "../../includes/matrizDispersa/MatrizDispersa.h"
#include "../../includes/Administrador.h"

MatrizDispersa::MatrizDispersa() {
    this->cabezaHorizontal = nullptr;
    this->cabezaVertical = nullptr;
}

MatrizDispersa::~MatrizDispersa() {
};

Nodo *MatrizDispersa::getCabezaHorizontal(std::string departamento) {
    if (estaVacia()) {
        return nullptr;
    }

    Nodo *aux = this->cabezaHorizontal;
    while (aux != nullptr) {
        if (aux->getUsuario()->getDepartamento() == departamento) {
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

Nodo *MatrizDispersa::getCabezaVertical(std::string empresa) {
    if (estaVacia()) {
        return nullptr;
    }

    Nodo *aux = this->cabezaVertical;
    while (aux != nullptr) {
        if (aux->getUsuario()->getEmpresa() == empresa) {
            return aux;
        }
        aux = aux->getAbajo();
    }
    return nullptr;
}

Nodo *MatrizDispersa::setCabezaHorizontal(std::string departamento) {
    Usuario *cabecera = new Usuario();
    cabecera->setDepartamento(departamento);
    Nodo *nuevaCabezaHorizontal = new Nodo(cabecera);

    if (this->cabezaHorizontal == nullptr) {
        this->cabezaHorizontal = nuevaCabezaHorizontal;
        return nuevaCabezaHorizontal;
    }

    Nodo *aux = this->cabezaHorizontal;
    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }

    aux->setSiguiente(nuevaCabezaHorizontal);
    nuevaCabezaHorizontal->setAnterior(aux);
    return nuevaCabezaHorizontal;
}

Nodo *MatrizDispersa::setCabezaVertical(std::string empresa) {
    Usuario *cabecera = new Usuario();
    cabecera->setEmpresa(empresa);
    Nodo *nuevaCabezaVertical = new Nodo(cabecera);

    if (this->cabezaVertical == nullptr) {
        this->cabezaVertical = nuevaCabezaVertical;
        return nuevaCabezaVertical;
    }

    Nodo *aux = this->cabezaVertical;
    while (aux->getAbajo() != nullptr) {
        aux = aux->getAbajo();
    }

    aux->setAbajo(nuevaCabezaVertical);
    nuevaCabezaVertical->setArriba(aux);
    return nuevaCabezaVertical;
}

Nodo *MatrizDispersa::buscarCabezaHorizontal(Nodo *usuario) {
    Nodo *aux = usuario;
    while (aux->getArriba() != nullptr) {
        aux = aux->getArriba();
    }
    return aux;
}

Nodo *MatrizDispersa::buscarCabezaVertical(Nodo *usuario) {
    Nodo *aux = usuario;
    while (aux->getAnterior() != nullptr) {
        aux = aux->getAnterior();
    }
    return aux;
}

Nodo *MatrizDispersa::buscarUsuario(Usuario *usuario) {

    Nodo *cabeceraVertical = getCabezaVertical(usuario->getEmpresa());

    if(cabeceraVertical != nullptr) {
        Nodo *auxUsuario = cabeceraVertical->getSiguiente();
        while (auxUsuario != nullptr) {
            Nodo *cabeceraHorizontal = buscarCabezaHorizontal(auxUsuario);
            if (cabeceraHorizontal->getUsuario()->getDepartamento() == usuario->getDepartamento()) {
                //para atras si no es el mismo usuario
                Nodo *auxUsuarioAtras = auxUsuario;
                while (auxUsuarioAtras != nullptr) {
                    if(auxUsuarioAtras->getUsuario()->getUsername() == usuario->getUsername()) {
                        return auxUsuario;
                    }
                    auxUsuarioAtras = auxUsuarioAtras->getAtras();
                }
                return nullptr;
            }
            if (!masDerecha(cabeceraHorizontal, cabeceraVertical)) {
                return nullptr;
            }
            auxUsuario = auxUsuario->getSiguiente();
        }
    }
    return nullptr;
}


bool MatrizDispersa::estaVacia() {
    return this->cabezaHorizontal == nullptr && this->cabezaVertical == nullptr;
}

bool MatrizDispersa::masAbajo(Nodo *cabeceraVertical, Nodo *empresa) {
    Nodo *auxCabezaVertical = cabeceraVertical;
    while (auxCabezaVertical != nullptr) {
        if (auxCabezaVertical == empresa) {
            return true;
        }
        auxCabezaVertical = auxCabezaVertical->getAbajo();
    }
    return false;
}

bool MatrizDispersa::masDerecha(Nodo *cabeceraHorizontal, Nodo *departamento) {
    Nodo *auxCabezaHorizontal = cabeceraHorizontal;
    while (auxCabezaHorizontal != nullptr) {
        if (auxCabezaHorizontal == departamento) {
            return true;
        }
        auxCabezaHorizontal = auxCabezaHorizontal->getSiguiente();
    }
    return false;
}


void MatrizDispersa::insertarUsuario(Usuario *usuario) {
    Nodo *departamento = nullptr;
    Nodo *empresa = nullptr;
    Nodo *usuarioNuevo = new Nodo(usuario);

    if (estaVacia()) {
        departamento = setCabezaHorizontal(usuario->getDepartamento());
        empresa = setCabezaVertical(usuario->getEmpresa());
        insertarUsuarioAlFinal(usuarioNuevo, departamento, empresa);
        return;
    }

    departamento = getCabezaHorizontal(usuario->getDepartamento());
    empresa = getCabezaVertical(usuario->getEmpresa());

    if (departamento == nullptr && empresa == nullptr) {
        departamento = setCabezaHorizontal(usuario->getDepartamento());
        empresa = setCabezaVertical(usuario->getEmpresa());
        insertarUsuarioAlFinal(usuarioNuevo, departamento, empresa);
        return;
    }

    if (departamento == nullptr) {
        departamento = setCabezaHorizontal(usuario->getDepartamento());
        insertarUsuarioAlFinal(usuarioNuevo, departamento, empresa);
        return;
    }

    if (empresa == nullptr) {
        empresa = setCabezaVertical(usuario->getEmpresa());
        insertarUsuarioAlFinal(usuarioNuevo, departamento, empresa);
        return;
    }

    //las cabeceras ya existen
    Nodo *auxUsuario = empresa->getSiguiente();
    while (auxUsuario != nullptr) {
        Nodo *cabeceraHorizontal = buscarCabezaHorizontal(auxUsuario);
        if (cabeceraHorizontal == departamento) {
            Administrador *administrador = new Administrador();
            insertarUsuarioAtrasAdelante(usuarioNuevo, auxUsuario, administrador->insertarAtras(auxUsuario->getUsuario()->getUsername()));
            return;
        }
        if(!masDerecha(cabeceraHorizontal, departamento)) {
            break;
        }
        auxUsuario = auxUsuario->getSiguiente();
    }

    Nodo *auxUsuarioDepartamento = departamento->getAbajo();
    Nodo *usuarioCabeceraVertical;
    bool abajo = false;

    while (auxUsuarioDepartamento != nullptr) {
        usuarioCabeceraVertical = buscarCabezaVertical(auxUsuarioDepartamento);
        abajo = masAbajo(usuarioCabeceraVertical, empresa);
        if(!abajo) {
            break;
        }
        auxUsuarioDepartamento = auxUsuarioDepartamento->getAbajo();
    }
    if(abajo) {
        insertarUsuarioAlFinalHorizontal(usuarioNuevo, departamento);
    } else {
        insertarUsuarioEnMedioHorizontal(usuarioNuevo, auxUsuarioDepartamento->getArriba(), auxUsuarioDepartamento);
    }

    Nodo *auxUsuarioEmpresa = empresa->getSiguiente();
    Nodo *usuarioCabeceraHorizontal;
    bool derecha = false;

    while (auxUsuarioEmpresa != nullptr) {
        usuarioCabeceraHorizontal = buscarCabezaHorizontal(auxUsuarioEmpresa);
        derecha = masDerecha(usuarioCabeceraHorizontal, departamento);
        if(!derecha) {
            break;
        }
        auxUsuarioEmpresa = auxUsuarioEmpresa->getSiguiente();
    }
    if(derecha) {
        insertarUsuarioAlFinalVertical(usuarioNuevo, empresa);
    } else {
        insertarUsuarioEnMedioVertical(usuarioNuevo, auxUsuarioEmpresa, auxUsuarioEmpresa->getAnterior());
    }

}

void MatrizDispersa::insertarUsuarioAtrasAdelante(Nodo *usuarioNuevo, Nodo *usuarioActual, bool insertarAtras) {
    if (insertarAtras) {
        usuarioActual->setAtras(usuarioNuevo);
        usuarioNuevo->setAdelante(usuarioActual);
        return;
    }

    usuarioNuevo->setAtras(usuarioActual);

    if (usuarioActual->getSiguiente() != nullptr) {
        usuarioNuevo->setSiguiente(usuarioActual->getSiguiente());
        usuarioActual->getSiguiente()->setAnterior(usuarioNuevo);
    }

    if (usuarioActual->getAnterior() != nullptr) {
        usuarioNuevo->setAnterior(usuarioActual->getAnterior());
        usuarioActual->getAnterior()->setSiguiente(usuarioNuevo);
    }

    if (usuarioActual->getArriba() != nullptr) {
        usuarioNuevo->setArriba(usuarioActual->getArriba());
        usuarioActual->getArriba()->setAbajo(usuarioNuevo);
    }

    if (usuarioActual->getAbajo() != nullptr) {
        usuarioNuevo->setAbajo(usuarioActual->getAbajo());
        usuarioActual->getAbajo()->setArriba(usuarioNuevo);
    }

    usuarioActual->setAdelante(usuarioNuevo);
    usuarioActual->setSiguiente(nullptr);
    usuarioActual->setAnterior(nullptr);
    usuarioActual->setArriba(nullptr);
    usuarioActual->setAbajo(nullptr);
}

void MatrizDispersa::insertarUsuarioEnMedioHorizontal(Nodo *usuario, Nodo *arriba, Nodo *abajo) {
    usuario->setArriba(arriba);
    usuario->setAbajo(abajo);
    abajo->setArriba(usuario);
    arriba->setAbajo(usuario);
}

void MatrizDispersa::insertarUsuarioEnMedioVertical(Nodo *usuario, Nodo *siguiente, Nodo *anterior) {
    usuario->setSiguiente(siguiente);
    siguiente->setAnterior(usuario);
    anterior->setSiguiente(usuario);
    usuario->setAnterior(anterior);
}


void MatrizDispersa::insertarUsuarioAlFinal(Nodo *usuarioNuevo, Nodo *cabeceraHorizontal, Nodo *cabeceraVertical) {
    insertarUsuarioAlFinalHorizontal(usuarioNuevo, cabeceraHorizontal);
    insertarUsuarioAlFinalVertical(usuarioNuevo, cabeceraVertical);
}

void MatrizDispersa::insertarUsuarioAlFinalHorizontal(Nodo *usuarioNuevo, Nodo *cabeceraHorizontal) {

    Nodo *auxHorizontal = cabeceraHorizontal;

    while (auxHorizontal->getAbajo() != nullptr) {
        auxHorizontal = auxHorizontal->getAbajo();
    }

    auxHorizontal->setAbajo(usuarioNuevo);
    usuarioNuevo->setArriba(auxHorizontal);
}

void MatrizDispersa::insertarUsuarioAlFinalVertical(Nodo *usuarioNuevo, Nodo *cabeceraVertical) {
    Nodo *auxVertical = cabeceraVertical;

    while (auxVertical->getSiguiente() != nullptr) {
        auxVertical = auxVertical->getSiguiente();
    }

    auxVertical->setSiguiente(usuarioNuevo);
    usuarioNuevo->setAnterior(auxVertical);
}
