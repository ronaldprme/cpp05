/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:36:17 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/02 17:39:28 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("default") {}
PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm(copy), _target(copy._target) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return *this;
}

void PresidentialPardonForm::beExecuted(Bureaucrat const &Bureaucrat) const
{
	(void)Bureaucrat;
	std::cout << _target << " has been pardoned by Jesus" << std::endl;
}

std::ostream & operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	return (str << form.getName() << " form------:signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
