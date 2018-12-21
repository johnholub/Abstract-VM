// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ParseInput.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/26 13:18:50 by yholub            #+#    #+#             //
//   Updated: 2018/10/26 13:18:50 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/avm.hpp"
#include <iomanip>
#include <string>

int	flSize(const char *str)
{
	int i = 0;
	int p = 0;

	while(str[i] != '\0' && str[i] != ')')
	{
		if (str[i] == '.' || str[i] == ',')
			p++;
		else if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
			throw AvmClass::WrongComExep();
		i++;
	}
	if (p > 1)
		throw AvmClass::WrongComExep();
	return (i);
}

int checkTypeVal(std::string s)
{
	int i = 0;
	unsigned long len;
	std::string types[5] = {"int8", "int16", "int32", "float", "double"};
	while (i < 5)
	{
		if (s.find(types[i]) < s.length())
		{
			len = s.find(types[i]) + types[i].length();
			if (s.c_str()[len] == '(')
			{
				len++;
				if (i == 3 || i == 4)
					len += flSize(s.c_str() + len);
				else
					if (std::isdigit(s.c_str()[len]) || s.c_str()[len] == '+' || s.c_str()[len] == '-')
						len += std::to_string(std::stoll(s.c_str() + len)).length();
				if(s.c_str()[len] != ')')
					throw AvmClass::WrongComExep();
			}
			return (static_cast<int>(len - s.find(types[i])) + 1);
		}
		i++;
	}
	throw AvmClass::WrongComExep();
}

int wsLen(std::string s)
{
	int i = 0;
	int res = 0;

	while (i <= static_cast<int>((s.length())))
	{
		if (s.c_str()[i] == ' ')
			res++;
		i++;
	}
	return (res);
}

void checkEachEl(std::string s)
{
	std::string comands[11] = {"pop", "push", "dump", "assert", "add", "sub", "mul", "div", "mod", "print", "exit"};
	int i = 0;
	int flen;
	if (wsLen(s) == static_cast<int>(s.length()))
		return ;
	while (i < 11)
	{
		if (s.find(comands[i]) < s.length())
		{
			flen = wsLen(s) + static_cast<int>(comands[i].length());
			if (i == 1 || i == 3)
				flen += checkTypeVal(s);
			if (flen == static_cast<int>(s.length()))
				return ;
			else
				throw AvmClass::WrongComExep();
		}
		i++;
	}
	throw AvmClass::WrongComExep();
}
