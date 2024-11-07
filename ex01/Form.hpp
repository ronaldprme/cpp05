/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:12 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/04 17:04:29 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		int const		_signGrade;
		int const		_execGrade;
		bool			_isSigned;
	public: 
		/* Constructors & Destructors */
		Form(void);
		Form(std::string const &name, int const &signGrade, int const &execGrade);
		Form(const Form &copy);
		~Form(void);

		/* Basic Operators */
		Form const &operator=(Form const &copy);

		/* Getters */
		std::string const 	&getName(void) const;
		int const 			&getSignGrade(void) const;
		int const 			&getExecGrade(void) const;
		bool const 			&getIsSigned(void) const;

		/* Functions */
		void beSigned(Bureaucrat &bureaucrat);
				
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

std::ostream &operator<<(std::ostream &str, Form const &form);

