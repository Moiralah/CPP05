/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 06:10:41 by huidris           #+#    #+#             */
/*   Updated: 2025/09/06 19:24:51 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("unknown"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "Constructing " << _name << " Form with level "<< _gradeSign;
	std::cout << " to sign, grade " << _gradeExecute << " to execute" << std::endl;
}

Form::Form(const std::string &name, const int grade, const int execute)
: _name(name), _signed(false), _gradeSign(grade), _gradeExecute(execute)
{
	std::cout << "Constructing " << _name << " Form with level "<< _gradeSign;
	std::cout << " to sign, grade " << _gradeExecute << " to execute" << std::endl;
}

Form::Form(const Form &other)
: _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	std::cout << "Form construct copy from " << other._name << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form " << _name << " assigned with "<< other._name << std::endl;
	_signed = other._signed;
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw (GradeTooLowException());
}

std::string Form::getNameForm() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeSign() const
{
	return _gradeSign;
}

int Form::getGradeExecute() const
{
	return _gradeExecute;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &name, const int gradeSign, const int gradeExecute)
{
	std::ostringstream oss;
	oss << "Form " << name << " grade to sign" << gradeSign << " grade to execute" << gradeExecute;
	_msg = oss.str();
}

Form::GradeTooHighException::~GradeTooHighException() throw(){}

const char *Form::GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low, he have no power here.";
}

std::ostream &operator << (std::ostream &out, const Form &copy)
{
	out << copy.getNameForm() << ", need to be sign by Bureoucrat Grade " << copy.getGradeSign() << " and Execute by Grade " << copy.getGradeExecute() << std::endl;
	return out;
}
