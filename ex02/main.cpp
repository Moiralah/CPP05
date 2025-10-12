/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:19:17 by huidris           #+#    #+#             */
/*   Updated: 2025/10/12 18:58:02 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	{
		Bureaucrat b;
		Form a("Borang", 15, 15);

		b.signForm(a);
		b.increment(135);
	}

	{
		Bureaucrat b("Warganegara", 150);
		Form a("Borang", 15, 15);

		b.increment(135);
		std::cout << a;
		std::cout << b;
		b.signForm(a);
	}

	{
		Bureaucrat b("Raja", 1);
		Form a("Borang FIFA", 15, 15);

		std::cout << a;
		b.signForm(a);
	}

	return 0;
}
