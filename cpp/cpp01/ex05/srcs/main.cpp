/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:21:43 by yeolee2           #+#    #+#             */
/*   Updated: 2024/06/01 17:27:35 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main() {
    
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return (0);
}