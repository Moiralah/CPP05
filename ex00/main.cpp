/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:19:17 by huidris           #+#    #+#             */
/*   Updated: 2025/09/02 12:37:34 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

	std::cout << "--- What if level too high ---" << std::endl;

	try
	{
		Bureaucrat b("Passport", 0);
		Bureaucrat c("Passport", 15);
	}

	catch (const std::exception &a)
	{
		std::cerr << "Exception : " << a.what() << std::endl;
		std::cerr << "No Bureaucrat created." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- What if level is okay ---" << std::endl;

	try
	{
		Bureaucrat b("JPJ", 15);
		Bureaucrat c("JPJ", -2);
	}

	catch (const std::exception &a)
	{
		std::cerr << "Exception : " << a.what() << std::endl;
		std::cerr << "No Bureaucrat created." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- What if we treat catch high and low differently ---" << std::endl;

	try
	{
		Bureaucrat b("IC", 15);
		Bureaucrat c("IC", -1);
	}

	catch (const Bureaucrat::GradeTooHighException &a)
	{
		std::cerr << "Exception : " << a.what() << std::endl;
		std::cerr << "No high level Bureaucrat created." << std::endl;
	}

	try
	{
		Bureaucrat d("IC", 151);
	}

	catch (const Bureaucrat::GradeTooLowException &a)
	{
		std::cerr << "Exception : " << a.what() << std::endl;
		std::cerr << "No low level Bureaucrat created." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- What if we increase / decrease the level ---" << std::endl;

	try
	{
		Bureaucrat b;
		b.increment(20);
		std::cout << "Bureaucrate " << b.getName()<< " new level will be " << b.getGrade() << std::endl;
		b.decrement(21);
		std::cout << "Bureaucrate " << b.getName()<< " new level will be " << b.getGrade() << std::endl;

	}

	catch (const std::exception &a)
	{
		std::cerr << "Exception : " << a.what() << std::endl;
		std::cerr << "No level changed" << std::endl;
	}

	// std::cout << std::endl;
	// std::cout << "--- What if there is no try/catch to catch error ---" << std::endl;

	// {
	// 	Bureaucrat b("Summons", 15);
	// 	Bureaucrat c("Summons", -2);
	// }

	return 0;
}
