/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:10:35 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/01 20:12:29 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

inline void	nl()
{
	std::cout << std::endl;
}

void	tryIncrement(Bureaucrat *b)
{
	std::cout << GRY1 "Try to increment the grade of bureaucrat " GOLD << b->getName() << RST << std::endl;
	try
	{
		b->incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << GRY1 "Exception caught: " << e.what() << std::endl;
	}
}

void	tryCreate(void)
{
	std::cout << GRY1 << "## FORM GRADE TO SIGN = 160." << std::endl;
	try
	{
		Form		test("Invalid1", 160, 1);
	}
	catch (const std::exception& e)
	{
		std::cout << GRY1 "Exception caught: " << e.what() << std::endl;
	}

	nl();
	std::cout << GRY1 << "## FORM GRADE TO EXEC = 0." << std::endl;
	try
	{
		Form		test("Invalid2", 1, 0);
	}
	catch (const std::exception& e)
	{
		std::cout << GRY1 "Exception caught: " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << CLRALL;

	Bureaucrat	b1("John", 2);
	Form		f1("Contract", 1, 1);

	nl();
	tryCreate();

	nl();
	std::cout << GRY1 << "## DEBUG BUREAUCRAT <<" << std::endl;
	std::cout << b1 << std::endl;

	nl();
	std::cout << GRY1 << "## DEBUG FORM <<" << std::endl;
	std::cout << f1 << std::endl;

	std::cout << GRY1 << "## TRIES TO SIGN" << std::endl;
	b1.signForm(f1);

	nl();
	std::cout << GRY1 << "## DEBUG BUREAUCRAT <<" << std::endl;
	std::cout << b1 << std::endl;

	nl();
	std::cout << GRY1 << "## DEBUG FORM <<" << std::endl;
	std::cout << f1 << std::endl;

	std::cout << GRY1 << "## PROMOTION" << std::endl;
	tryIncrement(&b1);
	
	nl();
	std::cout << GRY1 << "## TRIES TO SIGN" << std::endl;
	b1.signForm(f1);
	
	nl();
	std::cout << GRY1 << "## DEBUG BUREAUCRAT <<" << std::endl;
	std::cout << b1 << std::endl;

	nl();
	std::cout << GRY1 << "## DEBUG FORM <<" << std::endl;
	std::cout << f1 << std::endl;

	nl();
	return (0);	
}
