/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:39:18 by yeolee2           #+#    #+#             */
/*   Updated: 2024/06/01 12:34:56 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string& getType() const;
		void setType(std::string type);

	private:
		std::string	type;
};