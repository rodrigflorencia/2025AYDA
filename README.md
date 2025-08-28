# Proyecto Grafos 

Este proyecto implementa estructuras de datos de grafos y algoritmos relacionados, desarrollado como parte de la materia Análisis y Diseño de Algoritmos II. Incluye múltiples implementaciones de grafos y algoritmos de recorrido y búsqueda.

## Características

- Múltiples implementaciones de grafos:
  - Lista de adyacencia
  - Matriz de adyacencia
  - Grafos con punteros
  - Grafos rotulados
- Algoritmos de recorrido:
  - Búsqueda en profundidad (DFS)
  - Clasificación de arcos (TREE, BACK, CROSS, FORWARD)
  - Componentes conexas
  - Algoritmo de Floyd-Warshall para caminos mínimos
  - Algoritmo de Prim para árbol de expansión mínima

## Estructura del Proyecto

```
Grafo/
├── include/               # Archivos de encabezado
│   ├── Grafo.hpp         # Interfaz base de grafo
│   ├── Grafo.cpp         # Implementación base
│   ├── GrafoLista.cpp    # Implementación con lista de adyacencia
│   ├── GrafoMatriz.cpp   # Implementación con matriz de adyacencia
│   ├── GrafoPuntero.hpp  # Interfaz para implementación con punteros
│   ├── GrafoRotulado.hpp # Interfaz para grafos con etiquetas en vértices y aristas con estructuras de stl
│   ├── dfs.hpp           # Algoritmos de búsqueda en profundidad
│   └── redSocial.hpp     # Ejemplo de aplicación: red social
├── main.cpp              # Programa principal con ejemplos

```

## Compilación y Ejecución

### Requisitos

- Compilador C++ compatible con C++11 o superior

### Compilación manual

```bash
g++ -std=c++11 -Iinclude/ main.cpp -o grafo
```

### Ejecución

```bash
./grafo
```
### Pruebas

https://replit.com/@rodrigflorencia/2025AYDA?v=1

## Documentación de Clases

### Clase Grafo

Clase base que define la interfaz común para todas las implementaciones de grafos.

#### Métodos principales:
- `addVertice(V v)`: Añade un vértice al grafo
- `addArco(V origen, V destino)`: Añade un arco entre dos vértices
- `hayArco(V origen, V destino)`: Verifica si existe un arco
- `getVertices()`: Devuelve el conjunto de vértices
- `getAdyacentes(V v)`: Devuelve los vértices adyacentes a v

### Clase GrafoRotulado

Extiende la funcionalidad básica del grafo añadiendo etiquetas a los vértices y pesos a los arcos.

#### Métodos adicionales:
- `addArco(V origen, V destino, C peso)`: Añade un arco con peso
- `getPeso(V origen, V destino)`: Obtiene el peso de un arco

## Algoritmos Implementados

### Búsqueda en Profundidad (DFS)

```cpp
// Ejemplo de uso
template <class V> 
list<V> dfsForest(const Grafo<V> &g) {
    unordered_map<V, bool> visitados;
    list<V> orden;
    // Implementación...
}
```

### Floyd-Warshall (Caminos mínimos)

```cpp
template <class V, class C> 
map<V, map<V, C>> floydWarshall(const Grafo<V, C> &g) {
    // Implementación...
}
```

### Prim (Árbol de expansión mínima)

```cpp
template <class V, class C> 
MST<V,C> prim(const Grafo<V,C> &g) {
    // Implementación...
}
```

## Ejemplo de Uso

```cpp
#include "include/mapa/Grafo.hpp"
#include "include/dfs.hpp"

int main() {
    // Crear un grafo no dirigido
    GrafoLista<string> g(false);

    // Añadir vértices
    g.addVertice("A");
    g.addVertice("B");
    g.addVertice("C");

    // Añadir arcos
    g.addArco("A", "B");
    g.addArco("B", "C");

    // Realizar DFS
    list<...> orden = dfsForest(g);

    // Imprimir orden de visita
    for (const V v : orden) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
```
