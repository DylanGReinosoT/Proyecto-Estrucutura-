#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include "MenuOptionM.h"
#include <conio.h>
#include <iostream>

constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_ENTER = 13;
constexpr auto KEY_ESCAPE = 27;


class MenuM
{
public:

    MenuM() = default;

    MenuM(std::vector<MenuOptionM>);

    void navigation();


    void display(size_t);

private:
    std::vector<MenuOptionM> menu_option_;
    HANDLE console_;
};