#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->count = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::set_new_contact(int i)
{
	while (1)
	{
		std::string name;
		std::cout << "Enter first name: ";
		getline(std::cin, name);
		if (std::cin.eof())
			exit(0);
		if (this->contacts[i].set_first_name(name))
			break ;
	}
	while (1)
	{
		std::string lname;
		std::cout << "Enter last name: ";
		getline(std::cin, lname);
		if (std::cin.eof())
			exit(0);
		if (this->contacts[i].set_last_name(lname))
			break ;
	}
	while (1)
	{
		std::string nickname;
		std::cout << "Enter nickname: ";
		getline(std::cin, nickname);
		if (std::cin.eof())
			exit(0);
		if (this->contacts[i].set_nickname(nickname))
			break ;
	}
	while (1)
	{
		std::string number;
		std::cout << "Enter phone number: ";
		getline(std::cin, number);
		if (std::cin.eof())
			exit(0);
		if (this->contacts[i].set_phone_number(number))
			break ;
	}
	while (1)
	{
		std::string secret;
		std::cout << "Enter darkest secret: ";
		getline(std::cin, secret);
		if (std::cin.eof())
			exit(0);
		if (this->contacts[i].set_darkest_secret(secret))
			break ;
	}
	if (this->count < 8)
		this->count++;
}

void	print(std::string str)
{
	int	k;

	k = -1;
	while (++k < (int)(10 - str.length()))
		std::cout << " ";
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << str;
}

int PhoneBook::get_contacts()
{
	int j;

	this->last_display_count = 0;
	for (j = 0; j < 8; ++j)
		this->last_display_map[j] = -1;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "|  Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	int displayed = 0;
	for (j = 0; j < 8; ++j)
	{
		std::string fn = this->contacts[j].get_first_name();
		if (fn.length() == 0)
			continue;
		this->last_display_map[displayed] = j;
		++displayed;
		std::cout << "|      " << displayed << "|";
		print(fn);
		std::cout << "|";
		print(this->contacts[j].get_last_name());
		std::cout << "|";
		print(this->contacts[j].get_nickname());
		std::cout << "|";
		std::cout << std::endl;
	}
	this->last_display_count = displayed;
	return this->last_display_count;
}

int PhoneBook::get_count()
{
	return (this->count);
}

void PhoneBook::print_contact(int index)
{
	std::cout << "First name: " << this->contacts[index
		- 1].get_first_name() << std::endl;
	std::cout << "Last name: " << this->contacts[index
		- 1].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[index
		- 1].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index
		- 1].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index
		- 1].get_darkest_secret() << std::endl;
}

void PhoneBook::print_contact_by_display_index(int display_index)
{
	if (display_index < 1 || display_index > this->last_display_count)
	{
		std::cout << "Invalid index\n";
		return;
	}
	int arr_idx = this->last_display_map[display_index - 1];
	if (arr_idx < 0 || arr_idx >= 8)
	{
		std::cout << "Invalid index\n";
		return;
	}
	print_contact(arr_idx + 1);
}