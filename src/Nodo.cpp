#include "Nodo.h"
#include <iostream>
#include <string>
using namespace std;

Nodo::Nodo() {
    nombreCiudad = "";
	estadoCiudad = "";
	descripcion = "";
	ubicacion = "";
	numeroCiudad = 0;
	poblacionCiudad = 0;
	demandaEnergiaCiudad = 0;
	energia = 0;
	suministrarEnergia = false;
}
Nodo::Nodo(string nombreCiudad2, string estadoCiudad2, string descripcion2, string ubicacion2, int numeroCiudad2, int poblacionCiudad2, double demandaEnergiaCiudad2, double energia2, bool suministrarEnergia2) {
    nombreCiudad = nombreCiudad2;
	estadoCiudad = estadoCiudad2;
	descripcion = descripcion2;
	ubicacion = ubicacion2;
	numeroCiudad = numeroCiudad2;
	poblacionCiudad = poblacionCiudad2;
	demandaEnergiaCiudad = demandaEnergiaCiudad2;
	energia = energia2;
	suministrarEnergia = suministrarEnergia2;
}
Nodo::Nodo(string ubicacion2, double energia2, bool suministrarEnergia2){
    nombreCiudad = "";
	estadoCiudad = "";
	descripcion = "";
	ubicacion = ubicacion2;
	numeroCiudad = 0;
	poblacionCiudad = 0;
	demandaEnergiaCiudad = 0;
	energia = energia2;
	suministrarEnergia = suministrarEnergia2;
}
string Nodo::verNombreCiudad(){
    return nombreCiudad;
}
string Nodo::verEstadoCiudad(){
    return estadoCiudad;
}
string Nodo::verDescripcion(){
    return descripcion;
}
string Nodo::verUbicacion(){
    return ubicacion;
}
int Nodo::verNumeroCiudad(){
    return numeroCiudad;
}
int Nodo::verPoblacionCiudad(){
    return poblacionCiudad;
}
double Nodo::verDemandaEnergiaCiudad(){
    return demandaEnergiaCiudad;
}
double Nodo::verEnergia(){
    return energia;
}
bool Nodo::verSuministrarEnergia(){
    return suministrarEnergia;
}

/**Metodos de cambio de Atributo*/
void Nodo::setNombreCiudad(string nombreCiudad2){
    nombreCiudad = nombreCiudad2;
}
void Nodo::setEstadoCiudad(string estadoCiudad2){
    estadoCiudad = estadoCiudad2;
}
void Nodo::setDescripcion(string descripcion2){
    descripcion = descripcion2;
}
void Nodo::setUbicacion(string ubicacion2){
    ubicacion = ubicacion2;
}
void Nodo::setNumeroCiudad(int numeroCiudad2){
    numeroCiudad = numeroCiudad2;
}
void Nodo::setPoblacionCiudad(int poblacionCiudad2){
    poblacionCiudad = poblacionCiudad2;
}
void Nodo::setDemandaEnergiaCiudad(double demandaEnergiaCiudad2){
    demandaEnergiaCiudad = demandaEnergiaCiudad2;
}
void Nodo::setEnergia(double energia2){
    energia = energia2;
}
void Nodo::setSuministrarEnergia(bool suministrarEnergia2){
    suministrarEnergia = suministrarEnergia2;
}
