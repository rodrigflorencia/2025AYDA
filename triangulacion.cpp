#include "Poligono.h"
#include <cassert>

#define MAX 9999

double costoTriangulacion(Poligono * p) const {
  int n = p->etTotalVertices();
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
    double costo = c[p->n-4][0];
    
    for (int i=0;i<p->n-3;i++){
        delete c[i];
    }
    delete c;

    return costo;
}
