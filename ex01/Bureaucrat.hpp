/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:12 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/04 17:03:03 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Form;

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
		void signForm(Form &form);

		/* Exeptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

