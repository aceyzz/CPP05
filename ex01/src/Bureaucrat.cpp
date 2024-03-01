/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:09:38 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/01 20:11:30 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
: _name("NoName"), _grade(150)
{
	std::cout << GRY1 "Default constructor called Bureaucrat " GOLD;
	std::cout << _name << RST << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: _name(name)
{
	std::cout << GRY1 "Default parametric constructor called Bureaucrat " GOLD;
	std::cout << _name << RST << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << GRY1 "Copy constructor called Bureaucrat." RST << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GRY1 "Destructor called Bureaucrat " GOLD << _name << RST << std::endl;
}

const std::string&	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return (REDD "Grade is too high ! (Max 1)." RST);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return (REDD "Grade is too low ! (Min 150)." RST);
}

void	Bureaucrat::incrementGrade()
{
	if ((_grade) - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		_grade--;
		std::cout << GOLD << _name << GRNN " got promoted ! He is now at grade " CYAN;
		std::cout << _grade << LIME "." RST << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	if ((_grade) + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_grade++;
		std::cout << GOLD << _name << ORNG " got downgraded ! He is now at grade " CYAN;
		std::cout << _grade << ORNG "." RST << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << GOLD << src.getName() << ", bureaucrat grade " CYAN << src.getGrade() << GOLD "." RST;
	return (os);
}

void	Bureaucrat::signForm(Form &src)
{
	if (src.getIsSigned() == true)
	{
		std::cout << GRY1 "Bureaucrat " GOLD << _name;
		std::cout << GRY1 " couldn't sign Form " CYAN << src.getName();
		std::cout << GRY1 " because it is already signed.";
		return ;
	}
	else
	{
		if (_grade <= src.getToSign())
			src.beSigned(*this);
		else
		{
			std::cout << GRY1 "The grade of " GOLD << _name;
			std::cout << GRY1 " is too low to sign the form " CYAN << src.getName() << std::endl;
			std::cout << GRY1 "(Need grade minimum " REDD << src.getToSign();
			std::cout << GRY1 " for this form !)" << RST << std::endl;
		}
	}
}
