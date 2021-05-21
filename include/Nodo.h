#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string>
using namespace std;
class Nodo {
        private:
    /**Atributos*/
	string nombreCiudad;
	string estadoCiudad;
	string descripcion;
	string ubicacion;
	int numeroCiudad;
	int poblacionCiudad;
	double demandaEnergiaCiudad;
	double energia;
	bool suministrarEnergia;
	    public:
    /**Constructor*/
	Nodo();
	Nodo(string nombreCiudad2, string estadoCiudad2, string descripcion2, string ubicacion2, int numeroCiudad2, int poblacionCiudad2, double demandaEnergiaCiudad2, double energia2, bool suministrarEnergia2);
	Nodo(string ubicacion2, double energia2, bool suministrarEnergia2);
	/**Metodos de Visualización*/
    string verNombreCiudad();
	string verEstadoCiudad();
	string verDescripcion();
	string verUbicacion();
	int verNumeroCiudad();
	int verPoblacionCiudad();
	double verDemandaEnergiaCiudad();
	double verEnergia();
	bool verSuministrarEnergia();
	/**Metodos de cambio de Atributo*/
	void setNombreCiudad(string nombreCiudad2);
	void setEstadoCiudad(string estadoCiudad2);
    void setDescripcion(string descripcion2);
    void setUbicacion(string ubicacion2);
    void setNumeroCiudad(int numeroCiudad2);
    void setPoblacionCiudad(int poblacionCiudad2);
    void setDemandaEnergiaCiudad(double demandaEnergiaCiudad2);
    void setEnergia(double energia2);
    void setSuministrarEnergia(bool suministrarEnergia2);
};
#endif // NODO_H
