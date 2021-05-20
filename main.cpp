#include <iostream>
#include <fstream> /**Libreria para poder leer files o txt*/
#include <string> /**Libreria para poder trabajar con metodos de string*/
#include <stdlib.h> /**usar exit*/
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
    cout << endl << "---Atributos del Nodo---" << endl;
    cout << "Nombre Ciudad: " << a->verNombreCiudad() << endl;
    cout << "Estado Ciudad: " << a->verEstadoCiudad()<< endl;
    cout << "Descripcion: " << a->verDescripcion() << endl;
    cout << "Ubicacion: " << a->verUbicacion() << endl;
    cout << "Numero de la Ciudad: " << a->verNumeroCiudad() << endl;
    cout << "Poblacion Ciudad: " << a->verPoblacionCiudad() << endl;
    cout << "Demanda de energia por Ciudad: " << a->verDemandaEnergiaCiudad() << endl;
    cout << "Energia Almacenada: " << a->verEnergia() << endl;
    if(a->verSuministrarEnergia() == true){
        cout << "El nodo es una central" << endl << endl;
    }else{
        cout << "El nodo es una ciudad" << endl << endl;
    }
}
void verDatosAris(Arista *a){
    cout << endl << "---Atributos de la Arista---" << endl;
    a->verConexionNodos();
    cout << "Coste por arista: " << a->verCableado() << endl;
    //cout << "Costo por Cantidad de Cable: " << a->verCostoMonetario() << endl;
    //cout << "Calibre: " << a->verCalibre() << endl;
    //cout << "Cantidad Suministrada de Energia: " << a->verCantSuministrada() << endl << endl;
}
void menuElectrico(){
    int opc;
    string txt;
    bool salir = true;
    ifstream arch_ent;
    cout << "Escribe el nombre del archivo de texto: ";
    cin >> txt;
    Grafo *g = new Grafo(txt);
    //Grafo *g = new Grafo("GrafoTXT_Opcion2.txt");
    if(arch_ent.fail()){
        cout << "Error al abrir el archivo del grafo...";
        exit(1);
    } else {
        cout << endl << "Clase Grafo creado correctamente." << endl;
        cout << "Archivo leido correctamente." << endl;
    }
    int tam = g->verTam();

    while(salir == true){
        cout << endl << "---Menu Proyecto Electrico---" << endl;
        cout << "1. Imprimir matriz de adyacencia del archivo de texto." << endl;
        cout << "2. Mostrar todos los nodos conectados con los demas nodos." << endl;
        cout << "3. Mostrar todos los caminos minimos posibles." << endl;
        cout << "4. Establecer energia a nodo." << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opc;
        switch(opc){
            case 1: {
                g->muestraGrafo();
                break;
            }
            case 2: {
                /**Algoritmo Floyd-Warshall*/
                double costoMinimo[tam][tam];
                for(int o = 0; o<tam; o++){
                    for(int p = 0; p<tam; p++){
                        costoMinimo[o][p] = g->matriz[o][p];
                    }
                }
                string caminos[tam][tam];
                for(int o = 0; o<tam; o++){
                    for(int p = 0; p<tam; p++){
                        if(g->nodos[o]->verUbicacion() == g->nodos[p]->verUbicacion()){
                            caminos[o][p] = "";
                        }else{
                            caminos[o][p] = g->nodos[o]->verUbicacion() + "--" + to_string(g->matriz[o][p]) + "-->" + g->nodos[p]->verUbicacion();
                            /**Almacenar todos los caminos posibles en la clase grafo*/
                            g->aristas[o][p].conectarNodos(g->nodos[o], g->nodos[p]);
                            verDatosAris(&g->aristas[o][p]);
                        }
                    }
                }
                break;
            }
            case 3: {
                /**Algoritmo Floyd-Warshall*/
                double costoMinimo[tam][tam];
                for(int o = 0; o<tam; o++){
                    for(int p = 0; p<tam; p++){
                        costoMinimo[o][p] = g->matriz[o][p];
                    }
                }
                string caminos[tam][tam];
                for(int o = 0; o<tam; o++){
                    for(int p = 0; p<tam; p++){
                        if(g->nodos[o]->verUbicacion() == g->nodos[p]->verUbicacion()){
                            caminos[o][p] = "";
                        }else{
                            caminos[o][p] = g->nodos[o]->verUbicacion() + "--" + to_string(g->matriz[o][p]) + "-->" + g->nodos[p]->verUbicacion();
                        }
                    }
                }
                /**Algoritmo de Floyd-Warshall*/
                int i, j, k;
                for (k = 0; k < tam; k++)
                {
                    for (i = 0; i < tam; i++)
                    {
                        for (j = 0; j < tam; j++)
                        {
                            if ((costoMinimo[i][k] * costoMinimo[k][j] != 0) && (i != j))
                            {
                                if ((costoMinimo[i][k] + costoMinimo[k][j] <costoMinimo[i][j]) || (costoMinimo[i][j] == 0))
                                {
                                    caminos[i][j] = caminos[i][k] + ", " + caminos[k][j];
                                    costoMinimo[i][j] = costoMinimo[i][k] + costoMinimo[k][j];
                                }
                            }
                        }
                    }
                }
                /**Imprimir costes minimos con camino*/
                for (i = 0; i < tam; i++)
                {
                    cout<<"\nCoste minimo con respecto al nodo: "<< g->nodos[i]->verUbicacion() << endl;
                    for (j = 0; j < tam; j++)
                    {
                        if(i != j){ /**Condicional para evitar iteraciones en los nodos*/
                            cout<<"\tCon "<< g->nodos[j]->verUbicacion() << ": "<< costoMinimo[i][j] << " con camino: " << caminos[i][j] <<endl;
                        }
                    }
                }
                break;
            }
            case 4:{
                string str;
                double num;
                cout << endl << "Pon el nombre del nodo que administrara la energia: ";
                cin >> str;
                cout << endl << "Establece la energia del nodo: ";
                cin >> num;
                for(int i = 0; i < tam; i++){
                    if(g->nodos[i]->verUbicacion() == str){
                        g->nodos[i]->setEnergia(num);
                        g->nodos[i]->setSuministrarEnergia(true);
                        verDatosNodo(g->nodos[i]);
                    }
                }

                break;
            }
            case 5: {
                cout << endl << "Saliendo del programa..." << endl;
                salir = false;
                break;
            }
            default:
                cout << endl << "Esa no es una opcion valida, prueba con un numero..." << endl;
            break;
        }
    }
}

int main()
{
    menuElectrico();
    return 0;
}

