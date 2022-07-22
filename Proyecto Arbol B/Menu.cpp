#include "Menu.h"
#include <thread>
#include <chrono>

Menu::Menu(std::vector<MenuOption> options) : menu_option_(options) {
    console_ = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Menu::display() {
    unsigned int i = 0;

    HANDLE conhandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(conhandle, &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    COORD bufferSize = csbi.dwSize;
    COORD size = { columns, rows };

    while (menuCorriendo) {
        limpiar_ventana({ 0, 2, size.X, size.Y });
        SetConsoleCursorPosition(conhandle, { 0, 2 });

        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        std::cout << "----- MENU ----- " << std::endl;

        int i = 0;
        for (MenuOption option : this->menu_option_) {
            std::cout << ++i << ": " << option.get_title_() << std::endl;
        }

        int n;

        std::cout << std::endl;
        
        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> n;
            bool failed = std::cin.fail();

            std::cin.clear();
            std::cin.ignore(9999, '\n');

            if (failed) {
                continue;
            }
        } while (n < 1 || n > this->menu_option_.size());

        std::cout << std::endl;
        std::cout << std::endl;

        MenuOption option = this->menu_option_.at(n - 1);
        option.get_fuction()();

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "[presione enter para continuar]";
        std::cin.get();
    }
}
