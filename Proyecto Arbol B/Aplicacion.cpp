#include "Aplicacion.h"

using namespace std;
void drawImage(std::string imagePath, HDC* console);
int Aplicacion::run() {
    init();
    return 0;

}
void Aplicacion::init() {
    cout << "\n";

    std::vector<MenuOptionM> menu_item
    {
        {1, "Arbol B",ArbolB},
        {2, "Imagen PixelArt", Imagen},
        {3, "Ayuda", help},
        {3, "SALIR",funca }
    };
    MenuM menu{ menu_item };
    menu.navigation();
}
void Aplicacion::funca() {
    exit(0);
}
//PROCESO REGISTRO PERSONAS

void Aplicacion::Imagen() {
    runIMG();
}
int Aplicacion::runIMG() {

    HWND console = GetConsoleWindow();
    HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
    HDC dc = GetDC(console);

    CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
    GetCurrentConsoleFontEx(output, FALSE, &Font);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 1;
    cfi.dwFontSize.Y = 1;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    ShowWindow(console, SW_SHOWMAXIMIZED);

    //COORD pos = { 0, 15 };
    //SetConsoleCursorPosition(output, pos);

    std::cout << std::endl;
    drawImage("ejemplofinal.bmp", &dc);
    _getch();

    SetCurrentConsoleFontEx(output, FALSE, &Font);
    system("cls");
    return 0;
}
void drawImage(std::string imagePath, HDC* console) {
    BMP image;
    image.ReadFromFile(imagePath.c_str());

    double original_width = image.TellWidth();
    double original_height = image.TellHeight();
    double ratio = ratio = original_width / original_height;

    double max_width = 500;
    double width = original_width;
    double height = original_height;

    if (original_width > max_width) {
        height = max_width / ratio;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int RED = image.GetPixel(x, y).Red;
            int GREEN = image.GetPixel(x, y).Green;
            int BLUE = image.GetPixel(x, y).Blue;

            int ALPHA = image.GetPixel(x, y).Alpha;

            COLORREF COLOUR = RGB(RED, GREEN, BLUE);
            if (ALPHA == 0) {
                //SetPixel(*console, x, y, COLOUR);

                std::cout << "\033["
                    << 48
                    << ";2;"
                    << RED << ";"
                    << GREEN << ";"
                    << BLUE << "m"
                    << '##'
                    << "\033[0;00m";

                if (x == width - 1) {
                    std::cout << std::endl;
                }
            }
        }
    }
}

