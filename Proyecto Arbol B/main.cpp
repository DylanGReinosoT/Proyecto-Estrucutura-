#pragma warning(disable : 4996)
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <ctime>
#include <Windows.h>
#include "Aplicacion.h"
#include "marquesina.h"
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

#define MAX 4
#define MIN 0


//Variables utilizadas en el programa
const char FINCAD = char(0);
const int MAXCAD = 20;

const char SP = ' ';
char contrasena;
int i;
int contador = 0;

//Tcadena: cadena de caracteres ocupadas con MAXCAD + FINCAD
typedef char TCadena[MAXCAD + 1]; // MAXCAD caracteres + FINCAD
struct Person_R
{
    TCadena contras;
};


//Funciones Principales

void Ingresar_contrasena(Person_R& p);
void Aceptar_contrasena(Person_R& p);

void Crear_archivo(TCadena nombreFichero, Person_R p);
void Ingreso_archivo_person(ofstream& fichero, Person_R p);
void verificar_existencia_fichero(TCadena nombreFichero);
void verificar_existencia_person(TCadena nombreFichero);
void verificar_contrasena(TCadena nombreFichero, Person_R& password);

void borrar();
void pausa();
void finalizar();
string asterisco(string);


int main()
{
    Marquesina marquesina("ESPE  |  GRUPO 3 y 17: ESTRUCTURA DE DATOS | MYCKEL CHAMORRO, GABRIEL REINOSO, JONATHAN TOAPANTA Y DIEGO TORRES");
    marquesina.iniciar();
    Person_R p;
    Person_R password;
    char opcion;
    int num;
    bool fin, encontrado;
    TCadena nombre_usuario_registrado;
    int op;
    char* word = NULL;
    char* aux = NULL;
    bool repetir = true;

        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Registrar" << endl;
        cout << "3. Salir" << endl;


        cout << "\nIngrese una opcion: ";
        cin >> op;

       
 
    aux = (char*)calloc(200, sizeof(char));
    word = (char*)calloc(200, sizeof(char));
    system("CLS");

    if (op == 3) { finalizar(); }
    if ((op < 0) || (op > 3)) {

        /* La declaración try... catch señala un bloque de instrucciones a intentar ( try ),
        y especifica una respuesta si se produce una excepción ( catch ).*/
        try {
            system("cls");

            cout << "\n\n\t Opcion incorrecta. \n";
            Sleep(50);
            system("cls");
            main();
        }
        catch (...)
        {
            cout << "\n Error " << endl;
        }
    }

    switch (op)
    {
    case 1: {
        //Ingreso de Usuario
        cout << "\nIngrese su nombre de usuario -->     ";
        cin >> nombre_usuario_registrado;
        verificar_existencia_fichero(nombre_usuario_registrado);

        verificar_contrasena(nombre_usuario_registrado, password);
        Sleep(1000); borrar(); Aplicacion::run();
        break;
    }

    case 2: {
        //Registro
        cout << "\nIngrese el nombre de usuario -->    ";
        cin >> nombre_usuario_registrado;
        verificar_existencia_person(nombre_usuario_registrado);
        Ingresar_contrasena(p);
        Crear_archivo(nombre_usuario_registrado, p);
        Sleep(1000); borrar(); main();
        break;
    }

    case 3: {
        exit(0);
        break;
    }
    }

}

void Ingresar_contrasena(Person_R& p)
{
    string contra;
    int cant;
    contra = asterisco("Ingrese la contrasena: ");
    strcpy(p.contras, contra.c_str());
    cout << "\nRegistro exitoso. " << endl; Sleep(2500);
}


void Aceptar_contrasena(Person_R& password)
{
    cout << "Ingrese su contrasena --> ";
    cin >> password.contras;
}

string asterisco(string msg) {

    string text = "";
    char letter;
    cout << msg;
    letter = _getch();
    while (letter != 13 || text.length() == 0) {
        if ((letter >= '0' && letter <= '9') || (letter < 91 && letter > 64) || (letter < 123 && letter > 96) || letter == 48 || letter == 64) {
            text.push_back(letter);
            cout << "*";
        }
        letter = _getch();
    }
    return text;
}

//Ficheros
void Crear_archivo(TCadena _nombreFichero, Person_R p)
{
    ofstream out;
    string nombreFichero = _nombreFichero;
    out.open(nombreFichero, ios::app);

    //Abrir el fichero
    if (out.bad()) {
        out.open(nombreFichero);
    }
    Ingreso_archivo_person(out, p);
    out.close();
}

void Ingreso_archivo_person(ofstream& fichero, Person_R p)
{
    fichero << p.contras << SP;
}

void verificar_existencia_fichero(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero);
    if (!archivo)
    {
        cout << "\nUsuario incorrecto, ingrese nuevamente el Nombre de Usuario:  " << endl; Sleep(2500); borrar(); main();
    }
    else
    {
       
    }
}

void verificar_existencia_person(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero);
    if (!archivo)
    {
    
    }
    else
    {
        cout << "\nNombre de Usuario existente, ingrese un Nombre de Usuario diferente: " << endl; Sleep(2500); borrar(); main();


    }
}

void verificar_contrasena(TCadena nombreFichero, Person_R& password)
{
    string cadena;
    string contrase;
    string contra;
    contra =asterisco("Escriba su contrasena: ");
    strcpy(password.contras, contra.c_str());

    ifstream fichero(nombreFichero, ios::in);

    while (!fichero.eof()) {
        fichero >> cadena;


    }
    if (cadena != password.contras) {

        cout << "\nIntente nuevamente ingresar la contrasena: " << endl; Sleep(2000); borrar(); main();


        fichero.close();
    }

    if (cadena == password.contras) {

        cout << "\n\tWelcome\n" << endl;  Sleep(500);

    }
}

void borrar()
{
    system("cls");
}


void pausa()
{
    system("pause");
}

void finalizar()
{
    borrar();

    exit(0);
}