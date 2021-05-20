#ifndef ARISTA_H
#define ARISTA_H
#include "Nodo.h"

class Arista
{
    private:
    /**Atributos*/
	Nodo *inicial, *sig;
	double costoMonetario;
	double cableado;
	double calibre;
	double cantSuministrada;
    /**Constructor*/
    public:
	Arista();
	Arista(double cableado2, double calibre2, double cantSuministrada2);
	Arista(double cableado2); //preguntar cableado == cantSuministrada?????
	/**Metodos de Visualización*/
    double verCostoMonetario();
	double verCableado();
	double verCalibre();
	double verCantSuministrada();
	/**Metodos de cambio de Atributo*/
    void setCostoMonetario(double costoMonetario2);
	void setCableado(double cableado2);
	void setCalibre(double calibre2);
	void setCantSuministrada(double cantSuministrada2);

	void conectarNodos(Nodo *primerNodo, Nodo *segundoNodo);
    void verConexionNodos();
};

#endif // ARISTA_H
