# Programación Dinámica

La programación dinámica resuelve problemas combinando soluciones parciales de subproblemas. Esta técnica se aplica cuando los subproblemas se superponen, es decir, cuando los subproblemas comparten subsubproblemas; a diferencia de
la técnica divide y conquista que divide el problema en subproblemas separados, resuelve los subproblemas de forma recursiva y luego combina sus soluciones para resolver el problema original. De hecho, la técnica programación dinámica es aplicada a situaciones de solapamiento de subproblemas, en cambio, un algoritmo de divide y conquista resuelve reiteradas veces los subsubproblemas que se repiten.

En general, la programación dinámica se aplica a problemas que requieren soluciones algoritmicas de gran costo computacional. Mediante esta técnica, la solución óptima a un problema puede ser definida mediante soluciones óptimas a subproblemas de menor tamaño.
En otras palabras, la técnica permite resolver problemas a partir de la combinación de la solución de subproblemas idénticos al original y que, en general, tienen una *sub-estructura óptima*. 

La programación dinámica utiliza un enfoque _botton-upp_ para obtener la solución: 

i. primero calcula la solución óptima de cada subproblema.

ii. utilizando dichas soluciones, encuentra soluciones a problemas de mayor tamaño.


Para evitar repetir calculo, usualmente se utiliza una matriz que se llena conforme las soluciones a los subproblemas son calculados. 
Antes de resolver un subproblema *Q*, se chequea en la matriz para ver si ya se resolvió. Si no se resolvió, se resuelve. Si ya está resuelto, se recupera la solución, evitando recalcular. Antes de devolver la solución de *Q*, ésta se guarda.


## Pasos para desarrollar un algoritmo basado en programación dinámica

1. Caracterizar la estructura de una solución óptima.
   
2. Definición de la solución optima. Definir el calculo de la solución óptima en función de valores de soluciones para subproblemas de tamaño menor.
   
3. Calcular el valor de la solución óptimal utilizando un enfoque descendente:
   
   - Determinar el conjunto de subproblemas distintos a resolver (tamaño de la tabla)
     
   - Identificar sub problemas con solución trivial.
     
   - Obtener los valores con un enfoque ascendente y almacenar los valores que vamos a calculando en la tabla.
     
   - En estapas posteriores se utilizarán los valores previamente calculados.
     
4. Construir solución óptima a partir de la información previamente calculada.

## Principales elementos de la programación dinámica

### Subestructura óptima

El primer paso para resolver un problema de optimización mediante programación dinámica es caracterizar la estructura de una solución óptima. 
Un problema presenta una subestructura óptima si una solución óptima al problema contiene soluciones óptimas a los subproblemas.

> *Principio de optimalidad de Bellman*: la solución óptima  cualquier instancia no trivial de un problema es una combinación de soluciones ótpimas de las sub-instancias

<!--
Se podría definir una serie de pasos para ayudar a descubrir la subestructura óptima: 
1. Una solución al problema consiste en hacer una elección, como elegir un índice en el cual dividir la cadena de la matriz. Hacer esta elección deja uno o más subproblemas por resolver.
2. Se supone que, para un problema determinado, tenemos "la opción" que conduce a una solución óptima. No se sabe aún cómo determinar esta elección. Simplemente asumimos que está.
3. Dada esta "opción", determinar qué subproblemas surgen y cómo caracterizar mejor el espacio de subproblemas resultante.
4. Mostrar que las soluciones a los subproblemas utilizadas dentro de una solución óptima al problema deben ser óptimas mediante el uso de una técnica de _cortar & pegar_. Para ello, supongamos que cada una de las soluciones de los subproblemas no es óptima; entonces tenemos que llegar a una contradicción.
En particular, al "cortar" la solución no óptima de cada subproblema y "pegar" la óptima, demuestra que puede obtener una mejor solución al problema original, contradiciendo así la suposición de que ya tenía una solución óptima. Si una solución óptima da lugar a más de un subproblema, normalmente son tan similares que se puede modificar el argumento de cortar y pegar para que uno se aplique a los demás con poco esfuerzo.
-->
### Subproblemas superpuestos 

