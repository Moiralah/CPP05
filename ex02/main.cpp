/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:19:17 by huidris           #+#    #+#             */
/*   Updated: 2025/11/01 23:43:20 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	{
		Bureaucrat b("Ali", 145);
		Bureaucrat executive("Alia", 137);
		ShruberryCreationForm a("Borang");

		b.signForm(a);
		executive.executeForm(a);
	}

	{
		Bureaucrat b("Yaya", 72);
		Bureaucrat executive("Boboiboy", 45);
		Bureaucrat executive2("Cika", 55);
		RobotomyRequestForm a("Robocop");

		b.signForm(a);
		executive.executeForm(a);
		executive2.executeForm(a);
	}

	{
		Bureaucrat b("Anwar", 25);
		Bureaucrat executive("Rafizi", 5);
		PresidentialPardonForm a("Najib");

		b.signForm(a);
		executive.executeForm(a);
	}

	return 0;
}
