/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:01:16 by kura              #+#    #+#             */
/*   Updated: 2023/10/20 02:08:27 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string promptForInput(std::string msg, int (*f)(int c), std::string errMsg) {
	std::string input;

	std::cout << msg;
	if (!std::getline(std::cin, input) || input.empty())
		std::cerr << "Error: Input is empty" << std::endl;
	if (f) {
		for (size_t i = 0; i < input.size(); i++) {
			if (f(input[i]))
				continue;
			std::cerr << errMsg << std::endl;
			return ("");
		}
	}
	return (input);
}

int main() {
	PhoneBook phonebook;
	std::string operation;
	std::string input;

	do {
		std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
		if (std::cin.bad()) {
			std::cerr << "Error: Input was interrupted" << std::endl;
			return (0);
		}
		std::getline(std::cin, operation);
		if (operation == "ADD") {
			Contact contact;
			input = promptForInput("First name: ", NULL, "");
			if (input.empty())
				continue;
			contact.setFirstName(input);
			input = promptForInput("Last name: ", NULL, "");
			if (input.empty())
				continue;
			contact.setLastName(input);
			input = promptForInput("Nickname: ", NULL, "");
			if (input.empty())
				continue;
			contact.setNickname(input);
			input = promptForInput("Phone number: ", isdigit, "Error: Phone number must be integers");
			if (input.empty())
				continue;
			contact.setPhoneNumber(input);
			input = promptForInput("Darkest secret: ", NULL, "");
			if (input.empty())
				continue;
			contact.setDarkestSecret(input);
			phonebook.addContact(contact);
		} else if (operation == "SEARCH") {
			phonebook.printBriefContactList();
			input = promptForInput("Index: ", NULL, "");
			try {
				phonebook.printContactDetail(stoi(input));
			} catch (const std::invalid_argument &e) {
				std::cerr << "Error: Index must be an integer" << std::endl;
			} catch (const std::out_of_range &e) {
				std::cerr << "Error: Index out of range" << std::endl;
			}
		} else if (operation == "EXIT") {
			exit(0);
		} else
			std::cerr << "Error: Invalid operation" << std::endl;
	} while (std::cin.good());
	return (0);
}
