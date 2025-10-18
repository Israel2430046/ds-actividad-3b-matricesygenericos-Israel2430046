#include <iostream>
#include "matrizdinamica.h"

int main() {
    std::cout << "--- sistema de analisis de transformaciones lineales ---\n";

    matrizdinamica<int> a(2, 3);
    std::cout << "matriz a (int):\n";
    a.leer("a");
    a.redimensionar(3, 3);
    std::cout << "\nmatriz a redimensionada:\n";
    a.mostrar();

    matrizdinamica<float> b(3, 2);
    b.valor(0,0)=1.5; b.valor(0,1)=0.5;
    b.valor(1,0)=2.0; b.valor(1,1)=1.0;
    b.valor(2,0)=1.0; b.valor(2,1)=2.5;

    matrizdinamica<float> af(a.getfilas(), a.getcolumnas());
    for (int i = 0; i < a.getfilas(); i++)
        for (int j = 0; j < a.getcolumnas(); j++)
            af.valor(i,j) = (float)a.valor(i,j);

    matrizdinamica<float> c = matrizdinamica<float>::multiplicar(af, b);

    std::cout << "\nmatriz c (resultado float):\n";
    c.mostrar();

    a.limpiar();
    b.limpiar();
    c.limpiar();
    af.limpiar();

    std::cout << "\nfin del programa.\n";
    return 0;
}