El espacio de los subproblemas debe ser "pequeño" en el sentido de que un algoritmo recursivo para el problema resuelve los mismos subproblemas una y otra vez, en lugar de generar siempre nuevos subproblemas. Normalmente, el número total de subproblemas distintos es un polinomio en el tamaño de entrada. Cuando un algoritmo recursivo revisa el mismo problema repetidamente, decimos que el problema de optimización tiene subproblemas superpuestos.
El enfoque de divide y conquista genera nuevos problemas en cada paso. En cambio, los algoritmos de programación dinámica aprovechan esta superposición resolviendo cada subproblema una vez y luego almacenando la solución parcial en una tabla donde se puede consultar cuando sea necesario, utilizando un tiempo constante para buscar.

### Reconstrucción de la solución óptima 

Como cuestión práctica, a menudo almacenamos en una tabla separada la "elección" que se hizo en cada subproblema para no tener que reconstruir esta información a partir de la tabla de costos.

### Memorización 

Se mantiene una tabla con soluciones de subproblemas, donde cada entrada de la tabla almacena la solución de cada subproblema. Inicialmente, cada entrada de la tabla contiene un valor especial para indicar que el subproblema aún no se ha procesado. Cuando el subproblema se encuentra por primera vez, la solución se calcula y luego se almacena en la tabla.

## Triangulación minimal de polígonos convexos


Dados los vértices de un polígono convexo se trata de seleccionar un conjunto de cuerdas (líneas entre vértices no adyacentes) de modo que ningún par de cuerdas se cruce entre sí y que todo el polígono quede dividido en triángulos. Además, la longitud total de las cuerdas debe ser mínima (triangulación minimal).

Utilidad: se puede emplear para sombrear objetos tridimensionales en una imagen virtual (bidimensional).

// poner una imagen que sea mas distinta de la de lal lado

![Posibles triangulaciones para un polígono P](img/img1.png)

- Tenemos un polígono P definido como un conjunto de N vértices ordenados en sentido antihorario P = <v<sub>0</sub>, v<sub>1</sub>, \... , v<sub>n-1</sub>>

- En toda triangulación de un polígono de más de 3 vértices, cada par de vértices adyacentes es tocado al menos por una diagonal. Si v<sub>i</sub> y v<sub>j</sub> no son adyacentes, entonces el segmento v<sub>i</sub>; v<sub>i</sub> es una cuerda.
  
- Si v<sub>i</sub> y v<sub>j</sub> definen una diagonal (v<sub>i</sub>, v<sub>j</sub>) debe existir un v<sub>k</sub> / (v<sub>i</sub>,v<sub>k</sub>) y (v<sub>k</sub>,v<sub>j</sub>) son lados o diagonal (i, j, k < N && v<sub>i</sub>, v<sub>j</sub>, v<sub>k</sub> ∈ P)
  
- Si v<sub>i</sub> y v<sub>j</sub> son lados del poligono, la distancia es cero.
  
## Subestructura óptima

Sea S<sub>i,s</sub> el subproblema de tamaño s partiendo del vértice v<sub>i</sub>, es decir, el problema de la triangulación
minimal del polígono formado por los s vértices que comienzan en v<sub>i</sub> y siguen en el sentido de las agujas del reloj (v<sub>i</sub>, v<sub>i+1</sub>, \..., v<sub>i+s-1</sub>), contando con la cuerda (v<sub>i</sub>,v<sub>i</sub>).

![Polígono P con cuerda v6;v5](img/img2.png)

Ahora, para triangular el polígono S<sub>i,s</sub>, hay tres posibilidades: 

![Posibles cuerdas para P luego de añadir cuerda v6;v5](img/img3.png)

a) Tomar el vértice v<sub>i+1</sub> para formar un triángulo con las cuerdas (v<sub>i</sub>,v<sub>i+s-1</sub>) y (v<sub>i+1</sub>,v<sub>i+s-1</sub>) y con el tercer lado (v<sub>i</sub>,v<sub>i+1</sub>), y después resolver el subproblema S<sub>i+1,s-1</sub>. 

b) Tomar el vértice v<sub>i+s-2</sub> para formar un triángulo con las cuerdas (v<sub>i</sub>,v<sub>i+s-1</sub>) y (v<sub>i</sub>,v<sub>i+s-2</sub>) y con el tercer lado (v<sub>i+s-2</sub>,v<sub>i+s-1</sub>), y después resolver el subproblema S<sub>i,s-1</sub>. 

c) Para algún k entre 2 y s-3, tomar el vértice v<sub>i+k</sub> y formar un triángulo con lados (v<sub>i</sub>,v<sub>i+k</sub>), (v<sub>i+k</sub>,v<sub>i+s-1</sub>) y (v<sub>i</sub>,v<sub>i+s-1</sub>), y después resolver los subproblemas S<sub>i,k+1</sub>y S<sub>i+k,s-k</sub>.

