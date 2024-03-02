/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:56:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/02 13:57:45 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTPARDONFORM_HPP
# define PRESIDENTPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm();

		void	execute(const Bureaucrat &executor) const;
};

#endif
