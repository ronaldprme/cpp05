/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:32:36 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/06 19:18:46 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
//Obs pode ser necessário chamar o header da classe Bureaucrat

class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;
		
	public:
		/* Constructors & Destructors */
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);
		
		/* Basic Operation */
		RobotomyRequestForm const &operator=(RobotomyRequestForm const &copy);
		
		/* Main Member Functions */
		void beExecuted(Bureaucrat const &bureaucrat) const;
	
};

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form);