Por tanto, si denotamos por C<sub>i,s</sub> el coste de la triangulación S<sub>i,s</sub>, se obtiene la siguiente formula: 

C<sub>i,s</sub>= min<sub>1≤k≤s−2</sub>C<sub>i,k+1</sub> +{ C<sub>i+k,s-k</sub> +D(v<sub>i</sub> ,v<sub>i+k</sub>) +D(v<sub>i+k</sub> ,v<sub>i+s-1</sub>)}
para 0≤i≤N-1, 4≤s≤N; 

donde: D(v<sub>p</sub>,v<sub>q</sub>) es la longitud de la cuerda entre los vértices v<sub>p</sub> y v<sub>q</sub>


si v<sub>p</sub> y v<sub>q</sub> no son vértices adyacentes en el polígono P; y D(v<sub>p</sub>,v<sub>q</sub>) es 0 si v<sub>p</sub> y v<sub>q</sub> son adyacentes. Además, C<sub>i,s</sub> = 0 para 0≤i≤N-1, 2≤s<4.

### Subproblemas superpuestos 

Los subproblemas se superponen porque el cálculo de la triangulación mínima de un subpolígono de v<sub>i</sub> a v<sub>j</sub> puede requerir resolver los mismos subproblemas múltiples veces.

### Reconstrucción de la solución óptima 

Utilizamos matrices para reconstruir la solución óptima.

## Seguimiento para el polígono dado (hasta s = 5, i =2)

![](img/img4.png)

![](img/img5.png)

![](img/img7.png)

![](img/img6.png)

Se recomienda continuar hasta s = 7

### Matriz final de costos

| |i=0|i=1|i=2|i=3|i=4|i=5|i=6|
|:---: |:---: |:---:|:---:|:---:|:---:|:---:|:---:|
|s=4|16.1555|16.1555|15.6525|15.6525|22.0907|22.0907|17.8885|
|s=5|37.5354|31.808|35.4515|37.7432|45.5001|39.9793|38.0872|
|s=6|53.34|55.2174|57.5422|59.6749|59.7783|59.7783|63.6122|
|s=7|75.4307|75.4307|75.4307|75.4307|75.4307|75.4307|75.4307|75.4307|


## Triangulación

Para cada posición (i,s) de la tabla se necesita almacenar, además del costo, el valor del índice k que produjo el mínimo.

Entonces la solución consta de las cuerdas (v<sub>i</sub>,v<sub>i+k</sub>) y (v<sub>i+k</sub>,v<sub>i+s-1</sub>) (a menos que una de ellas no sea cuerda, porque k=1 o k=s-2), más las cuerdas que generadas por las soluciones de S<sub>i,k+1</sub> y S<sub>i+k,s-k</sub>.

## Alternativas de implementación

1. Se puede utilizar una matriz de distancias D, en lugar de invocar al método getDistancia de la clase Punto.

Archivo Poligono.cpp

```cpp

double Poligono::costoTriangulacion() const
{

    double **D = new double *[this->cantidad];
    incializarDistancias(D, this->cantidad);

    double **C = new double *[this->cantidad - 4];

    for (int s = 4; s <= this->cantidad; s++)
    {
        C[s - 4] = new double[this->cantidad];
        for (int i = 0; i < this->cantidad; i++)
        {
            int ultimo = (s + i - 1) % this->cantidad;
            C[s - 4][i] = MAX;
            for (int k = 1; k <= s - 2; k++)
            {
                int x = (i + k) % this->cantidad;
                double c1 = (k + 1 >= 4) ? c[k - 3][i] : 0;
                double c2 = (s - k >= 4) ? c[s - k - 4][x] : 0;
                double d1 = D[i][x];
                double d2 = D[x][ultimo];
                double costoK = c1 + c2 + d1 + d2;
                if (costoK < C[s - 4][i])
                    C[s - 4][i] = costoK;
            }
        }
    }
    double costo = C[this->cantidad - 4][0];

    liberarMemoria(C,D,this->cantidad);

    return costo;
}

void Poligono::incializarDistancias(double ** D, int n) const
{
    for (int i = 0; i < n; i++)
    {
        D[i] = new double[n];
        const Punto &pi = this->vertices[i];
        
        // si vi, vj forman una arista, es decir, son consecutivos, tomamos la distancia como cero
        for (int j = 0; j < n; j++)
            D[i][j] = ((i == j) || (i + 1 == j) || (i == 0 && j == n - 1) || (j == 0 && i == n - 1))
                          ? 0
                          : pi.getDistancia(this->vertices[j]);
    }
}

void liberarMemoria(double ** C, double ** D, int n) const
{
    int i = 0;
    while (i < n - 3)
    {
        delete[] D[i];
        delete[] C[i];
        i++;
    }
    while (i < n)
    {
        delete[] D[i];
        i++;
    }

    delete[] C;
    delete[] D;
    C = NULL;
    D = NULL;
}
```
En Poligono .h, incluir el método que inicializa D como privado.

