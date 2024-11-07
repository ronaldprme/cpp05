/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:12 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/03 09:50:24 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		int const			_signGrade;
		int const			_execGrade;
		bool				_isSigned;
	public: 
		/* Constructors & Destructors */
		AForm(void);
		AForm(std::string const &name, int const &signGrade, int const &execGrade);
		AForm(const AForm &copy);
		virtual ~AForm(void);

		/* Basic Operators */
		AForm const &operator=(AForm const &copy);

		/* Getters */
		std::string const 			&getName(void) const;
		int const 					&getSignGrade(void) const;
		int const 					&getExecGrade(void) const;
		bool const 					&getIsSigned(void) const;
		virtual std::string const 	&getTarget(void) const = 0;
	
		/* Functions */
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void beExecuted(Bureaucrat const &bureaucrat) const = 0;
		static AForm *makeForm(std::string const &type, std::string const &target);
		

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
		
		class FormAlreadyExecutedException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};

		class InvalidFormException: public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};


};
std::ostream &operator<<(std::ostream &str, AForm const &AForm);

#endif // AFORM_HPP

