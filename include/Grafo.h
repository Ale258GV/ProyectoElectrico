#ifndef GRAFO_H
#define GRAFO_H
#include <fstream>
#include "Nodo.h"
#include "Arista.h"
#include <string>
#include <iostream>
using namespace std;

class Grafo
{
    public:
    Nodo **nodos;
    Arista **aristas;
    int tam;
    double **matriz;
    ifstream arch_ent;
    string cad;
    int contador = 0;

    Grafo(char *nomArch);
    int verTam();
    void generaGrafo(); /** llenar vertices y matriz adyacencia*/
    void muestraGrafo();
};

#endif // GRAFO_H
