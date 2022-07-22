#pragma once
#include <iostream>
using namespace std;
class Validar {
public:
	Validar() = default;
	string validarLetras(const string, int, bool);
	string validarNumeros(const string, int);
	bool validarCedula(string );
	bool validarFloat(string const&);
};