#pragma once
#include <iostream>
using namespace std;
class Persona {
private:
    string Pnombre;
    string Snombre;
    string P_apellido;
    string S_apellido;
    string correo;
    string telefono;
    string CI;
    
public:
    Persona(string, string,string, string, string, string, string);
    Persona() = default;
    string get_Pnombre();
    void set_Pnombre(string);
    string get_Snombre();
    void set_Snombre(string);
    string get_Papellido();
    void set_Papellido(string);
    string get_Sapellido();
    void set_Sapellido(string);
    string get_correo();
    void set_correo(string);
    string get_CI();
    void set_CI(string);
    string get_telefono();
    void set_telefono(string);
    int get_edad();
    void set_edad(int);
};