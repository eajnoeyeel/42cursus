/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:07:01 by yeolee2           #+#    #+#             */
/*   Updated: 2024/06/01 12:34:22 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();
        
        void attack() const;
    
    private:
        std::string name;
        // Reference cannot be null, so it must be initialized in the constructor
        Weapon&     weapon;
};