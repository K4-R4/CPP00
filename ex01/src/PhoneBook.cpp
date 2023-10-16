/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:01:34 by kura              #+#    #+#             */
/*   Updated: 2023/10/16 23:11:08 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->idx = 0;
}

void PhoneBook::addContact(Contact contact) {
	this->contacts[this->idx] = contact;
	this->idx = (this->idx + 1) % this->MAX_CONTACT;
}

void PhoneBook::printBriefContactList(void) {
	for (size_t i = 0; i < this->MAX_CONTACT; i++) {
		if (this->contacts[i].getFirstName().empty())
			continue;
		std::cout << std::setw(this->COLUMN_WIDTH) << i << '|';
		std::cout << std::setw(this->COLUMN_WIDTH) << this->contacts[i].getFirstName() << '|';
		std::cout << std::setw(this->COLUMN_WIDTH) << this->contacts[i].getLastName() << '|';
		std::cout << std::setw(this->COLUMN_WIDTH) << this->contacts[i].getNickname() << std::endl;
	}
}

void PhoneBook::printContactDetail(const int idx) {
	if (idx < 0 || idx >= this->MAX_CONTACT) {
		std::cerr << "Error: Index out of range" << std::endl;
		return;
	}
	std::cout << this->contacts[idx].getFirstName() << std::endl;
	std::cout << this->contacts[idx].getLastName() << std::endl;
	std::cout << this->contacts[idx].getNickname() << std::endl;
	std::cout << this->contacts[idx].getPhoneNumber() << std::endl;
	std::cout << this->contacts[idx].getDarkestSecret() << std::endl;
}
