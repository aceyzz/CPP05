/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:06:44 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 14:06:52 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# define DEF_TO_SIGN 1
# define DEF_TO_EXEC 1

class	AForm
{
	public:
		// COPLIEN'S
		AForm();
		AForm(const AForm &src);
		AForm& operator=(const AForm &src);
		virtual ~AForm();

		// ADDED CONSTRUCTOR
		AForm(const std::string &name, int gradeToSign, int gradeToExec);

		// GETTERS
		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getToSign() const;
		int					getToExec() const;
		const std::string	&getTarget() const;

		// SETTERS
		void	setTarget(const std::string &target);
		void	setIsSigned(bool isSigned);

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
		virtual void	execute(const Bureaucrat &executor) const = 0;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
		std::string			_target;
};

std::ostream&	operator<<(std::ostream &os, const AForm &src);

#endif
