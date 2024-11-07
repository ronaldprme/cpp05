/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:06:21 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/06 16:39:18 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
			Bureaucrat zeus("Zeus", 45);
			Bureaucrat apolo("Apolo", 45);
			Bureaucrat atena("Atena", 5);

			ShrubberyCreationForm shrubbery("Monte Olimpo");
			RobotomyRequestForm robotomy("Hermes");
			PresidentialPardonForm pardon("Judas");
			
			std::cout << GREEN "Bureaucrat --------------------- \n" << RESET;	
			std::cout << zeus << std::endl;
			std::cout << apolo << std::endl;
			std::cout << atena << std::endl;
			
			std::cout << GREEN "\nForm--------------------- \n" << RESET;	
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
					
			std::cout << GREEN "\nForm executed Zeus--------------------- \n" << RESET;
			std::cout << zeus << std::endl;
			zeus.executeForm(shrubbery);
			std::cout << shrubbery << std::endl;
		
			std::cout << GREEN "\nForm executed Apolo--------------------- \n" << RESET;
			std::cout << apolo << std::endl;
			apolo.executeForm(robotomy);
			std::cout << robotomy << std::endl;

			std::cout << GREEN "\nForm executed Atena--------------------- \n" << RESET;
			std::cout << atena << std::endl;
			atena.executeForm(pardon);
			std::cout << pardon << std::endl;
			
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