#include "Poligono.h"
#include <iostream>
#include <cassert>
#define MAX 9999

Poligono::Poligono(int n)
{
    this->vertices = new Punto[n];
    this->cantidad = 0;
    this->N = n;
}

Poligono::~Poligono()
{
    delete[] this->vertices;
    this->cantidad = 0;
    this->N = 0;
}

int Poligono::getTotalVertices() const
{
    return this->N;
}

void Poligono::agregarPunto(const Punto &p)
{
    assert(this->cantidad <= this->N);
    this->vertices[this->cantidad] = p;
    this->cantidad++;
}

const Punto & getPunto (int i)
{
  assert(i<= (this->cantidad );
    return this->vertices[i];
}

bool Poligono::esConvexo() const
{
    if (this->cantidad < 4)
    {
        return true;
    }

    int i = 0;
    bool productoNegativo = false;

    while (!productoNegativo && i < this->cantidad)
    {
        double cruz = productoCruz(this->vertices[i], this->vertices[(i + 1) % this->cantidad], this->vertices[(i + 2) % this->cantidad]);
        if (cruz > 0)
        {
            productoNegativo = true;
        }
        i++;
    }

    return !productoNegativo;
}

double Poligono::productoCruz(const Punto &A, const Punto &B, const Punto &C) const
{
    double ABx = B.getX() - A.getX();
    double ABy = B.getY() - A.getY();
    double BCx = C.getX() - B.getX();
    double BCy = C.getY() - B.getY();
    return ABx * BCy - ABy * BCx;
}

bool Poligono::sentidoAntihorario() const
{
    double suma = 0.0;

    for (int i = 0; i < this->cantidad; ++i)
    {
        const Punto &actual = this->vertices[i];
        const Punto &siguiente = this->vertices[(i + 1) % this->cantidad];
        suma += (siguiente.getX() - actual.getX()) * (siguiente.getY() + actual.getY());
    }

    return suma > 0;
}

void Poligono::liberarMemoria(double **C, int n) const
{
    for (int i = 0; i < n; i++)
        delete [] C[i];
    delete [] C;
    C = NULL;
}
