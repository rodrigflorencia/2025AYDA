#include "Poligono.h"
#include <cassert>

#define MAX 9999

double costoTriangulacion (Poligono * p) {
  int n = p->getTotalVertices();
    assert(n > 3 && p->esConvexo() && p->sentidoAntihorario()); // solo aplica a polígonos convexos de 4 lados o más. 
  
    double ** c = new double*[n-3]; // matriz de costos
    
    for (int s = 4; s <=n; s++) // s es el tamaño del subproblema
    {
        c[s-4] = new double[n]; // resto para que la matriz arranque en 0. Crear la fila para guardar los subproblemas tamaño s
        for (int i=0; i< n; i++) // vértice de inicio
        {
            int ultimo = (s+i-1)%n;

            const Punto & pi = p->getVertice(i); // inicio
            const Punto & ps = p->getVertice(ultimo); // fin
            c[s-4][i] = MAX;

            for (int k=1; k<= s-2; k++) // k para probar cuerdas internas al polígono y obtener el mínimo
            {
                int x = (i+k)%n;
                const Punto & pk = p->getVertice(x); // obtener vértice intermedio a inicio vi y inicio+s, vs

                double c1 = (k+1>=4) ? c[k-3][i] : 0; // costo considerando que la cuerda del vértice vk crea un polígono con el vértice final(vs) del que ya hemos calculado la triangulación mínima
                double c2 = (s-k>=4) ? c[s-k-4][x] : 0; // costo considerando que la cuerda del vértice vk crea un polígono con el vértice inicial (vi) del que ya hemos calculado la triangulación mínima
                double d1 = (k!=1) ? pi.getDistancia(pk) : 0; // distancia de una cuerda intermedia que es lado de un subproblema previo y forma una cuerda con vi, o bien, esa cuerda (vk,vi ) no forma parte de ningún subproblema previo
                double d2 = (x != (ultimo-1) ) ? pk.getDistancia(ps) : 0; // distancia de una cuerda intermedia que es lado de un subproblema previo y forma una cuerda con vs, o bien, esa cuerda (vk,vs ) no forma parte de ningún subproblema previo
                double costo_k = c1 + c2 + d1 + d2;

                if (costo_k < c[s-4][i]) // triangulación menor. compara con los k's previos y se queda con el más chico
                {
                    c[s-4][i] = costo_k;
                }

            }

        }

    }
    double costo = c[n-4][0];
    
    for (int i=0;i<n-3;i++){
        delete[] c[i];
    }
    delete[] c;

    return costo;
}
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

    std::cout << "Costo de triangulación del cuadrado: " << costoTriangulacion(cuadrado) << std::endl;

    delete v0;
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

    std::cout << "Costo de triangulación del pentágono: " << costoTriangulacion(pentagono) << std::endl;

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

    std::cout << "Costo de triangulación del hexágono: " << costoTriangulacion(hexagono) << std::endl;
    delete v0;
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
    std::cout << "Costo de triangulación del heptágono: " << costoTriangulacion(heptagono) << std::endl;
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

    std::cout << "Costo de triangulación del octágono: " << costoTriangulacion(octogono) << std::endl;

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
