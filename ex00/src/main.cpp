/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:39 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/01 18:05:43 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

void	tryDecrement(Bureaucrat *b)
{
	std::cout << GRY1 "Try to decrement the grade of bureaucrat " GOLD << b->getName() << RST << std::endl;
	try
	{
		b->decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << GRY1 "Exception caught: " << e.what() << std::endl;
	}
}

void	nl()
{
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << CLRALL;

	Bureaucrat	b1("John", 1);
	Bureaucrat	b2;

	nl();
	std::cout << GRY1 << "Printing infos with surcharded operator <<" << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	nl();
	tryIncrement(&b1);
	
	nl();
	tryDecrement(&b2);

	nl();
	tryIncrement(&b2);
	
	nl();
	tryDecrement(&b1);

	nl();
	return (0);	
}
