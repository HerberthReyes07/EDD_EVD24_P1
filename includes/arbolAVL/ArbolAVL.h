//
// Created by herberthreyes on 13/12/24.
//

#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "NodoAVL.h"

class ArbolAVL {
private:
    NodoAVL *raiz;

    void insertar(NodoAVL *activo, NodoAVL * &raiz);

    void eliminar(std::string idActivo, NodoAVL * &raiz);

    Activo *buscar(std::string idActivo, NodoAVL * &raiz);

    void recorrer(NodoAVL * &raiz);

    void generarGrafico(NodoAVL * &raiz, std::string &grafico);

    int alturaMaxNodo(NodoAVL *nodo);

    int factorEquilibrio(NodoAVL *nodo);

    bool esHoja(NodoAVL *nodo);

    NodoAVL *masDerecha(NodoAVL *&nodo);

    void rotacionSI(NodoAVL *&nodo);

    void rotacionSD(NodoAVL *&nodo);

    void rotacionID(NodoAVL *&nodo);

    void rotacionDI(NodoAVL *&nodo);

public:
    ArbolAVL();

    ~ArbolAVL();

    NodoAVL *&getRaiz();

    void setRaiz(NodoAVL *raiz);

    void insertar(Activo *activo);

    void eliminar(std::string idActivo);

    Activo *buscar(std::string idActivo);

    void recorrer();

    std::string generarGrafico();
};
#endif //ARBOLAVL_H
