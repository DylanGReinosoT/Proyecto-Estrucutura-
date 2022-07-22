/*----------------------------------------------------------------------------+
|		      UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE			              |
| 		        	ESTRUCTURA DE DATOS									      |
| AUTORES: CRISTOPHER ZAMBRANO, JOSUE FERRIN, RICARDO GRIJALVA, RICHADR ALBAN |
| FECHA: MIERCOLES 26 DE ENERO DEL 2022                                       |
| NRC: 7166                                                                   |
+-----------------------------------------------------------------------------*/
#pragma once
#include "Menu.h"
#include "sha1.h"
#include <list>

class Autentificacion
{
public:
	class DatosUsuario {
	public:
		std::string nombreUsuario;
		std::string contraseniaUsuario;
	};

	Autentificacion();
	void iniciar();
	void registrarUsuario();
	void loguearse();
	std::string leerPassword(std::string);

private:
	Menu* menu;
	SHA1 hash;

	std::list<DatosUsuario> getListaUsuarios();
	void ingresarUsuarioNuevo(DatosUsuario datos);
	bool nombreUsuarioOcupado(std::string nombreUsuario);
};

