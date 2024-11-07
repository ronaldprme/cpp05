/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:17:37 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/03 09:30:58 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		/* Constructors & Destructors */
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		/* Basic Operator */
		Intern const &operator=(Intern const &copy);
		
		/* Main Member Functions */
		AForm *makeForm(std::string const &type, std::string const &target);
		
};
