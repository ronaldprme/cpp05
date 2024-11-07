/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:09:50 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/03 09:18:40 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
	public:
		/* Constructors & Destructors */
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm(void);
		
		/* Basic Operations */
		PresidentialPardonForm const &operator=(PresidentialPardonForm const &copy);
		
		/*	Getters */
		std::string const &getTarget(void) const;
		
		/* Main functions */
		void beExecuted(Bureaucrat const &bureaucrat) const;
		static AForm *makeForm(AForm *form, std::string const &type, std::string const &target);
		
};

std::ostream &operator<<(std::ostream &str, PresidentialPardonForm const &form);

#endif