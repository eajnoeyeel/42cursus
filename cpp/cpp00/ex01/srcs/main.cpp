/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:23:25 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/31 02:22:49 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (1) {
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEOF detected. Exiting the program." << std::endl;
			break;
		}
		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}
		if (!std::getline(std::cin, command)) {
			std::cout << "EOF detected. Exiting the program." << std::endl;
			break;
		}
	}
	return 0;
}
