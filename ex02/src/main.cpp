/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:23:05 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 14:31:12 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

inline void	nl(int nb)
{
	for (int i = 0; i < nb; i++)
		std::cout << std::endl;
}

void	debugHeader(const std::string &mess)
{
	std::cout << BLUE "######################################" << std::endl;
	std::cout << "  " << mess << std::endl;
	std::cout << "######################################" RST << std::endl;
}

int	main(void)
{
	std::cout << CLRALL;

	debugHeader("INIT BUREAUCRAT");
	Bureaucrat	john("John", 138);//test Shrubbery
	Bureaucrat	bill("Bill", 46);//test Robotomy
	Bureaucrat	kyle("kyle", 6);//test President

	nl(2);
	debugHeader("INIT FORMS");
	ShrubberyCreationForm	scf("scf_target");
	RobotomyRequestForm		rrf("rrf_target");
	PresidentialPardonForm	ppf("ppf_target");

	nl(2);
	debugHeader("TRY EXECUTE FORM WITHOUT SIGN IT");
	john.executeForm(scf);
	bill.executeForm(rrf);
	kyle.executeForm(ppf);

	nl(2);
	debugHeader("THEY SIGN IT");
	john.signForm(scf);
	bill.signForm(rrf);
	kyle.signForm(ppf);

	nl(2);
	debugHeader("TRY EXECUTE WITHOUT RIGHT LEVEL");
	john.executeForm(scf);
	bill.executeForm(rrf);
	kyle.executeForm(ppf);

	nl(2);
	debugHeader("INCREMENT GRADE FOR EXECUTION");
	john.incrementGrade();
	bill.incrementGrade();
	kyle.incrementGrade();

	nl(2);
	debugHeader("TRY TO SIGN IT AGAIN");
	john.signForm(scf);
	bill.signForm(rrf);
	kyle.signForm(ppf);

	nl(2);
	debugHeader("THEY EXECUTE THEIR FORMS");
	john.executeForm(scf);
	bill.executeForm(rrf);
	kyle.executeForm(ppf);

	nl(2);
	debugHeader("DESTRUCTORS");
	return (0);
}