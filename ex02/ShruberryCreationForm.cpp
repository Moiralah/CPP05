/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 06:10:41 by huidris           #+#    #+#             */
/*   Updated: 2025/10/13 02:43:39 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm() : AForm(), _target("")
{
	std::cout << "Constructing Shruberry Creation Form" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(const std::string &target)
: AForm(), _target(target)
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

const std::string ShruberryCreationForm::getTarget() const
{
	return _target;
}

void ShruberryCreationForm::createFile()
{
	std::ofstream file(_target + "_shruberry");
	file << putAsciiTree();
}

std::string ShruberryCreationForm::putAsciiTree()
{
	std::string tree;

	tree < "    O      \n";
	tree < "   0O0     \n";
	tree < "  00O00    \n";
	tree < " 000O000   \n";
	tree < "    O      \n";
	tree < "    O     \n";

	return tree;
}

std::ostream &operator << (std::ostream &out, const ShruberryCreationForm &copy)
{
	out << copy.getNameForm() << ", need to be sign by Bureaucrat Grade " << copy.getGradeSign() << " and Execute by Grade " << copy.getGradeExecute() << std::endl;
	return out;
}