void Aplicacion::ArbolB() {
    runAB();
}
int Aplicacion::runAB() {
    B_Tree tree;

    
    cout << " ____________________________________________________________________________________________________________\n";
    cout << "|                                                     MENU                                                   |\n";
    cout << "|                                                                                                            |\n";
    cout << "| 1. Crear nuevo arbol                                                                                       |\n";
    cout << "| 2. Crear backup                                                                                            |\n";
    cout << "| 3. Imprimir arbol por nivel                                                                                |\n";
    cout << "| 4. Altura del arbol                                                                                        |\n";
    cout << "| 5. Nro de nodos                                                                                            |\n";
    cout << "| 6. Encontrar llave                                                                                         |\n";
    cout << "| 7. Insertar llave                                                                                          |\n";
    cout << "| 8. Borrar llave                                                                                            |\n";
    cout << "| 9. Transformar arbol(Capacidad Max)                                                                        |\n";
    cout << "| 10. Borrar arbol                                                                                           |\n";
    cout << "|                                                                                                            |\n";
    cout << "|                                                                                                            |\n";
    cout << "| 0. Salir                                                                                                   |\n";
    cout << "|____________________________________________________________________________________________________________|\n";

    cout << "\nSeleccione:\n";

    putchar('\n');
    while (1) {

        int x;
        cin >> x;
        putchar('\n');
        switch (x)
        {
        case 1: {
            if (!tree.is_empty()) {
                tree.delete_tree();
            }
            tree.initialize();
            cout << "Arbol creado correctamente." << endl;
            break;
        }
        case 2: {
            tree.backup();
            break;
        }
        case 3: {
            if (!tree.is_empty()) {
                tree.print();
                tree.print_detailed();
            }
            else
                cout << "Arbol vacio." << endl;
            break;

        }

        case 4: {
            if (tree.is_empty()) {
                cout << "Arbol vacio." << endl;
            }
            else
                cout << "Altura del Arbol: h = " << tree.get_height() << endl;
            break;
        }
        case 5: {
            if (tree.is_empty()) {
                cout << "Arbol vacio." << endl;
            }
            else
                cout << "Numero de claves en el arbol: n = " << tree.get_key_num() << endl;
            break;
        }
        case 6: {
            if (tree.is_empty()) {
                cout << "Arbol vacio." << endl;
            }
            else {
                int key;
                cout << "Ingrese llave:" << endl;
                cin >> key;

                Pointer ptr = tree.find_key(key).node_ptr;

                if (ptr == nullptr)
                    cout << "La llave no exite en el arbol." << endl;
                else
                {
                    cout << "Llave encontrada en la posicion: " << ptr << endl;
                }

            }
            break;

        }
        case 7: {
            cout << "Ingrese el numero de llaves que quiere anadir al arbol:" << endl;
            cin >> x;
            for (int i = 0; i < x; i++) {
                cout << "Ingrese la  " << i + 1 << ". llave:" << endl;
                int key;
                cin >> key;
                tree.insert_key(key);
                tree.print();
            }
            break;

        }
        case 8: {
            if (tree.is_empty()) {
                cout << "Arbol vacio." << endl;
            }
            else {
                int key;
                cout << "Ingrese la clave a borrar: " << endl;
                cin >> key;


                if (tree.delete_key(key))
                    cout << "La llave " << key << " fue borrada correctamente." << endl;
                else
                    cout << "La llave " << key << " no existe en el arbol." << endl;

            }
            break;
        }

        case 9: {
            if (tree.is_empty())
                cout << "Arbol vacio" << endl;
            else
                tree.transform();
            break;
        }
        case 10: {
            if (tree.is_empty())
                cout << "Arbol vacio" << endl;
            else {
                cout << "Borrando arbol..." << endl;
                tree.delete_tree();
                cout << "Arbol correctamente eliminado." << endl;
            }
            break;
        }
        case 0: {
            cout << "Goodbye." << endl;
            tree.delete_tree();
            exit(EXIT_SUCCESS);
        }

        default: {
            cout << "La opcion no existe. Ingrese de nuevo:";
            continue;
        }
        }

        cout << "\nTecla para continuar.\n";
        cin.get();
        cin.get();
        system("cls");
        cout << endl;
        cout << " ____________________________________________________________________________________________________________\n";
        cout << "|                                                     MENU                                                   |\n";
        cout << "|                                                                                                            |\n";
        cout << "| 1. Crear nuevo arbol                                                                                       |\n";
        cout << "| 2. Crear backup                                                                                  |\n";
        cout << "| 3. Imprimir arbol por nivel                                                                                |\n";
        cout << "| 4. Altura del arbol                                                                                        |\n";
        cout << "| 5. Nro de nodos                                                                                            |\n";
        cout << "| 6. Encontrar llave                                                                                         |\n";
        cout << "| 7. Insertar llave                                                                                          |\n";
        cout << "| 8. Borrar llave                                                                                            |\n";
        cout << "| 9. Transformar arbol(Capacidad Max)                                                                        |\n";
        cout << "| 10. Borrar arbol                                                                                           |\n";
        cout << "|                                                                                                            |\n";
        cout << "|                                                                                                            |\n";
        cout << "| 0. Salir                                                                                                   |\n";
        cout << "|____________________________________________________________________________________________________________|\n";

        cout << "\nSeleccione:\n";

    }

    return 0;
}
void Aplicacion::help() {
    runH();
}
int Aplicacion::runH() {
    system("C:/Users/Admin/Desktop/Proyecto Btrees/Documentos_Proyecto_UML/html-docs");
    return 0;
}