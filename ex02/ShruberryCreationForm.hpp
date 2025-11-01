/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:23:54 by huidris           #+#    #+#             */
/*   Updated: 2025/11/01 10:07:19 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShruberryCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShruberryCreationForm();
		ShruberryCreationForm(const std::string &target);
		ShruberryCreationForm(const ShruberryCreationForm& copy);
		ShruberryCreationForm& operator=(const ShruberryCreationForm& copy);

		~ShruberryCreationForm();

		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const &executor)const;
		const std::string getTarget() const;
		void createFile() const;
		std::string putAsciiTree() const;

};

std::ostream &operator << (std::ostream &out, const ShruberryCreationForm &copy);

#endif
 