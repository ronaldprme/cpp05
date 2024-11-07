/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:47:35 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/02 17:55:39 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* Constructors & Destructor */
Bureaucrat::Bureaucrat(void): _name("default"), _grade(145) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}

Bureaucrat const &Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_name = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void){}

/* Setters */
void Bureaucrat::setName(std::string const &name)
{
	this->_name = name;
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

/* Getters */
std::string const &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int const &Bureaucrat::getGrade(void) const
{
	return (this->_grade);	
}

/* Functions */
void Bureaucrat::gradeUp(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void Bureaucrat::gradeDown(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

void Bureaucrat::gradeSet(int grade)
{
	this->_grade = grade;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)	
	{
		std::cout << this->_name << " cannot signs " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		if (this->getGrade() > form.getExecGrade())
		{
			throw AForm::GradeTooLowException();
		}	
		form.beExecuted(*this);
		std::cout << this->_name << " execute " << form.getName() << std::endl;
	}
	catch (std::exception &e)	
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}
/* Exceptions */
char const *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() <<", bureaucrat grade " << bureaucrat.getGrade());
}