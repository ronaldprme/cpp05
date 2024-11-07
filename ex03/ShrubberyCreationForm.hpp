/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:12 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/03 09:16:00 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

#define TREE "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n"
#define TREE1 "     *\n    ***\n   *****\n  *******\n *********\n***********\n    |||\n    |||"
class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
		
	public: 
		/* Constructors & Destructors */
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm(void);

		/* Getters */
		std::string const &getTarget(void) const;
		
		/* Basic Operators */
		ShrubberyCreationForm const &operator=(ShrubberyCreationForm const &copy);
		
		/* Functions */
		void beExecuted(Bureaucrat const &bureaucrat) const; // Implementação da função virtual pura
		static AForm *makeForm(AForm *form, std::string const &type, std::string const &target);
};

std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm const &form);

#endif