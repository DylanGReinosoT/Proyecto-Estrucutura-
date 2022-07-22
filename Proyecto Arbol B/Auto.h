
/**
* @file Auto.h
* @version 1.2
* @date 09/06/2022
* @author Myckel Chamorro & Gabriel Reinoso
* @title Clase Auto
* @brief Clase para la generacion de vehiculos
* */

#pragma once
#include <iostream>
using namespace std;

/**
* @brief Clase para generar Vehiculos
* */
class Auto {
private:
    string Marca;
    string Modelo;
    string Placa;
    string Anio;
    string Color;
    string Cilindraje;
    string propietario;
    
public:
    Auto(string, string, string, string, string,string, string);
    Auto() = default;
    string get_Marca();
    void set_Marca(string);
    string get_Modelo();
    void set_Modelo(string);
    string get_Placa();
    void set_Placa(string);
    string get_Anio();
    void set_Anio(string);
    string get_Color();
    void set_Color(string);
    string get_Cilindraje();
    void set_Cilindraje(string);
    string get_Propietario();
    void set_Propietario(string);
   
};