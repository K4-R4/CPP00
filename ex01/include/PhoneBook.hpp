/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:03:57 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/17 00:29:05 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
private:
	static const int MAX_CONTACT = 8;
	static const int COLUMN_WIDTH = 10;
	int idx;
	Contact contacts[MAX_CONTACT];

	static std::string truncateString(std::string s);
public:
	PhoneBook();

	void addContact(Contact contact);

	void printBriefContactList();

	void printContactDetail(int idx);
};

#endif
