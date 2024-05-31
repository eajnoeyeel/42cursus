/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:14:43 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/29 00:36:36 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// You have to determine in what case it’s better to allocate the zombies on the stack or heap.
int main() {
    // stackZombie is automatically deallocated when it goes out of scope.
    Zombie stackZombie("stackZombie");
    stackZombie.announce();

    // heapZombie is not automatically deallocated when it goes out of scope.
    Zombie* heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("randomChump");
    return 0;
}
