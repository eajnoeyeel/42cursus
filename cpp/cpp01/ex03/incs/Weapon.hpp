/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:39:18 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/30 22:42:01 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>

class Weapon {
	public:
		Weapon();
		Weapon(std::string str);
		~Weapon();

		const std::string &getType();
		void setType(int );

	private:
		std::string type;
}
