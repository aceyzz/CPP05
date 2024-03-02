/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:18:45 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 16:19:51 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RRF_form", 72, 45)
{
	this->setTarget("RRF_target");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RRF_form", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: AForm(src.getName(), src.getToSign(), src.getToExec())
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() > this->getToExec())
		throw AForm::GradeTooLowException();
	
	srand(time(0));
	std::cout << BROW "* Drilling noises (brrrrrrr) *" RST << std::endl;
	if ((rand() % 2) == 0)// Simuler une probabilité de 50%
	{
		std::cout << GRNN "ROBOTOMY SUCCESSFULL ! The target " ORNG << this->getTarget();
		std::cout << GRNN " has been robotomized. (BRR BRR)" RST << std::endl;
	}
	else
	{
		std::cout << BROW "ROBOTOMY FAILED ! The target " ORNG << this->getTarget();
		std::cout << BROW " hasn't been robotomized ! (50% rate)" RST << std::endl;
	}
}
