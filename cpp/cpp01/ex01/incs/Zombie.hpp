/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:16:36 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/30 17:42:51 by yeolee2          ###   ########.fr       */
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
		void setName(std::string name);

	private:
		std::string _name;
};

Zombie*	zombieHorde(int N, std::string name);
