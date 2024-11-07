/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:12 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/03 08:54:54 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		std::string 	_name;
		int		 		_grade;
	public:
		/* Constructors & Destructors */
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		/* Basic Operators */
		Bureaucrat const &operator=(Bureaucrat const &copy);

		/* Getters */
		std::string const 	&getName(void) const;
		int const 			&getGrade(void) const;

		/* Setters */
		void setName(std::string const &name);
		void setGrade(int grade);

		/* Functions */
		void gradeUp(void);
		void gradeDown(void);
		void gradeSet(int grade);
		void signForm(AForm &Form);
		void executeForm(AForm &Form);

		/* Exeptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what(void)const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif
