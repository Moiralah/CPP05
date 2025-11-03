/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:19:17 by huidris           #+#    #+#             */
/*   Updated: 2025/11/04 00:55:22 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	std::cout << "--- Testing Shruberry Creation Form ---" << std::endl;
	try
	{
		Bureaucrat b("Ali", 145);
		Bureaucrat executive("Alia", 137);
		ShruberryCreationForm a("Borang");

		b.signForm(a);
		executive.executeForm(a);
	}
	catch(std::exception &error_message)
	{
		std::cerr << "Exception : " << error_message.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Testing Robotomy Request Form ---" << std::endl;
	try
	{
		Bureaucrat b("Yaya", 72);
		Bureaucrat executive("Boboiboy", 45);
		Bureaucrat executive2("Cika", 55);
		RobotomyRequestForm a("Robocop");

		b.signForm(a);
		executive.executeForm(a);
		executive2.executeForm(a);
	}
	catch(std::exception &error_message)
	{
		std::cerr << "Exception : " << error_message.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Testing Presidential Pardon ---" << std::endl;
	try
	{
		Bureaucrat b("Anwar", 25);
		Bureaucrat executive("Rafizi", 5);
		PresidentialPardonForm a("Najib");

		b.signForm(a);
		executive.executeForm(a);
	}
	catch(std::exception &error_message)
	{
		std::cerr << "Exception : " << error_message.what() << std::endl;
	}

	return 0;
}
