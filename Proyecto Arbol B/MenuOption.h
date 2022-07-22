/*----------------------------------------------------------------------------+
|		      UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE			              |
| 		        	ESTRUCTURA DE DATOS									      |
| AUTORES: CRISTOPHER ZAMBRANO, JOSUE FERRIN, RICARDO GRIJALVA, RICHADR ALBAN |
| FECHA: MIERCOLES 26 DE ENERO DEL 2022                                       |
| NRC: 7166                                                                   |
+-----------------------------------------------------------------------------*/
#pragma once
#include <iostream>
#include <functional>

typedef std::function<void()> Menu_Processing_Function_Ptr;

class MenuOption 
{
public:
	/**
	 * @brief Construct a new Menu Option object
	 * 
	 * @param int 
	 */
	MenuOption(const std::string, Menu_Processing_Function_Ptr);
	
	/**
	 * @brief Get the title object
	 * 
	 * @return std::string 
	 */
	std::string get_title_() { return this->title_; };
	
	/**
	 * @brief Get the fuction object
	 * 
	 * @return Menu_Processing_Function_Ptr 
	 */
	Menu_Processing_Function_Ptr get_fuction() { return this->p_processing_function_; };
private:
	const std::string title_;
	Menu_Processing_Function_Ptr p_processing_function_;
};
