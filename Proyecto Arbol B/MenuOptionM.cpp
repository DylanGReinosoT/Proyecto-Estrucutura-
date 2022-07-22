#include "MenuOptionM.h"

MenuOptionM::MenuOptionM(unsigned int number, const std::string title, Menu_Processing_Function_PtrM fuction)
	: number_option_(number), title_(title), p_processing_function_(fuction)
{

}