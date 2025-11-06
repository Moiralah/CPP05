/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:23:54 by huidris           #+#    #+#             */
/*   Updated: 2025/11/06 20:58:21 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		Form();
		Form(const std::string &name, const int grade, const int execute);
		Form(const Form& copy);
		Form& operator=(const Form& copy);

		~Form();

		void beSigned(const Bureaucrat &b);

		std::string getNameForm() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;

		class GradeTooHighException : public std::exception
		{
			private:
				std::string _msg;

			public:
				GradeTooHighException(const std::string &name, const int gradeSign, const int gradeExecute);
				~GradeTooHighException() throw();
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const Form &copy);

#endif
