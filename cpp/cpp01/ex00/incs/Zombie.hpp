/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:53:58 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/29 12:29:01 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

        void announce();

	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);