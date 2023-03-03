#include "Harl.hpp"

void Harl::complain(std::string level) {
    std::map<std::string, void (Harl::*)()>::const_iterator it = funcs_.find(level);
    if (it != funcs_.end()) {
        (this->*(it->second))();
    }
    else {
        std::cout << "Unknown complaint level: " << level << std::endl;
    }
}

std::map<std::string, void (Harl::*)()> Harl::init_funcs() {
    std::map<std::string, void (Harl::*)()> funcs;
    funcs["DEBUG"] = &Harl::debug;
    funcs["INFO"] = &Harl::info;
    funcs["WARNING"] = &Harl::warning;
    funcs["ERROR"] = &Harl::error;
    return funcs;
}


void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
		"ketchup burger. I really do!" << std::endl;
    
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
   	std::cout << "I cannot believe adding extra bacon costs more money." 
		"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." 
		"I've been coming for years whereas you started working here since last month." << std::endl;
    
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    
}

Harl::Harl()
{
	funcs_ = init_funcs();
}

Harl::~Harl()
{
}