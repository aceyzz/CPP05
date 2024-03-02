/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:32:38 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 14:33:05 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PPF_form", 25, 5)
{
	this->setTarget("PPF_target");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PPF_form", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
: AForm(src.getName(), src.getToSign(), src.getToExec())
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() > this->getToExec())
		throw AForm::GradeTooLowException();

	std::cout << PEAC "The target " PINK << this->getTarget();
	std::cout << PEAC " has been pardoned by Zaphod Beeblebrox." RST << std::endl;
}
