/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:12:07 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/31 23:37:57 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
    this->name = name;
    this->weapon = nullptr;
}

HumanB::~HumanB()
{
    // Destructor implementation
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " has no weapon to attack with" << std::endl;
}