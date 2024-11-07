/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:32:36 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/03 09:15:38 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm:public AForm
{
	private:
		std::string _target;
		
	public:
		/* Constructors & Destructors */
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);
		
		/* Getters */
		std::string const &getTarget(void) const;
		
		/* Basic Operation */
		RobotomyRequestForm const &operator=(RobotomyRequestForm const &copy);
		
		
		/* Main Member Functions */
		void beExecuted(Bureaucrat const &bureaucrat) const;
		static AForm *makeForm(AForm *form, std::string const &type, std::string const &target);
		
};

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif