/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:16:15 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 17:44:40 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("PPForm", 145, 137)
{
	this->target_ = "DESK";
	std::cout << "Shrubbery constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("PPForm", 145, 137), target_(target)
{
	std::cout << *this << "was made." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &base) : AForm("PPForm", 145, 137), target_(base.target_)
{
	std::cout << AForm::getName() << " shrubbery copy was made for " << this->getTarget() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &base)
{
	if (this != &base)
	{
		this->target_ = base.getTarget();
		std::cout << AForm::getName() << " shrubbery copy was made from assignment for " << this->getTarget() << std::endl;
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target_);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	target = this->getTarget() + "_shrubbery";
	std::string	shrub = "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣿⣿⡿⠟⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⡛⠛⢿⣿⡟⠛⠛⢻⡀⢸⣿⡆⣠⠟⠉⠛⣹⣿⡿⠿⢿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠋⠙⠦⠤⠻⠿⠶⠴⣆⠉⣈⣉⣀⣀⠁⠒⠚⢛⣃⣀⣤⣿⠁⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣅⡀⠉⣿⣴⠖⢈⣤⡴⠒⢰⡦⠠⡀⠈⡏⢠⣿⠟⠉⢁⣦⡀⢣⣤⣌⠉⠰⡁⢀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣁⡀⠄⠋⢀⣉⠉⠉⠻⣗⣠⠞⠁⣼⣿⡄⠀⠛⠃⠀⣴⡏⢈⡇⠀⠈⠉⢑⡀⢋⠙⠛⢀⣀⣩⡿⠿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣋⣁⣈⡻⠋⣠⠖⢸⠁⣸⣿⢷⡀⠀⠀⠀⢠⣣⠤⠀⣀⡀⠀⢸⣿⡗⠈⠀⡠⠒⠻⣿⠃⠸⣿⣷⠀⠙⢻⣤⣀⣴⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⠁⢀⣴⢀⣴⣷⣠⣿⠀⢿⣿⡀⠈⡣⠀⠀⢸⣿⢀⡴⠛⢡⠀⠀⠉⠀⠀⠰⠶⠶⠚⠁⢀⣀⡉⠛⠇⣴⡄⠢⣀⠈⢻⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⠿⠛⠓⢿⠛⠋⣁⣀⣀⣀⡀⠀⠈⠛⠿⠿⠿⠀⠀⢸⣿⢾⢀⣴⡿⠀⠀⠀⠀⣀⣤⣤⣤⣴⣾⣿⣿⢿⡿⠀⣧⡉⠒⢆⠉⠙⢿⣿⣿⣿⣿\n"
	"⣿⣿⣧⠖⠒⢚⠋⢠⣾⣆⠘⠻⢿⣿⣿⣶⢄⡀⠀⠀⠀⠀⠈⢇⢈⣿⣿⠃⠀⠀⢀⣾⣿⣿⠉⢡⠋⢈⣿⡁⡸⠁⢠⠋⢻⠂⡀⠹⠶⠶⠿⣿⣿⣿\n"
	"⣿⣿⣯⡖⠀⣱⢀⡿⠟⠛⠓⠀⠀⠹⡄⠉⣆⠀⢹⣿⣷⡄⠀⠀⠘⠿⠏⠀⠀⠀⠘⠛⠛⠁⠈⠑⠲⠾⠿⠃⠀⠰⠿⠐⠃⢰⣿⡆⠐⢦⣤⣼⣿⣿\n"
	"⣿⣿⡿⣀⣴⠟⢀⢤⣶⣾⣿⠗⠀⠀⠈⠁⠘⠓⠘⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⢀⣀⡀⠀⠀⠀⠀⣀⠤⣄⠀⠀⠙⠿⠀⠰⣄⣀⣈⢻\n"
	"⣿⡿⠋⢩⠇⣰⣧⡀⠉⠉⠁⣀⡤⠒⣢⢠⣤⢄⣀⣀⣠⣤⣤⡀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣇⠀⢹⣿⣷⣾⣿⠟⠹⡄⠈⡇⠀⢰⣦⡀⠀⣇⣀⣉⢿\n"
	"⣿⣇⣴⡿⠀⣿⠏⣀⣀⠀⣸⣿⣠⡎⠀⣸⡇⠀⢻⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣶⣿⣿⣿⣿⡄⢠⣿⣧⡇⢠⡈⠻⣷⡀⣦⠉⢻⣿\n"
	"⡟⠉⡹⣴⠀⣠⣾⡿⠃⢠⣿⣿⣿⣷⣼⣿⣿⣤⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣧⡈⠻⣦⡈⠃⢹⣦⢸⣿\n"
	"⣧⡞⠁⡇⢰⡿⢁⣴⠃⢣⣀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠐⣌⠻⡆⢰⠙⢻⣿\n"
	"⣿⣿⣀⣿⠈⠁⣾⣿⣄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢀⣿⡆⠀⢸⣄⠀⣿\n"
	"⣿⣿⣿⡿⢀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⡟⠀⡆⠻⣿⣿\n"
	"⣿⣿⣿⠀⣸⡄⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢁⣼⡇⢀⣿⣿\n"
	"⣿⣿⣿⣴⣿⣧⠀⡈⠙⠛⠛⠛⠿⠿⠿⠟⠋⠀⠀⠉⠁⠀⣀⣀⡀⠀⢀⣴⣿⡆⠀⢀⣤⡀⠀⠀⠈⠛⠿⠿⠿⠿⠿⣿⣿⠟⠁⠀⣿⣿⣧⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣧⠘⠷⣶⣶⣤⡀⠀⢠⣶⠆⢀⣤⠀⢰⣿⣿⠟⠁⠀⢸⣿⠋⠁⠀⢸⣿⣿⣷⡆⠀⢀⡄⠀⠀⠀⣀⠀⠀⣰⠀⣸⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣧⠀⢤⣌⡙⢿⣆⠈⣿⠀⢸⣿⣦⡈⠻⠃⡀⢠⣄⡈⠃⣴⣿⠀⡀⡿⠛⣁⣤⣶⠟⡀⠀⢠⡞⢁⣴⣿⠏⣰⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⢻⣿⡄⢻⣆⠸⣷⣄⡙⠿⠋⣠⠘⡧⠘⢋⣼⣦⣈⠋⢸⡏⣠⡘⠿⠋⣠⣾⡇⢠⣿⢁⣾⠟⢁⣴⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⡉⠓⠈⢿⡄⢻⡇⢠⣶⣦⣤⡄⢱⣆⠩⣠⣤⡉⢴⣶⢠⣤⣴⣶⡆⢨⡿⢀⣿⠇⠘⢁⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣤⣉⣀⠩⡄⢲⣦⣤⠑⢼⠁⠶⠌⡡⠾⠀⣿⠨⣤⣶⡶⢀⡌⢁⣨⣥⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣌⣀⡉⠡⣼⣌⠳⠖⢚⡓⠒⠾⢁⣧⠤⠉⣀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣭⣉⣉⣥⣶⣦⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
	if (this->getSignStatus() == false)
		throw(AForm::UnsignedException());
	else if (executor.getGrade() > this->getExecutionGrade())
		throw(AForm::GradeTooLowException());
	else
	{
		std::fstream	outFile;
		outFile.open(target.c_str(), std::ios::out);
		if (outFile.is_open())
		{
			outFile << shrub;
			outFile.close();
			std::cout << this->getTarget() << " has now a shrub authorized by " << executor.getName() << std::endl;
		}
		else
			std::cout << "An error occurred and the shrub could not be created!" << std::endl;
	}

	
}
