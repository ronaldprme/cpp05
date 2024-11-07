/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:47:35 by rprocopi          #+#    #+#             */
/*   Updated: 2024/10/25 18:24:44 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/* Constructors & Destructor */
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm::AForm(copy), _target(copy._target) {}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

/* Funcions */
void ShrubberyCreationForm::beExecuted(const Bureaucrat &Bureaucrat) const
{
	std::ofstream outfile;
	outfile.open((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (outfile.fail())
	{
		std::cout << "Could not open output file" << std::endl;
		return ;
	}
	outfile << TREE;
	outfile.close();
	std::cout << Bureaucrat.getName() << " successfully created a shrubbery"<< std::endl;
}

AForm *ShrubberyCreationForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	return (form);
}
/* Getters */
std::string const &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}


/* Exeptions */
std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
	return (str << form.getName() << " form-------:signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}