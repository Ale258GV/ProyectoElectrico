#include "Grafo.h"
#include <fstream>  /**usar archivos*/
#include <stdlib.h> /**usar exit*/
#include <string>
#include <iostream>
#include "Nodo.h"
#include "Arista.h"
using namespace std;
Grafo::Grafo(string nomArch){
    string cad;
    ifstream arch_ent(nomArch); /**Archivo de texto, de donde se saca el grafo*/
    getline(arch_ent, cad);
    tam = stoi(cad); /**Cantidad de nodos*/ /**La funci�n stoi convierte un string a int, en este caso cad la primera l�nea en el txt, la cual es la cantidad de nodos*/

    nodos = new Nodo*[tam];
    for(int i=0; i<tam; i++){ /**Obtener los nodos*/
        getline(arch_ent, cad);
        nodos[i] = new Nodo(cad,0,false);
    }

    matriz = new double*[tam];
    for(int o = 0; o < tam; o++){ /**Generar matriz en ceros*/
        matriz[o] = new double[tam];
        for(int p = 0; p < tam; p++){
            matriz[o][p] = 0;
        }
    }

    aristas = new Arista*[tam];
    for(int o = 0; o < tam; o++){ /**Generar matriz en ceros*/
        aristas[o] = new Arista[tam];
        for(int p = 0; p < tam; p++){
            aristas[o][p] = 0;
        }
    }

    cout << endl << "Datos del Grafo" << endl;
    while(!arch_ent.eof()){ /**Obtener aristas*/
        getline(arch_ent, cad); /**Obtener linea del txt*/

        int a = cad.size(); /**Tama�o de la l�nea*/
        string nodo1, nodo2;
        int posEspacio, posEspacio2;

        /**Cambiar el caracter dentro del .find dependiendo del archivo de texto que se use*/
        posEspacio = cad.find('*'); /**Obtener 1er nodo*/
        nodo1 = cad.substr(0,posEspacio);
        cad.replace(0,posEspacio+1,"");

        posEspacio2 = cad.find('*'); /**Obtener 2do nodo*/
        nodo2 = cad.substr(0,posEspacio2);
        cad.replace(0,posEspacio2+1,"");

        double costo = stod(cad); /**Obtener costo/ /*La funci�n stod convierte un string a double*/

        int posNodo1, posNodo2=-1;

        /**Buscar posicion correspondiente al 1er y 2do Nodo*/
        for(int j = 0; j<tam; j++){
            if(nodos[j]->verUbicacion() == nodo1){
                posNodo1 = j;
            }
            if(nodos[j]->verUbicacion() == nodo2){
                posNodo2 = j;
            }
        }

        cout << nodo1 << "\t" << nodo2 << "\t" << costo << " -> Posicion donde almacenar costo: " << posNodo1 << ", " << posNodo2 << endl;
        matriz[posNodo1][posNodo2] = costo;
        matriz[posNodo2][posNodo1] = costo;
        aristas[posNodo1][posNodo2] = Arista(costo);
        aristas[posNodo2][posNodo1] = Arista(costo);
    }
}
void Grafo::muestraGrafo(){
    /**Imprimir Matriz de Adyacencia*/
    cout<< "\nMatriz de Adyacencia:" <<endl;
    for(int k = 0; k<tam; k++){
        for(int l = 0; l<tam; l++){
            cout << matriz[k][l] << "\t";
        }
        cout << endl;
    }
}
int Grafo::verTam(){
    return tam;
}

