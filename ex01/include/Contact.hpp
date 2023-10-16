/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:03:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/10/16 22:52:02 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	const std::string &getFirstName() const;

	void setFirstName(const std::string &firstName);

	const std::string &getLastName() const;

	void setLastName(const std::string &lastName);

	const std::string &getNickname() const;

	void setNickname(const std::string &nickname);

	const std::string &getPhoneNumber() const;

	void setPhoneNumber(const std::string &phoneNumber);

	const std::string &getDarkestSecret() const;

	void setDarkestSecret(const std::string &darkestSecret);

	bool isValidContact();
};

#endif
