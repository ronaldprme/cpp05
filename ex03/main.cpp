/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:06:21 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/07 11:33:15 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define GREEN "\033[38;5;46m"
#define RESET "\033[0m"

int main (void)
{
	/* Try to execute forms without being signed */

	/* 
		* ShrubberyCreationForm:	sign 145, 	exec 137
		* RobotomyRequestForm: 		sign 72, 	exec 45
		* PresidentialPardonForm:	sign 25, 	exec 5
	*/
	{
		try
		{
			/* Create the 3 forms and Bureaucrats */
			Intern chita;
			Bureaucrat tarzan("Tarzan", 5);
			AForm *form;
			// form = chita.makeForm("robotomy request", "Zeus");
			// delete form;
			// form = chita.makeForm("shrubbery creation", "Apolo");
			// delete form;
			// form = chita.makeForm("presidential pardon", "Atena");
			// delete form;
			/* Test some Actions with available form */
			try
			{
				std::cout << GREEN "Bureaucrat --------------------- \n" << RESET;	
				form = chita.makeForm("shrubbery creation", "Zeus");
				std::cout << *form << std::endl;
				form->beSigned(tarzan);
				std::cout << *form << std::endl;
				tarzan.executeForm(*form);
				delete form;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				delete form;
			}			
			
			try
			{
				std::cout << GREEN "\nForm--------------------- \n" << RESET;	
				form = chita.makeForm("robotomy request", "Atena");
				form->beSigned(tarzan);
				tarzan.executeForm(*form);
				delete form;
			}
					catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				delete form;
			}
			try
			{
				std::cout << GREEN "\nForm--------------------- \n" << RESET;	
				form = chita.makeForm("presidential pardon", "Dionizio");
				form->beSigned(tarzan);
				tarzan.executeForm(*form);
				delete form;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				delete form;	
			}	
			std::cout << GREEN "---------------------------------------- \n" << RESET;
		}
	   	/* Exceptions */
	    catch (const std::exception &e)
	    {
	        std::cerr << "An error occurred: " << e.what() << std::endl;
	    }
	}
	return (0);
}