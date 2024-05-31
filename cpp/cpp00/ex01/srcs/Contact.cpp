/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:29:03 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/01 18:17:40 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    // Constructor implementation
}

Contact::~Contact() {
    // Destructor implementation
}

void Contact::setFirstName(const std::string& firstName) {
    m_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
    m_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
    m_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    m_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
    m_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return m_firstName;
}

std::string Contact::getLastName() const {
    return m_lastName;
}

std::string Contact::getNickname() const {
    return m_nickname;
}

std::string Contact::getPhoneNumber() const {
    return m_phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return m_darkestSecret;
}
