/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:06:21 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/06 16:15:59 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define GREEN "\033[38;5;46m"
#define RESET "\033[0m"
	
int main (void)
{
	/* Create a form with grade too high */
	try
	{
		/* config Form & Bureaucrat */
		Bureaucrat Bur0("Bur0", 72);
		Bureaucrat Bur1("Bur1", 100);
		Bureaucrat Bur2("Bur2", 119);
		Bureaucrat Bur3("Bur3", 119);

		// Name, GradeSign, GradeExec
		Form Form0("Form0", 139, 149);
		Form Form1("Form1", 90, 80);
		Form Form2("Form2", 50, 40);
		Form Form3("Form3", 1, 1);
		
		std::cout << GREEN << "\nBureaucrat -------------------------------------  \n" << RESET;
		std::cout << Bur0 << std::endl;
		std::cout << Bur1 << std::endl;
		std::cout << Bur2 << std::endl;
		std::cout << Bur3 << std::endl;
		
		std::cout << GREEN << "\nForm ------------------------------------------- \n" << RESET;
		std::cout << Form0 << std::endl;
		std::cout << Form1 << std::endl;
		std::cout << Form2 << std::endl;
		std::cout << Form3 << std::endl;

		
		Bur0.gradeSet(45);
		Bur1.gradeDown();
		Bur2.gradeSet(15);
		Bur3.gradeSet(10);
		Bur1.gradeSet(1);
		
		std::cout << Bur0 << std::endl;
		std::cout << Bur1 << std::endl;
		std::cout << Bur2 << std::endl;
		std::cout << Bur3 << std::endl;
		
		Bur2.gradeSet(50);
		Bur3.gradeSet(1);

		std::cout << GREEN << "\nSign -------------------------------------------  \n" << RESET;
		std::cout << Form0 << std::endl;
		std::cout << Bur0 << std::endl;
		Form0.beSigned(Bur0);
		Form0.beSigned(Bur0);
		std::cout << std::endl;
		
		std::cout << Form1 << std::endl;
		std::cout << Bur1 << std::endl;
		Form1.beSigned(Bur1);
		std::cout << std::endl;
		
		std::cout << Form2 << std::endl;
		std::cout << Bur2 << std::endl;
		Form2.beSigned(Bur2);
		std::cout << std::endl;

		std::cout << Form3 << std::endl;
		std::cout << Bur3 << std::endl;
		Form3.beSigned(Bur3);
	
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << GREEN "\n------------------------------------------------\n\n" << RESET;
	
	return (0);
}