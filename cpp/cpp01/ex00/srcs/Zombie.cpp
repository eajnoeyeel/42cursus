/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:53:42 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/29 12:09:42 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	this->_name = "default";
}

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " is dead." << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

