/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:53:39 by yeolee2           #+#    #+#             */
/*   Updated: 2024/06/01 12:34:35 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(const std::string& name);
        ~HumanB();

        void setWeapon(Weapon& weapon);
        void attack() const;
    
    private:
        std::string name;
        Weapon*     weapon;
};