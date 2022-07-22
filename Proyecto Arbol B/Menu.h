#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include "MenuOption.h"
#include <conio.h>
#include <iostream>

class Menu
{
public:
    /**
     * @brief Construct a new Menu object
     * 
     */
    Menu() = default;

    /**
     * @brief Construct a new Menu object
     * 
     */
    Menu(std::vector<MenuOption>);

    /**
     * @brief detiene el menu actual
     */
    void detener() {
        menuCorriendo = false;
    }
    
    /**
     * @brief mostrar en pantalla
     * 
     */
    void display();

private:
    std::vector<MenuOption> menu_option_;
    HANDLE console_;
    bool menuCorriendo = true;

    void limpiar_ventana(SMALL_RECT area) {
        int x = area.Left;
        int y = area.Top;
        int width = area.Right - area.Left;
        int height = area.Bottom - area.Top;

        std::string spaces = std::string(width * height, ' ');
        CHAR_INFO* buffer = (CHAR_INFO*)calloc(spaces.size(), sizeof(CHAR_INFO));

        if (buffer == 0) {
            return;
        }

        SMALL_RECT position = {
            x,
            y,
            x + width,
            y + height
        };
        COORD buffer_size = { width, height };
        HANDLE console_handler = GetStdHandle(STD_OUTPUT_HANDLE);
        int i = 0;

        for (const char c : spaces) {
            buffer[i].Char.AsciiChar = c;
            buffer[i].Attributes = 15;
            i++;
        }

        WriteConsoleOutputA(console_handler, buffer, buffer_size, { 0, 0 }, &position);
        free(buffer);
    }
};
