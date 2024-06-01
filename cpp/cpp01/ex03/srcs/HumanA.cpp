/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:31:56 by yeolee2           #+#    #+#             */
/*   Updated: 2024/06/01 12:34:48 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Initializer list for reference initialization
HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{   
}

HumanA::~HumanA()
{
    // Destructor implementation
}

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}