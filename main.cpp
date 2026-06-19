#include "Poligono.h"
#include <iostream>
using namespace std;
int main()
{
    Punto *v0 = new Punto(0, 0);
    Punto *v1 = new Punto(0, 10);
    Punto *v2 = new Punto(10, 10);
    Punto *v3 = new Punto(10, 0);

    Poligono *cuadrado = new Poligono(4);
    cuadrado->agregarPunto(*v0);
    cuadrado->agregarPunto(*v1);
    cuadrado->agregarPunto(*v2);
    cuadrado->agregarPunto(*v3);

    std::cout << "Costo de triangulación del cuadrado: " << cuadrado->costoTriangulacion() << std::endl;

    delete v1;
    delete v2;
    delete v3;
    delete cuadrado;
    cuadrado = NULL;

    v0 = new Punto(0, 0);
    v1 = new Punto(1, 2);
    v2 = new Punto(3, 3);
    v3 = new Punto(5, 2);
    Punto *v4 = new Punto(4, 0);

    Poligono *pentagono = new Poligono(5);
    pentagono->agregarPunto(*v0);
    pentagono->agregarPunto(*v1);
    pentagono->agregarPunto(*v2);
    pentagono->agregarPunto(*v3);
    pentagono->agregarPunto(*v4);

    std::cout << "Costo de triangulación del pentágono: " << pentagono->costoTriangulacion() << std::endl;

    delete v0;
    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete pentagono;
    pentagono = NULL;

    v1 = new Punto(2, 1);
    v2 = new Punto(4, 1);
    v3 = new Punto(6, 0);
    v4 = new Punto(4, -2);
    Punto *v5 = new Punto(2, -2);

    Poligono *hexagono = new Poligono(6);
    hexagono->agregarPunto(*v0);
    hexagono->agregarPunto(*v1);
    hexagono->agregarPunto(*v2);
    hexagono->agregarPunto(*v3);
    hexagono->agregarPunto(*v4);
    hexagono->agregarPunto(*v5);

    std::cout << "Costo de triangulación del hexágono: " << hexagono->costoTriangulacion() << std::endl;

    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;
    delete hexagono;
    hexagono = NULL;

    v0 = new Punto(0, 10);
    v1 = new Punto(0, 20);
    v2 = new Punto(8, 26);
    v3 = new Punto(15, 26);
    v4 = new Punto(27, 21);
    v5 = new Punto(22, 12);
    Punto *v6 = new Punto(10, 0);
    Poligono *heptagono = new Poligono(7);
    heptagono->agregarPunto(*v0);
    heptagono->agregarPunto(*v1);
    heptagono->agregarPunto(*v2);
    heptagono->agregarPunto(*v3);
    heptagono->agregarPunto(*v4);
    heptagono->agregarPunto(*v5);
    heptagono->agregarPunto(*v6);
    std::cout << "Costo de triangulación del heptágono: " << heptagono->costoTriangulacion() << std::endl;
    delete v0;
    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;
    delete v6;
    delete heptagono;
    heptagono = NULL;

    v0 = new Punto(0, 0);
    v1 = new Punto(2, 1);
    v2 = new Punto(4, 2);
    v3 = new Punto(6, 1);
    v4 = new Punto(8, 0);
    v5 = new Punto(6, -2);
    v6 = new Punto(4, -3);
    Punto *v7 = new Punto(2, -2);

    Poligono *octogono = new Poligono(8);
    octogono->agregarPunto(*v0);
    octogono->agregarPunto(*v1);
    octogono->agregarPunto(*v2);
    octogono->agregarPunto(*v3);
    octogono->agregarPunto(*v4);
    octogono->agregarPunto(*v5);
    octogono->agregarPunto(*v6);
    octogono->agregarPunto(*v7);

    std::cout << "Costo de triangulación del octágono: " << octogono->costoTriangulacion() << std::endl;

    delete v0;
    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;
    delete v6;
    delete v7;
    v0 = NULL;
    v1 = NULL;
    v2 = NULL;
    v3 = NULL;
    v4 = NULL;
    v5 = NULL;
    v6 = NULL;
    v7 = NULL;

    delete octogono;
    octogono = NULL;

    return 0;
}
