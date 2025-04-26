/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:11:18 by micchen           #+#    #+#             */
/*   Updated: 2025/03/15 21:26:07 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
using namespace std;

int	main(int ac, char **av)
{
	PhoneBook phoneBook;
	string command;
	(void)av;
	if (ac > 1)
	{
		cout << "No args needed...." << endl;
		return 0;
	}
	while (1)
	{
		if (cin.eof())
		{
			cout << "\nEOF detected: exiting...." << endl;
			return 0;
		}
		cout << "Enter command (ADD, SEARCH, EXIT): ";
		cin >> command;
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			cout << "Exit.." << endl;
			return 0;
		}
	}
	return (0);
}
