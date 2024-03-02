/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:21:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 14:21:51 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("SCF_form", 145, 137)
{
	this->setTarget("SCF_target");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("SCF_form", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm(src.getName(), src.getToSign(), src.getToExec())
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() > this->getToExec())
		throw AForm::GradeTooLowException();
	
	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	outfile (filename);
	for (int i = 0; i < NB_TREES; i++)
		outfile << ASCII_TREE;
	outfile.close();
}
