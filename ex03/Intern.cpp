/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 06:10:41 by huidris           #+#    #+#             */
/*   Updated: 2025/11/04 20:48:34 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string form_name, std::string form_target)
{
	std::string form[] = {"Shruberry Creation", "Robotomy Request", "Presidential Pardon"};

	int i = 0;
	while (i < 3 && form_name != form[i])
		i++;

	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new ShruberryCreationForm(form_target));
		case 1:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new RobotomyRequestForm(form_target));
		case 2:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new PresidentialPardonForm(form_target));
		default:
			std::cout << "Form does not exist. " << form_name << " form is not created." << std::endl;
			return NULL;
	}
}
