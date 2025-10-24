/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 06:10:41 by huidris           #+#    #+#             */
/*   Updated: 2025/10/24 18:31:49 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm() : AForm("Shruberry Creation", 145, 137), _target("")
{
	std::cout << "Constructing Shruberry Creation Form for no known target" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(const std::string &target)
: AForm("Shruberry Creation Form", 145, 137), _target(target)
{
	std::cout << "Constructing Shruberry Creation Form for " << _target << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &other)
: AForm(other), _target(other._target)
{
	std::cout << "Shruberry Creation Form construct copy form" << std::endl;
}

ShruberryCreationForm &ShruberryCreationForm::operator=(const ShruberryCreationForm &other)
{
	std::cout << "Shruberry Creation Form assigned" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShruberryCreationForm::~ShruberryCreationForm()
{
	std::cout << "Shruberry Creation Form destroyed" << std::endl;
}

void ShruberryCreationForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() == 145)
		setSigned();
	else if (b.getGrade() > 145)
		throw GradeTooLowException();
	else
		throw GradeTooHighException(getNameForm(), 145, 137);
}


const std::string ShruberryCreationForm::getTarget() const
{
	return _target;
}

void ShruberryCreationForm::createFile()
{
	std::ostringstream name;
	name << _target << "_shruberry";

	std::ofstream file(name.str().c_str());
	file << putAsciiTree();
	file.close();
}

std::string ShruberryCreationForm::putAsciiTree()
{
	std::string tree;

	tree += "    O      \n";
	tree += "   0O0     \n";
	tree += "  00O00    \n";
	tree += " 000O000   \n";
	tree += "    O      \n";
	tree += "    O     \n";

	return tree;
}

std::ostream &operator << (std::ostream &out, const ShruberryCreationForm &copy)
{
	out << copy.getNameForm() << ", need to be sign by Bureaucrat Grade " << copy.getGradeSign() << " and Execute by Grade " << copy.getGradeExecute() << std::endl;
	return out;
}
