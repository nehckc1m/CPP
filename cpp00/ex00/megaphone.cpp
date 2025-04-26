/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:11:50 by micchen           #+#    #+#             */
/*   Updated: 2025/03/15 19:12:00 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int ac, char **av)
{
	int i;
	int j = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			av[j][i] = toupper(av[j][i]);
			i++;
		}
		std::cout << av[j];
		j++;
	}
	std::cout << std::endl;
	return 0;
}
