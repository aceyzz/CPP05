/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:07:08 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/01 20:09:13 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
: _name("DeForm"), _isSigned(false), _gradeToSign(DEF_TO_SIGN), _gradeToExec(DEF_TO_EXEC)
{
	std::cout << GRY1 "Default constructor called for Form " CYAN << _name << RST << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << GRY1 "Default parametric constructor called for Form " CYAN;
	std::cout << _name << RST << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src)
: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << GRY1 "Copy constructor called for Form " CYAN << _name << RST << std::endl;
}

Form&	Form::operator=(const Form &src)
{
	(void)src;
	return (*this);
}

Form::~Form()
{
	std::cout << GRY1 "Default constructor called for Form " CYAN << _name << RST << std::endl;
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool				Form::getIsSigned() const
{
	return (_isSigned);
}

int			Form::getToSign() const
{
	return (_gradeToSign);
}

int			Form::getToExec() const
{
	return (_gradeToExec);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return (REDD "Grade is too high ! (Max 1)." RST);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return (REDD "Grade is too low ! (Min 150)." RST);
}

void	Form::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() >= _gradeToSign)
	{
		_isSigned = true;
		std::cout << GOLD << src.getName();
		std::cout << LIME " just signed the form " CYAN << _name;
		std::cout << LIME " !" << std::endl;
	}
	else
	{
		std::cout << GRY1 "The grade of " GOLD << src.getGrade();
		std::cout << GRY1 " is too low to sign the form " CYAN << _name;
		std::cout << GRY1 ". (Need grade minimum " REDD << _gradeToExec;
		std::cout << GRY1 " for this form !)" << RST << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &os, const Form &src)
{
	std::string bl;
	(src.getIsSigned() == false) ? bl = "false" : bl = "true";

	std::cout << GRY1 "Form's name:\t\t" CYAN << src.getName() << RST << std::endl;
	std::cout << GRY1 "Form is signed:\t\t" CYAN << bl << RST << std::endl;
	std::cout << GRY1 "Form min. sign grade:\t" CYAN << src.getToSign() << RST << std::endl;
	std::cout << GRY1 "Form min. exec grade:\t" CYAN << src.getToExec() << RST << std::endl;
	return (os);
}
