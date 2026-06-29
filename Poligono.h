#ifndef POLIGONO_H
#define POLIGONO_H
#include "Punto.h"
class Poligono
{
private:
    int N;
    Punto *vertices;
    int cantidad;
 
public:
    Poligono(int n);
    ~Poligono();
    void agregarPunto(const Punto &p);
    bool esConvexo() const;
    bool sentidoAntihorario() const;
    int getTotalVertices() const;
    const Punto & getVertice(int i) const;
};
#endif // POLIGONO_H
