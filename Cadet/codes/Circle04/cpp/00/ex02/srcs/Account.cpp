#include "Account.hpp"
#include <iostream>
#include <ctime>
using namespace std;

int	Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int		Account::getNbAccounts() {
	return _nbAccounts;
}

int		Account::getTotalAmount() {
	return _totalAmount;
}

int		Account::getNbDeposits() {
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts << ';';
	cout << "total:" << _totalAmount << ';';
	cout << "deposits:" << _totalNbDeposits << ';';
	cout << "withdrawals" << _totalNbWithdrawals << endl;
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << "index:" << _accountIndex << ';';
	cout << "amount:" << _amount << ';';
	cout << "created" << endl;
}

Account::~Account() {
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	cout << "index:" << _accountIndex << ';';
	cout << "amount:" << _amount << ';';
	cout << "closed" << endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ';';
	cout << "p_amount:" << _amount << ';';
	cout << "deposit:" << deposit << ';';
	_amount += deposit;
	_totalAmount += deposit;
	cout << "amount:" << _amount << ';';
	_nbDeposits++;
	_totalNbDeposits++;
	cout << "nb_deposits:" << _nbDeposits <<  endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ';';
	cout << "p_amount:" << _amount << ';';
	if (checkAmount() < withdrawal) {
		cout << "withdrawal:" << "refused" << endl;
		return false;
	}
	cout << "withdrawal:" << withdrawal << ';';
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	cout << "amount:" << _amount << ';';
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	cout << "nb_withdrawals:" << _nbWithdrawals << endl;
	return true;
}

int		Account::checkAmount() const {
	return _amount;
}

void	Account::displayStatus() const {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ';';
	cout << "amount:" << _amount << ';';
	cout << "deposits:" << _nbDeposits << ';';
	cout << "withdrawals:" << _nbWithdrawals << endl;
}

void	Account::_displayTimestamp() {
	time_t	currTime;
	char	buff[16];

	buff[15] = 0;
	time(&currTime);
	strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&currTime));
	cout << '[' << buff << "] ";
}