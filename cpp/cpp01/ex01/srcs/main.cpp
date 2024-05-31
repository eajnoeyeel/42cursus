/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:34:22 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/29 13:38:08 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    //FIXME: Might have to use string stream for indexing
    Zombie *horde = zombieHorde(5, "yeolee2");
    for (int i = 0; i < 5; i++)
        horde[i].announce();
    delete[] horde;
}
