/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:03:57 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/16 22:42:58 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	static const int MAX_CONTACT = 8;
	static const int COLUMN_WIDTH = 10;
	int idx;
	Contact contacts[MAX_CONTACT];
public:
	PhoneBook(void);

	void addContact(Contact contact);
	void printBriefContactList(void);
	void printContactDetail(int idx);
};

#endif
