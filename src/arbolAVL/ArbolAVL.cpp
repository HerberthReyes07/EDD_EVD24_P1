#include "../../includes/arbolAVL/ArbolAVL.h"
#include <iostream>
using namespace std;
//
// Created by herberthreyes on 13/12/24.
//
ArbolAVL::ArbolAVL() {
    this->raiz = nullptr;
}

ArbolAVL::~ArbolAVL() {
}

NodoAVL *ArbolAVL::getRaiz() {
    return raiz;
}

void ArbolAVL::setRaiz(NodoAVL *raiz) {
    this->raiz = raiz;
}

void ArbolAVL::insertar(Activo *activo) {
    NodoAVL *nodo = new NodoAVL(activo);
    insertar(nodo, this->raiz);
}

void ArbolAVL::eliminar(std::string idActivo) {
    eliminar(idActivo, this->raiz);
}

void ArbolAVL::modificar(std::string idActivo, std::string nuevaDescripcion) {
    modificar(idActivo, nuevaDescripcion, this->raiz);
}

void ArbolAVL::recorrer() {
    recorrer(this->raiz);
}

void ArbolAVL::insertar(NodoAVL *activo, NodoAVL *&raiz) {

    if (raiz == nullptr) {
        raiz = activo;
        raiz->setFactorEquilibrio(factorEquilibrio(raiz));
        return;
    }

    if(activo->getActivo()->getId().compare(raiz->getActivo()->getId()) < 0) {
        insertar(activo, raiz->getIzquierda());
    } else {
        insertar(activo, raiz->getDerecha());
    }

    raiz->setFactorEquilibrio(factorEquilibrio(raiz));

    if(raiz->getFactorEquilibrio() < -1) {
        if(raiz->getIzquierda()->getFactorEquilibrio() > 0) {
            rotacionID(raiz);
            return;
        }
        rotacionSD(raiz);
        return;
    }

    if(raiz->getFactorEquilibrio() > 1) {
        if(raiz->getDerecha()->getFactorEquilibrio() < 0) {
            rotacionDI(raiz);
            return;
        }
        rotacionSI(raiz);
        return;
    }
}

void ArbolAVL::eliminar(std::string idActivo, NodoAVL *&raiz) {

    if (raiz == nullptr) {
        cout << "No se puede eliminar el activo con el id: " << idActivo << " ya que no se encontro. Por favor verifique el id ingresado" << endl;
        return;
    }

    if(idActivo == raiz->getActivo()->getId()) {

        if (esHoja(raiz)) {
            raiz = nullptr;
            return;
        }

        if (raiz->getIzquierda() == nullptr) {
            raiz = raiz->getDerecha();
            return;
        }

        if (raiz->getDerecha() == nullptr) {
            raiz = raiz->getIzquierda();
            return;
        }

        NodoAVL *aux = masDerecha(raiz->getIzquierda());
        raiz->setActivo(aux->getActivo());
        eliminar(aux->getActivo()->getId(), raiz->getIzquierda());
        idActivo = raiz->getActivo()->getId();
    }

    if(idActivo.compare(raiz->getActivo()->getId()) < 0) {
        eliminar(idActivo, raiz->getIzquierda());
    } else {
        eliminar(idActivo, raiz->getDerecha());
    }

    raiz->setFactorEquilibrio(factorEquilibrio(raiz));

    if(raiz->getFactorEquilibrio() < -1) {
        if(raiz->getIzquierda()->getFactorEquilibrio() > 0) {
            rotacionID(raiz);
            return;
        }
        rotacionSD(raiz);
        return;
    }

    if(raiz->getFactorEquilibrio() > 1) {
        if(raiz->getDerecha()->getFactorEquilibrio() < 0) {
            rotacionDI(raiz);
            return;
        }
        rotacionSI(raiz);
        return;
    }
}

void ArbolAVL::modificar(std::string idActivo, std::string nuevaDescripcion, NodoAVL *&raiz) {
    if (raiz != nullptr) {
        if(idActivo == raiz->getActivo()->getId()) {
            raiz->getActivo()->setDescripcion(nuevaDescripcion);
            return;
        } else if(idActivo.compare(raiz->getActivo()->getId()) < 0) {
            return modificar(idActivo, nuevaDescripcion, raiz->getIzquierda());
        } else {
            return modificar(idActivo, nuevaDescripcion, raiz->getDerecha());
        }
    } else {
        cout << "No se puede modificar el activo con el id: " << idActivo << " ya que no se encontro. Por favor verifique el id ingresado" << endl;
        return;
    }
}

void ArbolAVL::recorrer(NodoAVL *&raiz) {
    if (raiz == nullptr) {
        return;
    }
    cout << raiz->getActivo()->getId() << endl;
    recorrer(raiz->getIzquierda());
    recorrer(raiz->getDerecha());
}

void ArbolAVL::rotacionSD(NodoAVL *&nodo) {
    NodoAVL *aux = nodo->getIzquierda();

    nodo->setIzquierda(aux->getDerecha());
    aux->setDerecha(nodo);
    nodo = aux;

    nodo->setFactorEquilibrio(factorEquilibrio(nodo));
    nodo->getDerecha()->setFactorEquilibrio(factorEquilibrio(nodo->getDerecha()));

    if(nodo->getIzquierda() == nullptr) {
        return;
    }

    nodo->getIzquierda()->setFactorEquilibrio(factorEquilibrio(nodo->getIzquierda()));
}

void ArbolAVL::rotacionSI(NodoAVL *&nodo) {
    NodoAVL *aux = nodo->getDerecha();

    nodo->setDerecha(aux->getIzquierda());
    aux->setIzquierda(nodo);
    nodo = aux;

    nodo->setFactorEquilibrio(factorEquilibrio(nodo));
    nodo->getIzquierda()->setFactorEquilibrio(factorEquilibrio(nodo->getIzquierda()));

    if(nodo->getDerecha() == nullptr) {
        return;
    }

    nodo->getDerecha()->setFactorEquilibrio(factorEquilibrio(nodo->getDerecha()));
}

void ArbolAVL::rotacionID(NodoAVL *&nodo) {
    rotacionSI(nodo->getIzquierda());
    rotacionSD(nodo);
}

void ArbolAVL::rotacionDI(NodoAVL *&nodo) {
    rotacionSD(nodo->getDerecha());
    rotacionSI(nodo);
}

int ArbolAVL::alturaMaxNodo(NodoAVL *nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    int hIzq = alturaMaxNodo(nodo->getIzquierda());
    int hDer = alturaMaxNodo(nodo->getDerecha());
    return hIzq > hDer ? hIzq + 1 : hDer + 1;
}

int ArbolAVL::factorEquilibrio(NodoAVL *nodo) {
    return alturaMaxNodo(nodo->getDerecha()) - alturaMaxNodo(nodo->getIzquierda());
}

bool ArbolAVL::esHoja(NodoAVL *nodo) {
    if (nodo->getIzquierda() == nullptr && nodo->getDerecha() == nullptr) {
        return true;
    }
    return false;
}

NodoAVL *ArbolAVL::masDerecha(NodoAVL *&nodo) {
    if (nodo->getDerecha() == nullptr) {
        return nodo;
    }
    return masDerecha(nodo->getDerecha());
}



