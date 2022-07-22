#include "MenuM.h"
MenuM::MenuM(std::vector<MenuOptionM> options) : menu_option_(options)
{
    console_ = GetStdHandle(STD_OUTPUT_HANDLE);
}
void MenuM::navigation()
{

    if (menu_option_.empty()) {
        return;
    }
    size_t i{ 1 };
    display(1);
    while (1)
    {
        int option = _getch();


        switch (option)
        {
        case KEY_UP:
        {
            if (i != 1)
            {
                i--;
                display(i);
            }
            break;
        }
        case KEY_DOWN:
        {
            if (i != menu_option_.size())
            {
                i++;
                display(i);
            }
            break;
        }
        case KEY_ENTER:
        {
            system("cls");
            menu_option_.at(i - 1).get_fuction()();
            system("pause");
            break;
        }
        case KEY_ESCAPE:
        {
            exit(0);
            break;
        }

        default:
            break;
        }
    }
}

void MenuM::display(size_t option)
{
    system("cls");
    unsigned int i = 0;
    SetConsoleCursorPosition(console_, { 35,8 });
    std::cout << "\t\t  ARBOL B" << std::endl;
    while (i < menu_option_.size())
    {

        if (option == i + 1)
        {
            SetConsoleCursorPosition(console_, { 50,short(i + 10) });
            SetConsoleTextAttribute(console_, FOREGROUND_RED);
            std::cout << "[" << menu_option_[i].get_number_option_() << "] " << menu_option_[i].get_title_() << std::endl;
            SetConsoleTextAttribute(console_, 15);
        }
        else
        {
            SetConsoleCursorPosition(console_, { 50,short(i + 10) });
            std::cout << "[" << menu_option_[i].get_number_option_() << "] " << menu_option_[i].get_title_() << std::endl;
        }
        i++;
    }
}