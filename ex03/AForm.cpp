/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:47:35 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/03 10:11:18 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* Constructors & Destructor */
AForm::AForm(void): _name("default"), _signGrade(149), _execGrade(149), _isSigned(false) {}

AForm::AForm(std::string const &name, int const &signGrade, int const &execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &copy): _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _isSigned(copy._isSigned)
{
	*this = copy;
}

AForm::~AForm(void) {}

AForm const &AForm::operator=(const AForm &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

/* Getters */
std::string const &AForm::getName(void) const
{
	return (this->_name);
}

bool const &AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}	

int const &AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int const &AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

/* Functions */
void AForm::beSigned(Bureaucrat &bureaucrat)
{
	
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	else
	{	
		if (this->_isSigned == 1)
			std::cout << bureaucrat.getName() << " has already been signed " << this->_name << std::endl;	
		else {
		
			this->_isSigned = 1;
			std::cout << bureaucrat.getName() << " successfull signed " << this->_name << std::endl;
		}
	}
}
// obs validar este metodo
void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->beExecuted(executor);
	}
}	

AForm *AForm::makeForm(const std::string &type, const std::string &target)
{
	AForm *form;
	
	form = NULL;
	form = ShrubberyCreationForm::makeForm(form, type, target);
	form = RobotomyRequestForm::makeForm(form, type, target);
	form = PresidentialPardonForm::makeForm(form, type, target);
	return (form);	
}


/* Exeptions */
char const *AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm Grade is too high");
}

char const *AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm Grade is too low");
}

char const *AForm::FormNotSignedException::what(void) const throw()
{
	return ("AForm is not signed");
}

char const *AForm::FormAlreadyExecutedException::what(void) const throw()
{
	return ("AForm is already executed");
}

char const *AForm::InvalidFormException::what(void) const throw()
{
	return ("Invalid Form Request");
}
std::ostream &operator<<(std::ostream &str, AForm const &AForm)
{
	return (str << AForm.getName() << "Signed: " << AForm.getIsSigned() << ", grade signed " << AForm.getSignGrade() << ", grade execute " << AForm.getExecGrade());
}
