/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 06:10:41 by huidris           #+#    #+#             */
/*   Updated: 2025/11/01 23:07:37 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("")
{
	std::cout << "Constructing Robotomy Request Form for no known target" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "Constructing Robotomy Request Form for target " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target)
{
	std::cout << "Robotomy Request Form construct copy form" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Robotomy Request Form assigned" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destroyed" << std::endl;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() == getGradeSign())
		setSigned();
	else if (b.getGrade() > getGradeSign())
		throw GradeTooLowException();
	else
		throw GradeTooHighException(getNameForm(), getGradeSign(), getGradeExecute());
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if (getSigned() == true && executor.getGrade() <= getGradeExecute())
	{
		std::cout << "Grrrrr Grrrrr Grrrrr" << std::endl;
		std::srand(std::time(NULL));
		if (std::rand() % 2)
			std::cout << getTarget() << " has been robotomized successfully." << std::endl;
		else
			throw std::runtime_error("Robotomy failed. Please re-run the process.");
	}
	else if (getSigned() == false)
		throw (FormNotSigned());
	else
		throw (GradeExecuteNotEnough());
}

const std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

std::ostream &operator << (std::ostream &out, const RobotomyRequestForm &copy)
{
	out << copy.getNameForm() << ", need to be sign by Bureaucrat Grade " << copy.getGradeSign() << " and Execute by Grade " << copy.getGradeExecute() << std::endl;
	return out;
}
