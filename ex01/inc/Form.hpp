/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:35:08 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/01 19:35:08 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# define DEF_TO_SIGN 1
# define DEF_TO_EXEC 1

class	Form
{
	public:
		// COPLIEN'S
		Form();
		Form(const Form &src);
		Form& operator=(const Form &src);
		~Form();

		// ADDED CONSTRUCTOR
		Form(const std::string &name, int gradeToSign, int gradeToExec);

		// GETTERS
		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getToSign() const;
		int					getToExec() const;

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

		void	beSigned(const Bureaucrat &src);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
};

std::ostream&	operator<<(std::ostream &os, const Form &src);

#endif
