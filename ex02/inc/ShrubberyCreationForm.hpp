/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:44:40 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 13:44:40 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# define ASCII_TREE "  ^  \n ^^^ \n^^^^^\n  |  \n\n";
# define NB_TREES 4

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm();

		void	execute(const Bureaucrat &executor) const;
};

#endif
