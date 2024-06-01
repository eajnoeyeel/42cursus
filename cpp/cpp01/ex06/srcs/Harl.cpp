/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:21:52 by yeolee2           #+#    #+#             */
/*   Updated: 2024/06/01 17:13:29 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl()
{
    // Constructor implementation
}

Harl::~Harl()
{
    // Destructor implementation
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int idx;
    for (idx = 0; idx < 4; idx++)
        if (level == levels[idx])
            break;

    // Fall through
    switch (idx)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
        {
            this->error();
            break ;
        }   
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}