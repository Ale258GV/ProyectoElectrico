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
    inicial = primerNodo;
    sig = segundoNodo;
    if(sig->verSuministrarEnergia() == true){
        double sum, energiaPrincipal, energiaDestino;
        energiaPrincipal = inicial->verEnergia();
        energiaDestino = sig->verEnergia();
        sum = (energiaPrincipal - cableado) + energiaDestino;
        sig->setEnergia(sum);
    }else{
        double resto, energiaPrincipal;
        energiaPrincipal = inicial->verEnergia();
        resto = energiaPrincipal - cableado; //cambiar +/- en caso de diferente funcion (+ ver coste)(- cobrar coste)
        sig->setEnergia(resto);
    }
}
void Arista::verConexionNodos(){
    // << endl << "---Nodo Inicial---" << endl;
    //cout << "Ubicacion: " << inicial->verUbicacion() << endl;
    //cout << "Cantidad de Energia que Suministra: " << inicial->verEnergia() << endl;
    //(inicial->verSuministrarEnergia() == true) ? cout << "El nodo es una central" << endl : cout << "El nodo es una ciudad" << endl;
    //cout << endl << "---Nodo Destino---" << endl;
    //cout << "Ubicacion: " << sig->verUbicacion() << endl;
    //cout << "Cantidad de Energia que Suministra: " << sig->verEnergia() << endl;
    //(sig->verSuministrarEnergia() == true) ? cout << "El nodo es una central" << endl : cout << "El nodo es una ciudad" << endl;
    cout << endl << "\t" << inicial->verUbicacion() << "  -----  " << sig->verUbicacion() << endl;
    if(inicial->verSuministrarEnergia() == true){
        cout << endl << "\t" << inicial->verEnergia() << "  -----  " << sig->verEnergia() << endl;
    }else{
        cout << endl << "\t" << "0" << "  -----  " << "0" << endl;
    }
    cout << endl;
}
