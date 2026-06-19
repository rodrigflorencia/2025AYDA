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

double Poligono::costoTriangulacion() const
{
    assert(this->cantidad > 3 && this->esConvexo() && this->sentidoAntihorario());

    int nC = this->cantidad - 3;
    double **C = new double *[nC];

    for (int s = 4; s <= this->cantidad; s++)
    {
        C[s - 4] = new double[this->cantidad];
        for (int i = 0; i < this->cantidad; i++)
        {
            int ultimo = (s + i - 1) % this->cantidad;

            const Punto &pi = this->vertices[i];
            const Punto &ps = this->vertices[ultimo];
            c[s - 4][i] = MAX;

            for (int k = 1; k <= s - 2; k++)
            {
                int x = (i + k) % this->cantidad;
                const Punto &pk = this->vertices[x];

                double c1 = (k + 1 >= 4) ? C[k - 3][i] : 0;
                double c2 = (s - k >= 4) ? C[s - k - 4][x] : 0;
                double d1 = (k != 1) ? pi.getDistancia(pk) : 0;
                double d2 = (x != (ultimo - 1)) ? pk.getDistancia(ps) : 0;
                double costoK = c1 + c2 + d1 + d2;

                if (costoK < C[s - 4][i])
                    C[s - 4][i] = costoK;
            }
        }
    }
  
    double costo = C[nC - 1][0];

    liberarMemoria(C, nC);

    return costo;
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
