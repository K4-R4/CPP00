/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:01:34 by kura              #+#    #+#             */
/*   Updated: 2023/10/17 00:32:46 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->idx = 0;
}

void PhoneBook::addContact(Contact contact) {
	this->contacts[this->idx] = contact;
	this->idx = (this->idx + 1) % PhoneBook::MAX_CONTACT;
}

void PhoneBook::printBriefContactList() {
	std::string truncatedString;

	for (size_t i = 0; i < PhoneBook::MAX_CONTACT; i++) {
		if (this->contacts[i].getFirstName().empty())
			continue;
		std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << i << '|';
		truncatedString = PhoneBook::truncateString(this->contacts[i].getFirstName());
		std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << truncatedString << '|';
		truncatedString = PhoneBook::truncateString(this->contacts[i].getLastName());
		std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << truncatedString << '|';
		truncatedString = PhoneBook::truncateString(this->contacts[i].getNickname());
		std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << truncatedString << std::endl;
	}
}

void PhoneBook::printContactDetail(const int i) {
	if (i < 0 || i >= PhoneBook::COLUMN_WIDTH) {
		std::cerr << "Error: Index out of range" << std::endl;
		return;
	}
	std::cout << this->contacts[i].getFirstName() << std::endl;
	std::cout << this->contacts[i].getLastName() << std::endl;
	std::cout << this->contacts[i].getNickname() << std::endl;
	std::cout << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << this->contacts[i].getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncateString(std::string s) {
	if (s.size() <= PhoneBook::COLUMN_WIDTH)
		return (s);
	s = s.substr(0, PhoneBook::COLUMN_WIDTH - 1) + '.';
	return (s);
}