#ifndef POLIGONO_H
#define POLIGONO_H
#include "Punto.h"
class Poligono
{
private:
    int N;
    Punto *vertices;
    int cantidad;
    double productoCruz(const Punto &A, const Punto &B, const Punto &C) const;
    bool esConvexo() const;
    bool sentidoAntihorario() const;
    void liberarMemoria(double **C, int n) const;

public:
    Poligono(int n);
    ~Poligono();
    void agregarPunto(const Punto &p);

    double costoTriangulacion() const;
    int getTotalVertices() const;
};
#endif // POLIGONO_H
