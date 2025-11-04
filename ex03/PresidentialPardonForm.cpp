/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 06:10:41 by huidris           #+#    #+#             */
/*   Updated: 2025/11/04 00:47:30 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("")
{
	std::cout << "Constructing Presidential Pardon Form for no known target" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "Constructing Presidential Pardon Form for target " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target)
{
	std::cout << "Presidential Pardon Form construct copy form" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "Presidential Pardon Form assigned" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destroyed" << std::endl;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() == getGradeSign())
		setSigned();
	else if (b.getGrade() > getGradeSign())
		throw GradeTooLowException();
	else
		throw GradeTooHighException(getNameForm(), getGradeSign(), getGradeExecute());
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	if (getSigned() == true && executor.getGrade() <= getGradeExecute())
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else if (getSigned() == false)
		throw (FormNotSigned());
	else
		throw (GradeExecuteNotEnough());
}

const std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

std::ostream &operator << (std::ostream &out, const PresidentialPardonForm &copy)
{
	out << copy.getNameForm() << ", need to be sign by Bureaucrat Grade " << copy.getGradeSign() << " and Execute by Grade " << copy.getGradeExecute() << std::endl;
	return out;
}
