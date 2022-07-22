#include "Autentificacion.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

Autentificacion::Autentificacion()
{
    menu = new Menu({
        MenuOption("iniciar sesion", std::bind(&Autentificacion::loguearse, this)),
        MenuOption("registrar un nuevo usuario", std::bind(&Autentificacion::registrarUsuario, this)),
        MenuOption("Salir", [&]() { exit(0); })
    });
}

void Autentificacion::iniciar() {
    menu->display();
}

void Autentificacion::registrarUsuario() {
    std::string nombreDeUsuario;
    std::string contraseniaUsuario;

    do {
        std::cout << "ingrese su usuario: ";
        std::getline(std::cin, nombreDeUsuario);

        if (nombreDeUsuario.length() < 3) {
            std::cout << "\n(Ingrese minimo 3 caracteres)\n";
            continue;
        }

        if (nombreUsuarioOcupado(nombreDeUsuario)) {
            std::cout << "\n(ese nombre ya esta registrado)\n";
            continue;
        }
    } while (nombreDeUsuario.empty());

    do {
        contraseniaUsuario = leerPassword("ingresa un password: ");

        if (contraseniaUsuario.length() < 2) {
            std::cout << "\n(La contrasenia debe tener 2 de longitud minima)\n";
            continue;
        }
    } while (contraseniaUsuario.empty());

    DatosUsuario datos;
    datos.nombreUsuario = nombreDeUsuario;
    datos.contraseniaUsuario = contraseniaUsuario;

    ingresarUsuarioNuevo(datos);

    std::cout << std::endl;
    std::cout << "nuevo usuario registrado" << std::endl;
}

void Autentificacion::loguearse() {
    std::string nombreDeUsuario;
    std::string contraseniaUsuario;

    do {
        std::cout << "ingrese su usuario: ";
        std::getline(std::cin, nombreDeUsuario);
    } while (nombreDeUsuario.empty());

    do {
        contraseniaUsuario = leerPassword("ingrese su contrasenia: ");
    } while (contraseniaUsuario.empty());

    auto listaUsuarios = getListaUsuarios();

    for (auto const& usuario : listaUsuarios) {
        bool coincide =
            usuario.nombreUsuario == nombreDeUsuario
            &&
            usuario.contraseniaUsuario == hash(contraseniaUsuario);

        if (coincide) {
            std::cout << std::endl;
            std::cout << "bienvenido de nuevo" << std::endl;
            menu->detener();
            return;
        }
    }

    std::cout << std::endl;
    std::cout << "autentificacion incorrecta" << std::endl;
}

std::string Autentificacion::leerPassword(std::string indicacion)
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    std::string s;
    std::cout << indicacion;
    getline(std::cin, s);
    std::cout << std::endl;
    SetConsoleMode(hStdin, mode);

    return s;
}

std::list<Autentificacion::DatosUsuario> Autentificacion::getListaUsuarios()
{
    std::list<DatosUsuario> lista;
    std::ifstream txt("database_usrs.txt");

    for (std::string row; std::getline(txt, row); )
    {
        std::stringstream stream(row);
        DatosUsuario datos;
        int i = 0;

        for (std::string column; std::getline(stream, column, ','); i++)
        {
            if (i == 0) {
                datos.nombreUsuario = column;
            } else if (i == 1) {
                datos.contraseniaUsuario = column;
            }
        }

        lista.push_back(datos);
    }

    txt.close();

    return lista;
}

void Autentificacion::ingresarUsuarioNuevo(DatosUsuario datos)
{
    std::ofstream archivo("database_usrs.txt", std::ios::app);
    archivo << datos.nombreUsuario << "," << hash(datos.contraseniaUsuario) << std::endl;
    archivo.close();
}

bool Autentificacion::nombreUsuarioOcupado(std::string nombreUsuario)
{
    auto lista = getListaUsuarios();

    for (auto const& usuario : lista) {
        std::string a = usuario.nombreUsuario;
        std::string b = nombreUsuario;

        std::transform(a.begin(), a.end(), a.begin(), [](char c) {
            return ::tolower(c);
        });

        std::transform(b.begin(), b.end(), b.begin(), [](char c) {
            return ::tolower(c);
        });

        if (a == b) {
            return true;
        }
    }

    return false;
}
