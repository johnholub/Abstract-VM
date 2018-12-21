// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AvmClass.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/25 12:12:04 by yholub            #+#    #+#             //
//   Updated: 2018/10/25 12:12:05 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/AvmClass.hpp"
#include "../inc/avm.hpp"
#include <iostream>

AvmClass::AvmClass()
{

}

AvmClass::AvmClass(std::vector<std::string> *newCom)
{
	_commands = *newCom;
	delete newCom;
}

AvmClass AvmClass::operator=(AvmClass & rhs)
{
	_commands = rhs._commands;
	return (*this);
}

AvmClass::AvmClass(AvmClass & rhs)
{
	*this = rhs;
}

std::vector<std::string> AvmClass::getVector()
{
	return _commands;
}

AvmClass::~AvmClass()
{

}

AvmClass::WrongComExep::WrongComExep()
{

}

AvmClass::WrongComExep::WrongComExep(const WrongComExep &sec)
{
	*this = sec;
}

AvmClass::WrongComExep&	AvmClass::WrongComExep::operator=(WrongComExep const &)
{
	return *this;
}

AvmClass::WrongComExep::~WrongComExep() throw()
{

}

const char* AvmClass::WrongComExep::what() const throw()
{
	return ("Syntax error!");
}

AvmClass::EmptyComExep::EmptyComExep()
{

}

AvmClass::EmptyComExep::EmptyComExep(const EmptyComExep &sec)
{
	*this = sec;
}

AvmClass::EmptyComExep&	AvmClass::EmptyComExep::operator=(EmptyComExep const &)
{
	return *this;
}

AvmClass::EmptyComExep::~EmptyComExep() throw()
{

}

const char* AvmClass::EmptyComExep::what() const throw()
{
	return ("Operation list is empty!");
}

AvmClass::NoExitExep::NoExitExep()
{

}

AvmClass::NoExitExep::NoExitExep(const NoExitExep &sec)
{
	*this = sec;
}

AvmClass::NoExitExep&	AvmClass::NoExitExep::operator=(NoExitExep const &)
{
	return *this;
}

AvmClass::NoExitExep::~NoExitExep() throw()
{

}

const char* AvmClass::NoExitExep::what() const throw()
{
	return ("No exit command!");
}

void AvmClass::checkComList()
{
	if (_commands.size() == 1)
		throw AvmClass::EmptyComExep();
	for_each(_commands.begin(), _commands.end(), checkEachEl);
	for (int i = 0; i < static_cast<int>(_commands.size()); i++)
	{
		if (_commands[i].find("exit") < _commands[i].length())
			return ;
	}
	throw AvmClass::NoExitExep();
}
