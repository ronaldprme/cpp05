/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:40:49 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/02 12:06:16 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("default") {}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm(copy), _target(copy._target) {}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

/* Functions */
void RobotomyRequestForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	int success;
	
	/* set seed */
	srand((unsigned) time(NULL));
	success = rand() % 2;
	(void)bureaucrat;
	if (success)
		std::cout << this->_target << " has ben rototomized successfully " << std::endl;
	else 
		std::cout << this->_target << "'s robotomization faild" << std::endl;
}

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	return (str << form.getName() << " form---------:signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
