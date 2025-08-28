#include "include/puntero/GrafoLista.cpp"


/**
 * Pruebas de la implementación de grafo rotulado con punteros
 */
int main() {
  Grafo<char, char> g;

  g.addVertice('A');
  g.addVertice('B');
  g.addVertice('C');
  g.addVertice('D');

  g.addArco('A', 'B', '7');
  g.addArco('A', 'C', '5');

  cout << "\n\nGrafo rotulado implementado con punteros\n";

  cout << "Hay A-B? " << g.hayArco('A', 'B') << "\n";
  cout << "Hay C-B? " << g.hayArco('C', 'B') << "\n";
  cout << "Peso A-C = " << g.getPeso('A', 'C') << "\n";
  cout << "Peso A-D = " << g.getPeso('A', 'D') << "\n";
  g.imprimir();

  return 0;
}

