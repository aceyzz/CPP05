/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:00:55 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 16:13:11 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <cctype>

typedef struct s_formList
{
	std::string	name;
	AForm*		form;
}				t_formList;


Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern& Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

Intern::~Intern()
{
}

const char*	Intern::NoValidFormException::what() const throw()
{
	return (REDD "Invalid Form ! (from Intern)" RST);
}

AForm*	Intern::makeForm(std::string &formName, std::string &formTarget)
{
	AForm*	result = NULL;

	for (uint i = 0; i < formName.length(); i++)// Insensible a la casse, on n'est pas des sauvages
		formName[i] = tolower(formName[i]);

	std::string	list[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int			index = -1;

	for (int i = 0; i < 3; i++)
	{
		if (list[i] == formName)
			index = i;
	}

	switch (index)
	{
		case(0):
			result = new ShrubberyCreationForm(formTarget);
			break;
		case(1):
			result = new RobotomyRequestForm(formTarget);
			break ;
		case(2):
			result = new PresidentialPardonForm(formTarget);
			break ;
		default:
			throw NoValidFormException();
			break ;
	}
	
	std::cout << YLLW "Intern creates " CYAN << list[index];
	std::cout << YLLW " with target " CYAN << formTarget;
	std::cout << std::endl;
	
	return (result);
}
