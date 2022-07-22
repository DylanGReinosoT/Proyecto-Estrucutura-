#include "MenuOption.h"

MenuOption::MenuOption(const std::string title, Menu_Processing_Function_Ptr fuction)
	: title_(title), p_processing_function_(fuction)
{

}