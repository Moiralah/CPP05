/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:19:17 by huidris           #+#    #+#             */
/*   Updated: 2025/11/04 00:27:18 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--- What if level too low to sign ---" << std::endl;
	try
	{
		Bureaucrat b;
		Form a("Borang", 15, 15);

		b.signForm(a);
	}

	catch(std::exception &error_message)
	{
		std::cerr << "Exception : " << error_message.what() << std::endl;
		std::cerr << "No form signed." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- What if level is okay ---" << std::endl;
	try
	{
		Bureaucrat b("Warganegara", 150);
		Form a("Sijil Lahir", 15, 15);

		b.increment(135);
		std::cout << a;
		std::cout << b;
		b.signForm(a);
	}

	catch(std::exception &error_message)
	{
		std::cerr << "Exception : " << error_message.what() << std::endl;
		std::cerr << "No form signed." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- What if level is too high to sign ---" << std::endl;
	try
	{
		Bureaucrat b("Raja", 1);
		Form a("Borang FIFA", 15, 15);

		std::cout << a;
		b.signForm(a);
	}

	catch(std::exception &error_message)
	{
		std::cerr << "Exception : " << error_message.what() << std::endl;
		std::cerr << "No form signed." << std::endl;
	}

	return 0;
}
