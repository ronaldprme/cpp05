/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:47:35 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/04 17:44:50 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructors & Destructor */
Form::Form(void): _name("default"), _signGrade(1), _execGrade(1), _isSigned(false) {}

Form::Form(std::string const &name, int const &signGrade, int const &execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(Form const &copy): _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _isSigned(copy._isSigned)
{
	*this = copy;
}

Form::~Form(void){}

Form const &Form::operator=(const Form &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

/* Getters */
std::string const &Form::getName(void) const
{
	return (this->_name);
}

bool const &Form::getIsSigned(void) const
{
	return (this->_isSigned);
}	

int const &Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int const &Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

/* Functions */
void Form::beSigned(Bureaucrat &bureaucrat)
{
	
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
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
/* Exeptions */
char const *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form Grade is too high");
}

char const *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Grade is too low");
}

std::ostream &operator<<(std::ostream &str, Form const &Form)
{
	return (str << Form.getName() << ", grade asign " << Form.getSignGrade() << ", grade execute " << Form.getExecGrade());
}
