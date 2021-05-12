#include <iostream>
#include <fstream> /**Libreria para poder leer files o txt*/
#include <string> /**Libreria para poder trabajar con metodos de string*/
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

//NOTAS
//Todo el code que está aquí hasta el momento, es de Daniel
//Revisar el code con los archivos GrafoTXT_Opcion1 y GrafoTXT_Opcion2, ya que con esos archivos no funciona el code
int main()
{
    string cad;
    ifstream arch_ent("GrafoEj.txt"); /**Archivo de texto, de donde se saca el grafo*/
    getline(arch_ent, cad);
    int tam = stoi(cad); /**Cantidad de nodos*/
    string nodos[tam];

    for(int i=0; i<tam; i++){ /**Obtener los nodos*/
        getline(arch_ent, cad);
        nodos[i]=cad;
    }

    double aristas[tam][tam];

    for(int o = 0; o<tam; o++){
        for(int p = 0; p<tam; p++){
            aristas[o][p] = 0;
        }
    }

    while(!arch_ent.eof()){ /**Obtener aristas*/
        getline(arch_ent, cad);

        int a = cad.size(); /**Tamaño de la línea*/
        string nodo1, nodo2;
        int posEspacio, posEspacio2;

        posEspacio = cad.find(' '); /**Obtener 1er nodo*/
        nodo1 = cad.substr(0,posEspacio);
        cad.replace(0,posEspacio+1,"");

        posEspacio2 = cad.find(' '); /**Obtener 2do nodo*/
        nodo2 = cad.substr(0,posEspacio);
        cad.replace(0,posEspacio2+1,"");

        double costo = stod(cad); /**Obtener costo*/

        int posNodo1, posNodo2=-1;

        /**Buscar posicion correspondiente al 1er y 2do Nodo*/
        for(int j = 0; j<tam; j++){
            if(nodos[j] == nodo1){
                posNodo1 = j;
            }
            if(nodos[j] == nodo2){
                posNodo2 = j;
            }
        }

        cout<<""<<nodo1;
        cout<<" "<<nodo2;
        cout<<" "<<costo<< " - Pos donde almacenar costo: "<< posNodo1<<", "<< posNodo2<<endl;
        /**Insertar en matriz de adyacencia*/
        aristas[posNodo1][posNodo2] = costo;
        aristas[posNodo2][posNodo1] = costo;
    }

    /**Imprimir Matriz de Adyacencia*/
    cout<< "\nMatriz de Adyacencia:" <<endl;
    for(int k = 0; k<tam; k++){
        for(int l = 0; l<tam; l++){
            cout<< aristas[k][l] << ", ";
        }
        cout<< endl;
    }
    return 0;
}
