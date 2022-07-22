#include "Validar.h"
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;
/**
 * @brief
 *
 * @param msj
 * @param dim
 * @param espacio
 * @return string
 */
string Validar::validarLetras(string msj, int dim, bool espacio) {
    char dato[20];
    int i;
    char tecla;
    cout << msj;
    i = 0;
    dato[0] = '\0';
    do {
        tecla = _getch();
        if (i < dim) {
            if (i > 0 && tecla == 8)
            {
                cout << "\b \b";
                dato[--i] = '\0';
            }
            else {
                if (espacio == false) {
                    if ((tecla >= 65 && tecla <= 95) ||
                        (tecla >= 97 && tecla <= 122) &&
                        tecla != 32)
                    {
                        cout << tecla;
                        dato[i++] = tecla;
                    }
                }
                else {
                    if ((tecla >= 65 && tecla <= 95) ||
                        (tecla >= 97 && tecla <= 122) ||
                        tecla == 32)
                    {
                        cout << tecla;
                        dato[i++] = tecla;
                    }
                }
            }
        }
    } while ((tecla != 13 || dato[0] == '\0'));
    dato[i] = '\0';
    string retorno(dato);
    return retorno;
}
/**
 * @brief
 *
 * @param msj
 * @param dim
 * @return string
 */
string Validar::validarNumeros(string msj, int dim) {
    char dato[10];
    int i;
    char tecla;
    cout << msj;
    i = 0;
    dato[0] = '\0';
    do
    {
        tecla = _getch();
        if (i > 0 && tecla == 8) {
            cout << "\b \b";
            dato[--i] = '\0';
        }
        else {
            if (i < dim) {
                if ((tecla >= 48 && tecla <= 57)) {
                    cout << tecla;
                    dato[i++] = tecla;
                }
            }
        }
    } while ((tecla != 13 || dato[0] == '\0'));
    dato[i] = '\0';
    string retorno(dato);
    return retorno;
}
/**
 * @brief
 *
 * @return string
 */
bool Validar::validarCedula(string _id) {
    if (_id.length() != 10)
    {
        return true;
    }

    int temp;
    int sum_par = 0;
    int sum_impar = 0;
    int sum;

    int i = 1;
    std::string digits = _id.substr(0, _id.size() - 1);
    for (char& c : digits)
    {
        int digit = c - '0';
        if (i % 2 == 0) {
            sum_par += digit;
        }
        else {
            if ((digit * 2) > 9)
            {
                sum_impar += (digit * 2) - 9;
            }
            else
            {
                sum_impar += (digit * 2);
            }
        }
        i++;
    }

    sum = sum_par + sum_impar;
    int verifier = _id.at(_id.size() - 1) - '0';
    int higher = (10 - (sum % 10)) + sum;

    if (sum % 10 == 0)
    {
        return verifier != 0;
    }
    if ((higher - sum) == verifier) {
        return false;
    }
    else {
        std::cout << "\nLa cedula ingresada es invalida" << std::endl;
        return true;

    }
}
/**
 * @brief
 *
 * @param numero
 * @return true
 * @return false
 */
bool Validar::validarFloat(string const& numero){
    bool toReturn = false;
    try
    {
        std::size_t pos = 0;
        std::stof(numero, &pos);
        toReturn = (pos == numero.length());
    }
    catch (std::exception const&)
    {
    }
    return toReturn;
}