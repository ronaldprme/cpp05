/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:22:25 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/03 09:33:59 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern(void) {}

Intern const &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::makeForm(const std::string &type, const std::string &target)
{
	AForm *form;
	
	form = AForm::makeForm(type, target);
	if (!form)
		throw (AForm::InvalidFormException());
	else
		std::cout << "Intern creates form: " << form->getName() << " with target: " << form->getTarget() << std::endl;
	return (form);
}
