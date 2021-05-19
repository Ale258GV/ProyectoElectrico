#include "Arista.h"
#include "Nodo.h"

Arista::Arista(){
    inicial = NULL;
    sig = NULL;
    costoMonetario = 0;
    cableado = 0;
    calibre = 0;
    cantSuministrada = 0;
}
Arista::Arista(double cableado2, double calibre2, double cantSuministrada2) {
    inicial = NULL;
    sig = NULL;
    cableado = cableado2;
    calibre = calibre2;
    cantSuministrada = cantSuministrada2;
    costoMonetario = cableado * 100;
}
Arista::Arista(double cableado2) {
    inicial = NULL;
    sig = NULL;
    cableado = cableado2;
    calibre = 0;
    cantSuministrada = 0;
    costoMonetario = 0;
}
/**Metodos de Visualización*/
double Arista::verCostoMonetario(){
    return costoMonetario;
}
double Arista::verCableado(){
    return cableado;
}
double Arista::verCalibre(){
    return calibre;
}
double Arista::verCantSuministrada(){
    return cantSuministrada;
}
/**Metodos de cambio de Atributo*/
void Arista::setCostoMonetario(double costoMonetario2){
    costoMonetario = costoMonetario2;
}
void Arista::setCableado(double cableado2){
    cableado = cableado2;
}
void Arista::setCalibre(double calibre2){
    calibre = calibre2;
}
void Arista::setCantSuministrada(double cantSuministrada2){
    cantSuministrada = cantSuministrada2;
}

void Arista::conectarNodos(Nodo *primerNodo, Nodo *segundoNodo){
    Nodo *nodoPrincipal, *nodoDestino;
    nodoPrincipal = primerNodo; //Null
    nodoDestino = segundoNodo; //Null
    inicial = nodoPrincipal;
    sig = nodoDestino;

    if(sig->verSuministrarEnergia() == true){
        double sum, energiaPrincipal, energiaDestino;
        energiaPrincipal = nodoPrincipal->verEnergia();
        energiaDestino = nodoDestino->verEnergia();
        sum = (energiaPrincipal - cableado) + energiaDestino;
        nodoDestino->setEnergia(sum);
    }else{
        double resto, energiaPrincipal;
        energiaPrincipal = nodoPrincipal->verEnergia();
        resto = energiaPrincipal + cableado; //cambiar +/- en caso de diferentefuncion (+ ver coste)(- cobrar coste)
        nodoDestino->setEnergia(resto);
    }
}

void Arista::verConexionNodos(){
    cout << "---Nodo Inicial---" << endl;
    cout << "Ubicacion: " << inicial->verUbicacion() << endl;
    //cout << "Cantidad de Energia que Suministra: " << inicial->verEnergia() << endl;
    //(inicial->verSuministrarEnergia() == true) ? cout << "La central administra energia" << endl : cout << "La central solamente recibe energia" << endl;
    cout << endl << "---Nodo Destino---" << endl;
    cout << "Ubicacion: " << sig->verUbicacion() << endl;
    //cout << "Cantidad de Energia que Suministra: " << sig->verEnergia() << endl;
    //(sig->verSuministrarEnergia() == true) ? cout << "La central administra energia" << endl : cout << "La central solamente recibe energia" << endl;
    cout << endl;
}
