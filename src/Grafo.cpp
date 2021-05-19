#include "Grafo.h"
#include <fstream>  /**usar archivos*/
#include <stdlib.h> /**usar exit*/
#include <string>
#include <iostream>
#include "Nodo.h"
#include "Arista.h"
using namespace std;

Grafo::Grafo(char *nomArch){
    ifstream arch_ent(nomArch); /**Archivo de texto, de donde se saca el grafo*/
    //arch.open(nomArch);
    if(arch_ent.fail()){
       cout << "Error al abrir el archivo del grafo !!!";
       exit(1);
    }
    getline(arch_ent, cad);
    tam = stoi(cad); /**Cantidad de nodos*/ /**La función stoi convierte un string a int, en este caso cad la primera línea en el txt, la cual es la cantidad de nodos*/
    //numNodos = atoi(cad.c_str());

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

    aristas = new Arista*[tam-1];

    while(!arch_ent.eof()){ /**Obtener aristas*/
        getline(arch_ent, cad); /**Obtener linea del txt*/

        int a = cad.size(); /**Tamaño de la línea*/
        string nodo1, nodo2;
        int posEspacio, posEspacio2;

        /**Cambiar el caracter dentro del .find dependiendo del archivo de texto que se use*/
        posEspacio = cad.find('*'); /**Obtener 1er nodo*/
        nodo1 = cad.substr(0,posEspacio);
        cad.replace(0,posEspacio+1,"");

        posEspacio2 = cad.find('*'); /**Obtener 2do nodo*/
        nodo2 = cad.substr(0,posEspacio2);
        cad.replace(0,posEspacio2+1,"");

        double costo = stod(cad); /**Obtener costo/ /*La función stod convierte un string a double*/

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

        cout<<""<<nodo1;
        cout<<" "<<nodo2;
        cout<<"      "<<costo<< " -> Posicion donde almacenar costo: "<< posNodo1<<", "<< posNodo2<<endl;
        matriz[posNodo1][posNodo2] = costo;
        matriz[posNodo2][posNodo1] = costo;

        /**Obtener las Aristas*/
        aristas[contador] = new Arista(costo);
        contador++;
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

