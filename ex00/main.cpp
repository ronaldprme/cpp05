/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:06:21 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/04 16:59:52 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define GREEN "\033[38;5;46m"
#define RESET "\033[0m"

int main (void)
{
	/* Throw exception when calling constructor with grade too high */	
	try
	{
		Bureaucrat rpr("rpr", 2);
		Bureaucrat ronald;
		ronald.setName("ronald");
		ronald.setGrade(5);
		Bureaucrat ronaldpr;
		ronaldpr = ronald;
		std::cout << GREEN << "\nBureaucrat Grade ------------------ \n\n" << RESET;
		std::cout << rpr << std::endl;
		std::cout << ronald << std::endl;
		ronald.gradeDown();
		std::cout << ronald << std::endl;
		std::cout << ronaldpr << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	/* Throw exception when calling constructor with grade too low */
	try
	{
		Bureaucrat kika("kika", 130);
		std::cout << GREEN << "\nBureaucrat Grade ------------------ \n\n" << RESET;
		std::cout << kika << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	/* Throw exception when calling gradeUp */
	try
	{
		Bureaucrat gio("Gio", 1);
		
		std::cout << GREEN << "\nBureaucrat Grade ------------------ \n\n" << RESET;
		std::cout << gio << std::endl;
		gio.gradeUp();
		std::cout << gio << std::endl;
		gio.gradeUp();
		std::cout << gio << std::endl;
		gio.gradeUp();
		std::cout << gio << std::endl;
		
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	

	/* Throw exception when calling gradeDown */
	try
	{
		Bureaucrat gab("Gab", 149);
		std::cout << GREEN << "\nBureaucrat Grade ------------------ \n\n" << RESET;
		std::cout << gab << std::endl;
		gab.gradeDown();
		std::cout << gab << std::endl;
		gab.gradeDown();
		std::cout << gab << std::endl;
		gab.gradeDown();
		std::cout << gab << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}