/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:09:50 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/01 10:04:11 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
	public:
		/* Constructors & Destructors */
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm(void);
		
		/* Basic Operations */
		PresidentialPardonForm const &operator=(PresidentialPardonForm const &copy);
		
		/* Main functions */
		void beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &str, PresidentialPardonForm const &form);
