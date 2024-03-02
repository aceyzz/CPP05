/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:42:05 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 16:42:23 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

inline void	nl(int nb)
{
	for (int i = 0; i < nb; i++)
		std::cout << std::endl;
}

void	debugHeader(const std::string &mess)
{
	std::cout << BLUE "#######################################################" << std::endl;
	std::cout << "  " << mess << std::endl;
	std::cout << "#######################################################" RST << std::endl;
}

int	main(void)
{
	std::cout << CLRALL;

	std::string	formName;
	std::string	formTarget;

	debugHeader("INIT BUREAUCRAT");
	Bureaucrat	john("John", 138);//test Shrubbery
	Bureaucrat	bill("Bill", 46);//test Robotomy
	Bureaucrat	kyle("kyle", 6);//test President

	nl(2);
	debugHeader("INIT INTERN");
	Intern		slave;

	nl(2);
	debugHeader("INTERN: MAKEFORM (INVALID VALUES)");
	formName = "invalid";
	formTarget = "invalid";
	try
	{
		slave.makeForm(formName, formTarget);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	nl(2);
	debugHeader("INTERN: MAKEFORM (EMPTY VALUES)");
	formName = "";
	formTarget = "";
	try
	{
		slave.makeForm(formName, formTarget);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	nl(2);
	debugHeader("INTERN: MAKEFORM (SHRUBBERY)");
	formName = "shrubbery creation";
	formTarget = "SCF";
	AForm*	scf = slave.makeForm(formName, formTarget);

	nl(2);
	debugHeader("INTERN: MAKEFORM (ROBOTOMY)");
	formName = "robotomy request";
	formTarget = "RRF";
	AForm*	rrf = slave.makeForm(formName, formTarget);

	nl(2);
	debugHeader("INTERN: MAKEFORM (PRESIDENTIAL)");
	formName = "presidential pardon";
	formTarget = "PPF";
	AForm*	ppf = slave.makeForm(formName, formTarget);

	nl(2);
	debugHeader("BUREAUCRATS: EXECUTEFORM (NO SIGNED)");
	john.executeForm(*scf);
	bill.executeForm(*rrf);
	kyle.executeForm(*ppf);

	nl(2);
	debugHeader("BUREAUCRATS: SIGNS IT");
	john.signForm(*scf);
	bill.signForm(*rrf);
	kyle.signForm(*ppf);

	nl(2);
	debugHeader("BUREAUCRATS: EXECUTEFORM (BAD GRADE)");
	john.executeForm(*scf);
	bill.executeForm(*rrf);
	kyle.executeForm(*ppf);

	nl(2);
	debugHeader("BUREAUCRATS: INCREMENT GRADE");
	john.incrementGrade();
	bill.incrementGrade();
	kyle.incrementGrade();

	nl(2);
	debugHeader("BUREAUCRATS: RE-SIGNS (ERROR, ALREADY SIGNED)");
	john.signForm(*scf);
	bill.signForm(*rrf);
	kyle.signForm(*ppf);

	nl(2);
	debugHeader("BUREAUCRATS: EXECUTEFORM (FROM INTERN'S FORMS)");
	john.executeForm(*scf);
	bill.executeForm(*rrf);
	kyle.executeForm(*ppf);

	nl(2);
	debugHeader("DESTRUCTORS (INTERN'S FORMS)");

	delete scf;
	delete rrf;
	delete ppf;

	nl(2);
	debugHeader("DESTRUCTORS (DEFAULT)");
	return (0);
}
