#pragma once
#include "Nodo.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
class Lista {
private:
	Nodo* primero;
	Nodo* actual;
public:
	Lista();
	bool ListaVacia();
	void insertar(Persona);
	void insertarFinal(Persona);
	void borrarNodoEspe(Persona);
	Nodo* buscarNodo(string);
	bool buscarBool(string);
	void mostrar();
};
