/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:19:17 by huidris           #+#    #+#             */
/*   Updated: 2025/11/06 20:10:50 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <memory>

struct AFormPtr
{
	AForm* form;

	AFormPtr(AForm* form):
	form(form)
	{

	}

	~AFormPtr()
	{
		delete form;
	}
};

int main()
{
	{
		Intern someRandomIntern;
		AForm* rrf;

		{
			AFormPtr rf = someRandomIntern.makeForm("Robotomy Request", "Bender");
		}

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;

		// rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
		// delete rrf;

		// rrf = someRandomIntern.makeForm("Presidential Pardon", "Bender");
		// delete rrf;

		// rrf = someRandomIntern.makeForm("Shruberry Creation", "Bender");
		// delete rrf;



	}

	return 0;
}
