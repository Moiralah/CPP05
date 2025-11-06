/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:23:54 by huidris           #+#    #+#             */
/*   Updated: 2025/11/06 19:31:50 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		AForm();
		AForm(const std::string &name, const int grade, const int execute);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);

		virtual ~AForm();

		virtual void beSigned(const Bureaucrat &b) = 0;
		virtual void execute(Bureaucrat const &executor) const = 0;

		std::string getNameForm() const;
		bool getSigned() const;
		void setSigned();
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

		class FormNotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeExecuteNotEnough : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const AForm &copy);

#endif
