/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:01:43 by kura              #+#    #+#             */
/*   Updated: 2023/10/16 23:01:34 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string &Contact::getFirstName() const {
	return firstName;
}

void Contact::setFirstName(const std::string &firstName) {
	Contact::firstName = firstName;
}

const std::string &Contact::getLastName() const {
	return lastName;
}

void Contact::setLastName(const std::string &lastName) {
	Contact::lastName = lastName;
}

const std::string &Contact::getNickname() const {
	return nickname;
}

void Contact::setNickname(const std::string &nickname) {
	Contact::nickname = nickname;
}

const std::string &Contact::getPhoneNumber() const {
	return phoneNumber;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
	Contact::phoneNumber = phoneNumber;
}

const std::string &Contact::getDarkestSecret() const {
	return darkestSecret;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
	Contact::darkestSecret = darkestSecret;
}

bool Contact::isValidContact(void) {
	return (!(this->firstName.empty() || this->lastName.empty() || this->nickname.empty()
			  || this->phoneNumber.empty() || this->darkestSecret.empty()));
}