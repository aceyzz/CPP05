/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:54:46 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/01 18:54:46 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "colors.hpp"
# define MAX_GRADE 1
# define MIN_GRADE 150

class	Form;

class	Bureaucrat
{
	public:
		// COPLIEN'S
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat& operator=(const Bureaucrat &src);
		~Bureaucrat();

		// ADDED CONSTRUCTOR
		Bureaucrat(const std::string &name, int grade);

		// GETTERS
		const std::string	&getName() const;
		int 				getGrade() const;

		// EDITTERS
		void	incrementGrade();
		void	decrementGrade();

		// EXCEPTIONS
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// ADDED MEMBER
		void	signForm(Form &src);

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &src);

#endif
