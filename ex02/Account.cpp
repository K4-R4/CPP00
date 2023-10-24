/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:39:09 by kura              #+#    #+#             */
/*   Updated: 2023/10/17 13:23:28 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
		<< "total:" << Account::getTotalAmount() << ";"
		<< "deposits:" << Account::getNbDeposits() << ";"
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit),
										_nbDeposits(0), _nbWithdrawals(0) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
	Account::_nbAccounts--;
}

void Account::makeDeposit(int deposit) {
	if (deposit <= 0)
		return;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";";
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	if (this->_amount < withdrawal) {
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "withdrawal:" << withdrawal << ";";
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount() const {
	return (this->_amount);
}

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
	time_t unix_time;
	struct tm *separated_time;

	time(&unix_time);
	separated_time = localtime(&unix_time);
	std::cout << "["
		<< 1900 + separated_time->tm_year
		<< std::setfill('0')
		<< std::setw(2) << 1 + separated_time->tm_mon
		<< std::setw(2) << separated_time->tm_mday
		<< "_"
		<< std::setw(2) << separated_time->tm_hour
		<< std::setw(2) << separated_time->tm_min
		<< std::setw(2) << separated_time->tm_sec
		<< "] "
		<< std::setfill(' ');
}