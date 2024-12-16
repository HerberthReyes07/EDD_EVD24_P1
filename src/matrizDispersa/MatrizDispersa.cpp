//
// Created by herberthreyes on 8/12/24.
//
#include "../../includes/matrizDispersa/MatrizDispersa.h"
#include "../../includes/Administrador.h"

//int cont;

MatrizDispersa::MatrizDispersa() {
    cont = 0;
    this->cabezaHorizontal = nullptr;
    this->cabezaVertical = nullptr;
}

MatrizDispersa::~MatrizDispersa() {
};

int MatrizDispersa::getCont() {
    return this->cont;
}

void MatrizDispersa::setCont(int cont) {
    this->cont = cont;
}

NodoMD *MatrizDispersa::getCH() {
    return this->cabezaHorizontal;
}

NodoMD *MatrizDispersa::getCV() {
    return this->cabezaVertical;
}

NodoMD *MatrizDispersa::getCabezaHorizontal(std::string departamento) {
    if (estaVacia()) {
        return nullptr;
    }

    NodoMD *aux = this->cabezaHorizontal;
    while (aux != nullptr) {
        if (aux->getUsuario()->getDepartamento() == departamento) {
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

NodoMD *MatrizDispersa::getCabezaVertical(std::string empresa) {
    if (estaVacia()) {
        return nullptr;
    }

    NodoMD *aux = this->cabezaVertical;
    while (aux != nullptr) {
        if (aux->getUsuario()->getEmpresa() == empresa) {
            return aux;
        }
        aux = aux->getAbajo();
    }
    return nullptr;
}

NodoMD *MatrizDispersa::setCabezaHorizontal(std::string departamento) {
    Usuario *cabecera = new Usuario();
    cabecera->setDepartamento(departamento);
    NodoMD *nuevaCabezaHorizontal = new NodoMD(cabecera);
    cont ++;
    nuevaCabezaHorizontal->setIdNodo(cont);

    if (this->cabezaHorizontal == nullptr) {

        nuevaCabezaHorizontal->setGrupoVertical(2);
        //nuevaCabezaHorizontal->setIdNodo(1);
        this->cabezaHorizontal = nuevaCabezaHorizontal;
        return nuevaCabezaHorizontal;
    }

    NodoMD *aux = this->cabezaHorizontal;
    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }

    aux->setSiguiente(nuevaCabezaHorizontal);
    nuevaCabezaHorizontal->setAnterior(aux);
    nuevaCabezaHorizontal->setGrupoVertical(aux->getGrupoVertical() + 1);
    return nuevaCabezaHorizontal;
}

NodoMD *MatrizDispersa::setCabezaVertical(std::string empresa) {
    Usuario *cabecera = new Usuario();
    cabecera->setEmpresa(empresa);
    NodoMD *nuevaCabezaVertical = new NodoMD(cabecera);
    cont++;
    nuevaCabezaVertical->setIdNodo(cont);
    nuevaCabezaVertical->setGrupoVertical(1);

    if (this->cabezaVertical == nullptr) {

        //nuevaCabezaVertical->setIdNodo(2);
        this->cabezaVertical = nuevaCabezaVertical;
        return nuevaCabezaVertical;
    }

    NodoMD *aux = this->cabezaVertical;
    while (aux->getAbajo() != nullptr) {
        aux = aux->getAbajo();
    }

    aux->setAbajo(nuevaCabezaVertical);
    nuevaCabezaVertical->setArriba(aux);
    return nuevaCabezaVertical;
}

NodoMD *MatrizDispersa::buscarCabezaHorizontal(NodoMD *usuario) {
    NodoMD *aux = usuario;
    while (aux->getArriba() != nullptr) {
        aux = aux->getArriba();
    }
    return aux;
}

NodoMD *MatrizDispersa::buscarCabezaVertical(NodoMD *usuario) {
    NodoMD *aux = usuario;
    while (aux->getAnterior() != nullptr) {
        aux = aux->getAnterior();
    }
    return aux;
}

NodoMD *MatrizDispersa::buscarUsuario(Usuario *usuario) {

    NodoMD *cabeceraVertical = getCabezaVertical(usuario->getEmpresa());
    NodoMD *auxCabeceraHorizontal = getCabezaHorizontal(usuario->getDepartamento());

    if(cabeceraVertical != nullptr && auxCabeceraHorizontal != nullptr) {
        NodoMD *auxUsuario = cabeceraVertical->getSiguiente();
        while (auxUsuario != nullptr) {
            NodoMD *cabeceraHorizontal = buscarCabezaHorizontal(auxUsuario);
            if (cabeceraHorizontal->getUsuario()->getDepartamento() == usuario->getDepartamento()) {
                //para atras si no es el mismo usuario
                NodoMD *auxUsuarioAtras = auxUsuario;
                while (auxUsuarioAtras != nullptr) {
                    if(auxUsuarioAtras->getUsuario()->getUsername() == usuario->getUsername()) {
                        return auxUsuarioAtras;
                    }
                    auxUsuarioAtras = auxUsuarioAtras->getAtras();
                }
                return nullptr;
            }
            /*if (!masDerecha(cabeceraHorizontal, auxCabeceraHorizontal)) {
                return nullptr;
            }*/
            auxUsuario = auxUsuario->getSiguiente();
        }
    }
    return nullptr;
}

bool MatrizDispersa::estaVacia() {
    return this->cabezaHorizontal == nullptr && this->cabezaVertical == nullptr;
}

bool MatrizDispersa::masAbajo(NodoMD *cabeceraVertical, NodoMD *empresa) {
    NodoMD *auxCabezaVertical = cabeceraVertical;
    while (auxCabezaVertical != nullptr) {
        if (auxCabezaVertical == empresa) {
            return true;
        }
        auxCabezaVertical = auxCabezaVertical->getAbajo();
    }
    return false;
}

bool MatrizDispersa::masDerecha(NodoMD *cabeceraHorizontal, NodoMD *departamento) {
    NodoMD *auxCabezaHorizontal = cabeceraHorizontal;
    while (auxCabezaHorizontal != nullptr) {
        if (auxCabezaHorizontal == departamento) {
            return true;
        }
        auxCabezaHorizontal = auxCabezaHorizontal->getSiguiente();
    }
    return false;
}

void MatrizDispersa::insertarUsuario(Usuario *usuario) {
    NodoMD *departamento = nullptr;
    NodoMD *empresa = nullptr;
    NodoMD *usuarioNuevo = new NodoMD(usuario);
    cont++;
    usuarioNuevo->setIdNodo(cont);

    if (estaVacia()) {
        //cont = 0;
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
    usuarioNuevo->setGrupoVertical(departamento->getGrupoVertical());

    NodoMD *auxUsuario = empresa->getSiguiente();
    while (auxUsuario != nullptr) {
        NodoMD *cabeceraHorizontal = buscarCabezaHorizontal(auxUsuario);
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

    NodoMD *auxUsuarioDepartamento = departamento->getAbajo();
    NodoMD *usuarioCabeceraVertical;
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

    NodoMD *auxUsuarioEmpresa = empresa->getSiguiente();
    NodoMD *usuarioCabeceraHorizontal;
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

void MatrizDispersa::insertarUsuarioAtrasAdelante(NodoMD *usuarioNuevo, NodoMD *usuarioActual, bool insertarAtras) {
    if (insertarAtras) {
        usuarioActual->setAtras(usuarioNuevo);
        usuarioNuevo->setAdelante(usuarioActual);
        //usuarioNuevo->setIdNodo(usuarioActual->getIdNodo());
        return;
    }

    usuarioNuevo->setAtras(usuarioActual);
    /*cont++;
    usuarioNuevo->setIdNodo(cont);*/
    //usuarioNuevo->setGrupoVertical(usuarioActual->getGrupoVertical());

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

void MatrizDispersa::insertarUsuarioEnMedioHorizontal(NodoMD *usuario, NodoMD *arriba, NodoMD *abajo) {
    usuario->setArriba(arriba);
    usuario->setAbajo(abajo);
    abajo->setArriba(usuario);
    arriba->setAbajo(usuario);
}

void MatrizDispersa::insertarUsuarioEnMedioVertical(NodoMD *usuario, NodoMD *siguiente, NodoMD *anterior) {
    usuario->setSiguiente(siguiente);
    siguiente->setAnterior(usuario);
    anterior->setSiguiente(usuario);
    usuario->setAnterior(anterior);
}


void MatrizDispersa::insertarUsuarioAlFinal(NodoMD *usuarioNuevo, NodoMD *cabeceraHorizontal, NodoMD *cabeceraVertical) {
    /*cont++;
    usuarioNuevo->setIdNodo(cont);*/
    usuarioNuevo->setGrupoVertical(cabeceraHorizontal->getGrupoVertical());
    insertarUsuarioAlFinalHorizontal(usuarioNuevo, cabeceraHorizontal);
    insertarUsuarioAlFinalVertical(usuarioNuevo, cabeceraVertical);
}

void MatrizDispersa::insertarUsuarioAlFinalHorizontal(NodoMD *usuarioNuevo, NodoMD *cabeceraHorizontal) {

    NodoMD *auxHorizontal = cabeceraHorizontal;

    while (auxHorizontal->getAbajo() != nullptr) {
        auxHorizontal = auxHorizontal->getAbajo();
    }

    auxHorizontal->setAbajo(usuarioNuevo);
    usuarioNuevo->setArriba(auxHorizontal);
}

void MatrizDispersa::insertarUsuarioAlFinalVertical(NodoMD *usuarioNuevo, NodoMD *cabeceraVertical) {
    NodoMD *auxVertical = cabeceraVertical;

    while (auxVertical->getSiguiente() != nullptr) {
        auxVertical = auxVertical->getSiguiente();
    }

    auxVertical->setSiguiente(usuarioNuevo);
    usuarioNuevo->setAnterior(auxVertical);
}
