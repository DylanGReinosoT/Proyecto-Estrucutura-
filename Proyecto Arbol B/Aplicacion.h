
/**
* @file Aplicacion.h
* @version 1.2
* @date 09/06/2022
* @author Myckel Chamorro & Gabriel Reinoso
* @title Clase Aplicacion
* @brief Clase para la generacion de registros  
* */
#pragma once
#include <vector>
#include <iostream>
#include <windows.h>
#include "MenuM.h"
#include "MenuOptionM.h"
#include <iomanip>
#include <sstream>
#include "Validar.h"
#include "EasyBMP.h"
#include "B_Tree.h"

/**
* @brief Clase para generar registros
* */
class Aplicacion {
private:
	static void init();
	static void funca();
	//static void registroPersonas();
	//static void registroAutos();
	//static void listadoPersonas();
	//static void listadoAutos();
	//static void listadoAutosPersonas();
	static void Imagen();
	static void ArbolB();
public:
	/**
	* @brief Run
	* @param _
	* @return retorna un valor entero
	*/
	static int run();
	static int runIMG();
	/**
	* @brief RunAB
	* @param _
	* @return retorna un valor entero
	*/
	static int runAB();
	
};