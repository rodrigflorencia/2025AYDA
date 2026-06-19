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
   
public:
    Poligono(int n);
    ~Poligono();
    void agregarPunto(const Punto &p);
    bool esConvexo() const;
    bool sentidoAntihorario() const;
    int getTotalVertices() const;
    const Punto & getPunt(int i) const;
};
#endif // POLIGONO_H
