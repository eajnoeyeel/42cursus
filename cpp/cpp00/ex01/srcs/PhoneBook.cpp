/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:18:08 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/31 02:18:26 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	m_contactCount = 0;
}

PhoneBook::~PhoneBook() {
	// Destructor implementation
}

void PhoneBook::addContact() {
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Enter the first name: ";
	std::getline(std::cin, firstName);
	if (std::cin.eof() || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nEOF reached. Aborting input." << std::endl;
		return;
	}
	while (firstName.empty()) {
		std::cout << "First name cannot be empty. Please enter the first name: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof() || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nEOF reached. Aborting input." << std::endl;
			return;
		}
	}
	m_contacts[m_contactCount % 8].setFirstName(firstName);

	std::cout << "Enter the last name: ";
	std::getline(std::cin, lastName);
	if (std::cin.eof() || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nEOF reached. Aborting input." << std::endl;
		return;
	}
	while (lastName.empty()) {
		std::cout << "Last name cannot be empty. Please enter the last name: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof() || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nEOF reached. Aborting input." << std::endl;
			return;
		}
	}
	m_contacts[m_contactCount % 8].setLastName(lastName);

	std::cout << "Enter the nickname: ";
	std::getline(std::cin, nickname);
	if (std::cin.eof() || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nEOF reached. Aborting input." << std::endl;
		return;
	}
	while (nickname.empty()) {
		std::cout << "Nickname cannot be empty. Please enter the nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof() || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nEOF reached. Aborting input." << std::endl;
			return;
		}
	}
	m_contacts[m_contactCount % 8].setNickname(nickname);

	std::cout << "Enter the phone number: ";
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof() || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nEOF reached. Aborting input." << std::endl;
		return;
	}
	while (phoneNumber.empty()) {
		std::cout << "Phone number cannot be empty. Please enter the phone number: ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof() || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nEOF reached. Aborting input." << std::endl;
			return;
		}
	}
	m_contacts[m_contactCount % 8].setPhoneNumber(phoneNumber);

	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof() || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nEOF reached. Aborting input." << std::endl;
		return;
	}
	while (darkestSecret.empty()) {
		std::cout << "Darkest secret cannot be empty. Please enter the darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof() || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nEOF reached. Aborting input." << std::endl;
			return;
		}
	}
	m_contacts[m_contactCount % 8].setDarkestSecret(darkestSecret);

	if (m_contactCount < 8)
		m_contactCount++;
}


void PhoneBook::displayContacts() {
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	// If longer than 10 characters, truncate the string and add "." at the end
	for (int i = 0; i < m_contactCount; i++) {
		std::cout << std::setw(10) << i << "|";
		if (m_contacts[i].getFirstName().length() > 10) {
			std::cout << std::setw(9) << m_contacts[i].getFirstName().substr(0, 9) << ".|";
		} else {
			std::cout << std::setw(10) << m_contacts[i].getFirstName() << "|";
		}
		if (m_contacts[i].getLastName().length() > 10) {
			std::cout << std::setw(9) << m_contacts[i].getLastName().substr(0, 9) << ".|";
		} else {
			std::cout << std::setw(10) << m_contacts[i].getLastName() << "|";
		}
		if (m_contacts[i].getNickname().length() > 10) {
			std::cout << std::setw(9) << m_contacts[i].getNickname().substr(0, 9) << "." << std::endl;
		} else {
			std::cout << std::setw(10) << m_contacts[i].getNickname() << std::endl;
		}
	}
	std::cout << "--------------------------------------------" << std::endl;
}

void PhoneBook::searchContact() {
	if (m_contactCount == 0) {
		std::cout << "No contacts to display." << std::endl;
		return;
	} else {
		displayContacts();
		std::cout << "Enter the index of the contact you'd like to see: ";
		while (1)
		{
			std::string index;
			std::getline(std::cin, index);
			if (std::cin.eof() || std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "EOF reached. Aborting input." << std::endl;
				return;
			}
			int idx = stoi(index);
			if ((-1 < idx) && (idx < m_contactCount)) {
				std::cout << "First Name: " << m_contacts[idx].getFirstName() << std::endl;
				std::cout << "Last Name: " << m_contacts[idx].getLastName() << std::endl;
				std::cout << "Nickname: " << m_contacts[idx].getNickname() << std::endl;
				std::cout << "Phone Number: " << m_contacts[idx].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << m_contacts[idx].getDarkestSecret() << std::endl;
				break;
			} else
				std::cout << "Invalid index. Please enter a valid index." << std::endl;
		}
	}
}
