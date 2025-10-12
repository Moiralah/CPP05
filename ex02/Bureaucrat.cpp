/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 06:10:41 by huidris           #+#    #+#             */
/*   Updated: 2025/10/12 18:57:52 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
	std::cout << "Constructing " << _name << " Bureaucrat with level "<< _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException(_name, _grade);
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Constructing " << _name << " Bureaucrat with level " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat construct copy from " << other._name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat " << _name << " assigned with "<< other._name << std::endl;
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::increment(int level)
{
	if  (_grade - level < 1)
		throw GradeTooHighException(_name, _grade);
	_grade = _grade - level;
}

void Bureaucrat::decrement(int level)
{
	if  (_grade + level > 150)
		throw GradeTooLowException();
	_grade = _grade + level;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getNameForm() << std::endl;
	}
	catch (std::exception &errormsg)
	{
		std::cout << _name << " couldn't sign " << form.getNameForm() << " because " << errormsg.what() << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name, int grade)
{
	std::ostringstream oss;
	oss << "Bureaucrat " << name << " grade " << grade << " too high it is illogical";
	_msg = oss.str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low, he have no power here.";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &copy)
{
	out << copy.getName() << ", bureaucrat grade " << copy.getGrade() << "." << std::endl;
	return out;
}
