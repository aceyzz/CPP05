/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:06:11 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/01 18:07:27 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: _name("NoName"), _grade(150)
{
	std::cout << GRY1 "Default constructor called Bureaucrat " GOLD << _name << RST << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: _name(name)
{
	std::cout << GRY1 "Default parametric constructor called Bureaucrat " GOLD << _name << RST << std::endl;
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
		std::cout << GOLD << _name << LIME " got promoted ! He is now at grade " CYAN << _grade << LIME "." RST << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	if ((_grade) + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_grade++;
		std::cout << GOLD << _name << ORNG " got downgraded ! He is now at grade " CYAN << _grade << ORNG "." RST << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << GOLD << src.getName() << SLVR ", bureaucrat grade " CYAN << src.getGrade() << "." RST;
	return (os);
}
