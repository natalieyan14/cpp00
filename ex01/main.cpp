#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook phonebook;
	int i = 0;

	while (1)
	{
		std::string command;
		std::cout << "Enter one of this following commands: ADD, SEARCH,
			EXIT" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			exit(0);
		if (command == "ADD")
		{
			phonebook.set_new_contact(i);
			i = (i + 1) % 8;
		}
		else if (command == "SEARCH")
		{
			if (phonebook.get_count() == 0)
			{
				std::cout << "You don't have any contacts!!" << std::endl;
				continue ;
			}
			int displayed = phonebook.get_contacts();
			std::string index_str;
			while (1)
			{
				std::cout << "Enter the index: ";
				std::getline(std::cin, index_str);
				if (std::cin.eof())
					exit(0);
				if (index_str.length() != 1 || index_str[0] < '1'
					|| index_str[0] > ('0' + displayed))
				{
					std::cout << "Invalid index. Please enter a number between 1 and " << displayed << "." << std::endl;
					continue ;
				}
				phonebook.print_contact_by_display_index(index_str[0] - '0');
				break ;
			}
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid input! " << command << std::endl;
	}
}