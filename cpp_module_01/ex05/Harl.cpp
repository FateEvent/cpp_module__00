#include "Harl.hpp"

void    Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!\"" << std::endl;
    std::cout << std::endl;
}


void    Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "\"I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn't be asking for more!\"" << std::endl;
    std::cout << std::endl;
}


void    Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "\"I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month.\"" << std::endl;
    std::cout << std::endl;
}


void    Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "\"This is unacceptable!" << std::endl;
    std::cout << "I want to speak to the manager now.\"" << std::endl;
    std::cout << std::endl;
}


void    Harl::complain( std::string level )
{
    Harl    harl;
    void    (Harl::*e)( void );
    void    (Harl::*w)( void );
    void    (Harl::*i)( void );
    void    (Harl::*d)( void );

    e = &Harl::error;
    w = &Harl::warning;
    i = &Harl::info;
    d = &Harl::debug;
    if (level == "ERROR")
        (harl.*e)();
    else if (level == "WARNING")
        (harl.*w)();
    else if (level == "INFO")
        (harl.*i)();
    else if (level == "DEBUG")
        (harl.*d)();
    else
    {
        std::cout << "[ Invalid entry ]:" << std::endl;
        std::cout << "\"There are four levels, four damned levels!" << std::endl;
        std::cout << "It's not like you can enter anything that passes through your mind!" << std::endl;
        std::cout << "These levels are \"error\", \"warning\", \"info\" and \"debug\"!\"" << std::endl;
        std::cout << std::endl;
    }
}
