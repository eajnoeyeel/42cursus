/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:18:58 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/01 18:20:24 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>
# include <string>

class Contact {
public:
	Contact();
	~Contact();

	// Getter functions
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	// Setter functions
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setNickname(const std::string& nickname);
	void setPhoneNumber(const std::string& phoneNumber);
	void setDarkestSecret(const std::string& darkestSecret);

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_nickname;
	std::string m_phoneNumber;
	std::string m_darkestSecret;
};
