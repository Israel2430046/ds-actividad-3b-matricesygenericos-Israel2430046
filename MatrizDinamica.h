#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include <iostream>

template <typename t>
class matrizdinamica {
private:
    t** datos;
    int filas;
    int columnas;

    t** crear(int f, int c) {
        t** m = new t*[f];
        for (int i = 0; i < f; i++) {
            m[i] = new t[c];
            for (int j = 0; j < c; j++)
                m[i][j] = t();
        }
        return m;
    }

    void liberar(t** m, int f) {
        for (int i = 0; i < f; i++)
            delete[] m[i];
        delete[] m;
    }

public:
    matrizdinamica(int f, int c) {
        filas = f;
        columnas = c;
        datos = crear(f, c);
    }

    void leer(const char* nombre) {
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++) {
                std::cout << nombre << "[" << i << "," << j << "]: ";
                std::cin >> datos[i][j];
            }
    }

    void mostrar() {
        for (int i = 0; i < filas; i++) {
            std::cout << "| ";
            for (int j = 0; j < columnas; j++)
                std::cout << datos[i][j] << " ";
            std::cout << "|\n";
        }
    }

    t& valor(int i, int j) {
        return datos[i][j];
    }

    int getfilas() { return filas; }
    int getcolumnas() { return columnas; }

    void redimensionar(int nf, int nc) {
        t** nueva = crear(nf, nc);
        int fmin = (nf < filas) ? nf : filas;
        int cmin = (nc < columnas) ? nc : columnas;
        for (int i = 0; i < fmin; i++)
            for (int j = 0; j < cmin; j++)
                nueva[i][j] = datos[i][j];
        liberar(datos, filas);
        datos = nueva;
        filas = nf;
        columnas = nc;
    }

    static matrizdinamica<t> multiplicar(matrizdinamica<t>& a, matrizdinamica<t>& b) {
        matrizdinamica<t> c(a.filas, b.columnas);
        for (int i = 0; i < a.filas; i++)
            for (int j = 0; j < b.columnas; j++)
                for (int k = 0; k < a.columnas; k++)
                    c.datos[i][j] += a.datos[i][k] * b.datos[k][j];
        return c;
    }

    void limpiar() {
        liberar(datos, filas);
        datos = nullptr;
        filas = 0;
        columnas = 0;
    }
};

#endif