2. Se puede utilizar la matriz de costos de N * (N+1). Las filas menores a 4 deben tener 0:

Archivo Poligono.cpp

```cpp
double Poligono::costoTriangulacion() const{
    
    double ** C = new double*[this->cantidad+1];

    // Primeras tres filas de matriz de costos, con 0
    for (int s = 0; s < 4; s++)
    {
      C[s] = new double[this->cantidad];
      for (int i = 0; i < this->cantidad; i++)
        C[s][i] = 0;
    }

    // Soluciones parciales a sub problemas 
    for (int s = 4; s <= this->cantidad; s++)
    {
        C[s - 4] = new double[this->cantidad];
        for (int i = 0; i < this->cantidad; i++)
        {
            int ultimo = (s + i - 1) % this->cantidad;
            C[s][i] = MAX;

            for (int k = 1; k <= s - 2; k++)
            {
                int x = (i + k) % this->cantidad;
                double c1 = C[k + 1][i];
                double c2 = C[s - k ][x];
                double d1 = (k!=1) ? pi.getDistancia(pk) : 0;
                double d2 = (x != (ultimo-1) ) ? pk.getDistancia(ps) : 0;
                double costo_k = c1 + c2 + d1 + d2;
                if (costo_k < C[s][i])
                    C[s][i] = costo_k;
            }
        }
    }
    double costo = C[this->cantidad][0];

    liberarMemoria(C,D,this->cantidad);

    return costo;
}

void Poligono::liberarMemoria(double ** C,double ** D, int n) const
{
    for (int i=0;i<n;i++)
    {
        delete[] C[i];
        delete[] D[i];
    }
    delete[] C[n];
    delete[] C;
    delete[] D;
    C = NULL;
    D = NULL;
}
```

3. A continuación, se muestra una alternativa de implementación, utlizando matriz de distancias y matriz de costos con filas de problemas de tamaño menor a cuatro iniciadas en cero

Archivo Poligono.cpp

```cpp
double Poligono::costoTriangulacion() const
{
    assert(this->cantidad > 3 && this->esConvexo() && this->sentidoAntihorario());

    double ** C = new double*[this->cantidad+1];
    double ** D = new double *[this->cantidad];
    incializarDistancias(D, this->cantidad);

    for (int s = 0; s < 4; s++)
    {
      C[s] = new double[this->cantidad];
      for (int i = 0; i< this->cantidad; i++)
        C[s][i] = 0;
    }

    for (int s = 4; s <= this->cantidad; s++)
    {
        C[s] = new double[this->cantidad];
        for (int i=0; i< this->cantidad; i++)
        {
            int ultimo = (s+i-1)%this->cantidad;
            C[s][i] = MAX;

            for (int k=1; k<= s-2; k++)
            {
                int x = (i+k)%this->cantidad;
                double costoK = C[k+1][i] + C[s-k][x] + D[i][x] + D[x][ultimo];
                if (costoK < C[s][i])
                    C[s][i] = costoK;
            }
        }
    }

    double costo = C[this->cantidad][0];
    liberarMemoria(C,D);

    return costo;
}

```
## Para analizar

Puntos para tener en cuenta al elegir la implementación:

- El getDistancia tiene operaciones aritméticas complejas, como la raíz cuadrada y la potencia. Pueden no ser del orden constante. En ese caso sería mejor la matriz.
  
- Al tener la matriz, no tenemos el costo espacial de los objetos de la clase Punto, p<sub>i</sub>, p<sub>k</sub> y p<sub>s</sub>, pero caemos en un costo espacial de almacenamiento de la matriz.

Se recomienda incluir métricas para medir la cantidad de operaciones y los timepos de ejecución.
