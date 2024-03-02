/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:34:08 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 14:34:17 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
: _name("DeAForm"), _isSigned(false), _gradeToSign(DEF_TO_SIGN), _gradeToExec(DEF_TO_EXEC), _target("DefaultTarget")
{
	std::cout << GRY1 "Default constructor called for AForm " CYAN << _name << RST << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _target("DefaultTarget")
{
	std::cout << GRY1 "Default parametric constructor called for AForm " CYAN;
	std::cout << _name << RST << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src)
: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec), _target("DefaultTarget")
{
	std::cout << GRY1 "Copy constructor called for AForm " CYAN << _name << RST << std::endl;
}

AForm&	AForm::operator=(const AForm &src)
{
	(void)src;
	return (*this);
}

AForm::~AForm()
{
	std::cout << GRY1 "Default constructor called for AForm " CYAN << _name << RST << std::endl;
}

const std::string&	AForm::getName() const
{
	return (_name);
}

bool				AForm::getIsSigned() const
{
	return (_isSigned);
}

int			AForm::getToSign() const
{
	return (_gradeToSign);
}

int			AForm::getToExec() const
{
	return (_gradeToExec);
}

const std::string&	AForm::getTarget() const
{
	return (_target);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return (REDD "Grade is too high ! (from AForm)" RST);
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return (REDD "Grade is too low ! (from AForm)" RST);
}

void	AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= this->getToSign())
	{
		_isSigned = true;
		std::cout << GOLD << src.getName();
		std::cout << LIME " just signed the AForm " CYAN << _name;
		std::cout << LIME " !" << std::endl;
	}
	else
	{
		std::cout << GRY1 "The grade of " GOLD << src.getGrade();
		std::cout << GRY1 " is too low to sign the AForm " CYAN << _name;
		std::cout << GRY1 ". (Need grade minimum " REDD << _gradeToExec;
		std::cout << GRY1 " for this AForm !)" << RST << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &os, const AForm &src)
{
	std::string bl;
	(src.getIsSigned() == false) ? bl = "false" : bl = "true";

	std::cout << GRY1 "AForm's name:\t\t" CYAN << src.getName() << RST << std::endl;
	std::cout << GRY1 "AForm is signed:\t\t" CYAN << bl << RST << std::endl;
	std::cout << GRY1 "AForm min. sign grade:\t" CYAN << src.getToSign() << RST << std::endl;
	std::cout << GRY1 "AForm min. exec grade:\t" CYAN << src.getToExec() << RST << std::endl;
	return (os);
}

void	AForm::setTarget(const std::string &target)
{
	_target = target;
}

void	AForm::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}
