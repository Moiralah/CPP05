/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:23:54 by huidris           #+#    #+#             */
/*   Updated: 2025/10/13 02:46:37 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORMFORM_HPP

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

		const std::string getTarget() const;
		void createFile();
		std::string putAsciiTree();

};

std::ostream &operator << (std::ostream &out, const ShruberryCreationForm &copy);

#endif
