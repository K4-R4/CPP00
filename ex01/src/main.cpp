/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:01:16 by kura              #+#    #+#             */
/*   Updated: 2023/10/16 23:21:19 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string promptForInput(std::string message) {
	std::string input;

	std::cout << message;
	std::getline(std::cin, input);
	return (input);
}


int main(void) {
	PhoneBook phonebook;
	std::string operation;
	std::string input;

	std::cout << "Enter a phonebook operation" << std::endl;
	std::cout << "Available options are ADD, SEARCH, EXIT" << std::endl;
	while (std::getline(std::cin, operation)) {
		if (operation == "ADD") {
			Contact contact;
			input = promptForInput("First name: ");
			contact.setFirstName(input);
			input = promptForInput("Last name: ");
			contact.setLastName(input);
			input = promptForInput("Nickname: ");
			contact.setNickname(input);
			input = promptForInput("Phone number: ");
			contact.setPhoneNumber(input);
			input = promptForInput("Darkest secret: ");
			contact.setDarkestSecret(input);
			if (contact.isValidContact())
				phonebook.addContact(contact);
			else
				std::cerr << "Error: Input is empty" << std::endl;
		} else if (operation == "SEARCH") {
			phonebook.printBriefContactList();
		} else if (operation == "EXIT") {
			exit(0);
		} else
			std::cerr << "Error: Invalid operation" << std::endl;
	}
	return (0);
}
