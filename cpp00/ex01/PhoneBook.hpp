/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:58:50 by micchen           #+#    #+#             */
/*   Updated: 2025/03/15 21:18:43 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

class Contact {
	private:
		string _firstName;
		string _lastName;
		string _nickname;
		string _phoneNumber;
		string _darkSecret;

	public:
		void setContact();
		void displayContact() const;
		void displayInfo(int _index) const;
};

void	Contact::setContact()
{

    do {
        std::cout << "First Name: ";
        cin >> _firstName;
        if (cin.eof())
		return;
        if (_firstName.empty()) {
            cout << "First name cannot be empty. Please try again." << endl;
        }
    } while (_firstName.empty());

    do {
        cout << "Last Name: ";
        cin >> _lastName;
       if (cin.eof())
		return;
        if (_lastName.empty()) {
            cout << "Last name cannot be empty. Please try again." << endl;
        }
    } while (_lastName.empty());

    do {
        cout << "Nickname: ";
        cin >> _nickname;
        if (cin.eof())
		return;
        if (_nickname.empty()) {
            cout << "Nickname cannot be empty. Please try again." << endl;
        }
    } while (_nickname.empty());

    do {
        cout << "Phone Number: ";
        cin >> _phoneNumber;
        if (cin.eof())
		return;
        if (_phoneNumber.empty()) {
            cout << "Phone number cannot be empty. Please try again." << endl;
        }
    } while (_phoneNumber.empty());

    do {
    	cout << "This contact's dark secret: ";
    	cin >> _darkSecret;
    	if (cin.eof())
		return;
        if (_darkSecret.empty()) {
            cout << "Darkest secret cannot be empty. Please try again." << endl;
        }
    } while (_darkSecret.empty());
}

void	Contact::displayContact() const
{
	cout << "First Name: " << _firstName << "\n"
	     << "Last Name: " << _lastName << "\n"
	     << "Nickname: " << _nickname << "\n"
	     << "Phone Number: " << _phoneNumber << "\n"
	     << "Dark secret: " << _darkSecret << "\n";
}

void	Contact::displayInfo(int _index) const
{
	cout << setw(10) << _index + 1 << "|"
	     << setw(10) << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << "|"
	     << setw(10) << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << "|"
             << setw(10) << (_nickname.length() > 10 ? _nickname.substr(0, 9) + "." : _nickname) << "|"
             << endl;
}

class PhoneBook {
	private:
		Contact _contacts[8];
		int _index;
		int _totalContacts;

	public:
		PhoneBook();
		void addContact();
		void searchContact() const;
};

PhoneBook::PhoneBook() : _index(0), _totalContacts(0) {}

void	PhoneBook::addContact()
{
	_contacts[_index].setContact();
	_index = (_index + 1) % 8;
	if (_totalContacts < 8)
		_totalContacts++;
}

void PhoneBook::searchContact() const 
{
    if (_totalContacts == 0) {
        cout << "U have no friends..... yet." << endl;
        return;
    }
    cout << setw(10) << "Index" << "|"
              << setw(10) << "First Name" << "|"
              << setw(10) << "Last Name" << "|"
              << setw(10) << "Nickname" << "|" << endl;
    for (int i = 0; i < _totalContacts; i++) {
        _contacts[i].displayInfo(i);
    }
    cout << "Enter contact index: ";
    int searchIndex;
    cin >> searchIndex;
    cin.ignore();
    if (cin.eof())
        return;
    if (cin.fail() ||searchIndex < 0 || searchIndex - 1 >= _totalContacts) {
        cout << "Invalid index." << endl;
        cin.clear();
        cin.ignore();
        return;
    }
    else
        _contacts[searchIndex - 1].displayContact();
}

#endif
