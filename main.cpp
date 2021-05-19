#include <iostream>
#include <fstream> /**Libreria para poder leer files o txt*/
#include <string> /**Libreria para poder trabajar con metodos de string*/
#include "Nodo.h"
#include "Arista.h"
#include "Grafo.h"
using namespace std;

/**
Estructura de Datos
Equipo 2: Proyecto Eléctrico
Integrantes:
    GARCÍA VARGAS MICHELL ALEJANDRO - 259663
    JIMÉNEZ ELIZALDE ANDRÉS - 259678
    LEÓN PAULIN DANIEL - 260541
    MORALES RANGEL MARIA GUADALUPE - 290296
    MORALES TLATENCHI ALEXIS IVAN - 254387
    SALAZAR CASTILLO GUADALUPE - 261540
    SAUZA ARREGUIN MÓNICA MONSERRAT - 290269
    VELÁZQUEZ CAMPOS LEONARDO - 250893
Grupo: 30
4to. Semestre
*/

void verDatosNodo(Nodo *a){
    cout << "---Atributos del Nodo---" << endl;
    cout << "Nombre Ciudad: " << a->verNombreCiudad() << endl;
    cout << "Estado Ciudad: " << a->verEstadoCiudad()<< endl;
    cout << "Descripcion: " << a->verDescripcion() << endl;
    cout << "Ubicacion: " << a->verUbicacion() << endl;
    cout << "Numero de la Ciudad: " << a->verNumeroCiudad() << endl;
    cout << "Poblacion Ciudad: " << a->verPoblacionCiudad() << endl;
    cout << "Demanda de energia por Ciudad: " << a->verDemandaEnergiaCiudad() << endl;
    cout << "Energia Almacenada: " << a->verEnergia() << endl;
    if(a->verSuministrarEnergia() == true){
        cout << "La central administra energia" << endl << endl;
    }else{
        cout << "La central solamente recibe energia" << endl << endl;
    }
}
void verDatosAris(Arista *a){
    cout << "---Atributos de la Arista---" << endl;
    a->verConexionNodos();
    cout << "Costo por Cantidad de Cable: " << a->verCostoMonetario() << endl;
    cout << "Cableado por Metros: " << a->verCableado() << endl;
    cout << "Calibre: " << a->verCalibre() << endl;
    cout << "Cantidad Suministrada de Energia: " << a->verCantSuministrada() << endl << endl;
}

int main()
{
    /*Nodo *central = new Nodo("Pie de Gallo", "Queretaro", "Un lugar bien bonito", "Calle idk", 1, 50, 50.0, 100.0, true);
    Nodo *central2 = new Nodo("San Francisco", "Guanajuato", "Casita Chiquita", "Av. idk", 2, 80, 80.0, 0, false);
    Arista *cableado = new Arista(15, 10, 20);

    cableado->conectarNodos(central, central2);
    verDatosNodo(central);
    verDatosAris(cableado);*/

    /*Nodo *A = new Nodo("Pie de gallo", 100, true);
    Nodo *B = new Nodo("San Isidro Buenavista", 0, false);//85
    Nodo *C = new Nodo("Santa Maria los Baños", 50, true);
    Arista *a1 = new Arista(15);
    Arista *a2 = new Arista(30);

    a1->conectarNodos(A, B);
    a2->conectarNodos(B, C);

    verDatosAris(a1);
    verDatosAris(a2);*/

    Grafo *g = new Grafo("GrafoTXT_Opcion1.txt");
    g->muestraGrafo();

    //algoritmo floyd warshall
    int tam = g->verTam();
    double matriz2[tam][tam];
    for(int o = 0; o<tam; o++){
        for(int p = 0; p<tam; p++){
            matriz2[o][p] = g->matriz[o][p];
        }
    }
    string caminos[tam][tam];
    for(int o = 0; o<tam; o++){
        for(int p = 0; p<tam; p++){
            caminos[o][p] = g->nodos[o]->verUbicacion() + "-" + g->nodos[p]->verUbicacion();
        }
    }

    //Algoritmo de Floyd-Warshall
    int i, j, k;
    for (k = 0; k < tam; k++)
    {
        for (i = 0; i < tam; i++)
        {
            for (j = 0; j < tam; j++)
            {
                if ((matriz2[i][k] * matriz2[k][j] != 0) && (i != j))
                {
                    if ((matriz2[i][k] + matriz2[k][j] < matriz2[i][j]) || (matriz2[i][j] == 0))
                    {
                        matriz2[i][j] = matriz2[i][k] + matriz2[k][j];
                        caminos[i][j] = caminos[i][k] + "-" + caminos[k][j];
                        //cout << caminos[i][j] + "=" + caminos[i][k]  + " + " + caminos[k][j] << endl;
                        //cout << caminos[i][j] << "     " << matriz2[i][j] << endl;
                        g->aristas[j]->conectarNodos(g->nodos[i], g->nodos[j]);
                        g->aristas[j]->verConexionNodos();
                        cout << i << " - " << j << " - " << k << endl << endl;
                    }
                }
            }
        }
    }
    //Imprimir costes minimos con camino
    for (i = 0; i < tam; i++)
    {
        cout<<"\nCoste minimo con respecto al nodo:" << g->nodos[i]->verUbicacion()<<endl;
        for (j = 0; j < tam; j++)
        {
            cout<<"\tCon "<< g->nodos[j]->verUbicacion() << ": " << matriz2[i][j] << " con camino: " << caminos[i][j] <<endl;
        }

    }

    //cout << g->nodos[2]->verUbicacion() << endl;
    //cout << g->aristas[5]->verCableado() << endl;
    return 0;
}
