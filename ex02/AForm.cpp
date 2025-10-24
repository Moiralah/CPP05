/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 06:10:41 by huidris           #+#    #+#             */
/*   Updated: 2025/10/24 17:46:59 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("unknown"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "Constructing " << _name << " Form with level "<< _gradeSign;
	std::cout << " to sign, grade " << _gradeExecute << " to execute" << std::endl;
}

AForm::AForm(const std::string &name, const int grade, const int execute)
: _name(name), _signed(false), _gradeSign(grade), _gradeExecute(execute)
{
	std::cout << "Constructing " << _name << " Form with level "<< _gradeSign;
	std::cout << " to sign, grade " << _gradeExecute << " to execute" << std::endl;
}

AForm::AForm(const AForm &other)
: _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	std::cout << "Form construct copy from " << other._name << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Form " << _name << " assigned with "<< other._name << std::endl;
	_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() >= _gradeSign - 10 && b.getGrade() <= _gradeSign)
		setSigned();
	else if (b.getGrade() < _gradeSign - 10)
		throw (GradeTooHighException(_name, _gradeSign, _gradeExecute));
	else
		throw (GradeTooLowException());
}

std::string AForm::getNameForm() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

void AForm::setSigned()
{
	_signed = true;
}

int AForm::getGradeSign() const
{
	return _gradeSign;
}

int AForm::getGradeExecute() const
{
	return _gradeExecute;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &name, const int gradeSign, const int gradeExecute)
{
	std::ostringstream oss;
	oss << "Form too low std " << name << " grade to sign +- " << gradeSign << "; grade to execute " << gradeExecute;
	_msg = oss.str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw(){}

const char *AForm::GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low, he have no power here.";
}

std::ostream &operator << (std::ostream &out, const AForm &copy)
{
	out << copy.getNameForm() << ", need to be sign by Bureaucrat Grade " << copy.getGradeSign() << " and Execute by Grade " << copy.getGradeExecute() << std::endl;
	return out;
}
