/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:23:54 by huidris           #+#    #+#             */
/*   Updated: 2025/09/06 03:05:52 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <exception>

class Bureaucrat
{
	protected:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);

		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void increment(int);
		void decrement(int);

		class GradeTooHighException : public std::exception
		{
			private:
				std::string _msg;

			public:
				GradeTooHighException(const std::string &name, int grade);
				~GradeTooHighException() throw();
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &copy);

#endif
