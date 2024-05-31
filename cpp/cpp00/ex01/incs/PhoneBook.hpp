/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:30:27 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/12 12:27:08 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();

	Contact m_contacts[8];
	int     m_contactCount;

	void	addContact();
	void	searchContact();
	void	displayContacts();
};

# endif