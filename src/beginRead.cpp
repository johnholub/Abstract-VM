// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   beginRead.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/25 12:44:28 by yholub            #+#    #+#             //
//   Updated: 2018/10/25 12:44:29 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/avm.hpp"
#include "../inc/ValStorClass.hpp"
#include "../inc/ValFactory.hpp"

std::vector<std::string> *read_from_std()
{
	std::string str;
	std::vector<std::string> *nv;
	nv = new std::vector<std::string>;
	while (std::cin.eof() == 0)
	{
		std::getline(std::cin, str);
		if (str.find(";;") < str.length())
		{
			str.erase(str.find(";;"), str.length());
			nv->push_back(str);
			return (nv);
		}
		else if (str.find(';') < str.length())
		{
			str.erase(str.find(';'), str.length());
			nv->push_back(str);
		}
		else
			nv->push_back(str);
	}
	return (nv);
}

std::vector<std::string> *read_from_file(char *v)
{
	std::string str;
	std::vector<std::string> *nv;
	nv = new std::vector<std::string>;
	str = v;
	std::ifstream fl(str);
	if (fl.fail())
		std::cout << "Fail" << std::endl;
	while (std::getline(fl, str))
	{
		if (str.find(";;") < str.length())
		{
			str.erase(str.find(";;"), str.length());
			nv->push_back(str);
			return (nv);
		}
		else if (str.find(';') < str.length())
		{
			str.erase(str.find(';'), str.length());
			nv->push_back(str);
		}
		else
			nv->push_back(str);
	}
	fl.close();
	return (nv);
}



void	read_instuct(int c, char **v)
{
	AvmClass *cl;
	ValStorClass *sc;
	if (c == 1)
		cl = new AvmClass(read_from_std());
	else
	{
		std::ifstream fl(v[1]);
		if (fl.fail())
		{
			std::cout << "No correct file!" << std::endl;
			exit (1);
		}
		cl = new AvmClass(read_from_file(v[1]));
	}
	try
	{
		std::cout << "_____________________OUTPUT______________________\n";
		cl->checkComList();
		sc = new ValStorClass();
		sc->doOperatons(cl);
	}
	catch (AvmClass::EmptyComExep e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AvmClass::WrongComExep e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AvmClass::NoExitExep e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValStorClass::WrongTypeEx e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValStorClass::EmptyStackEx e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValStorClass::SmallStackEx e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValStorClass::WrongOerEx e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValStorClass::FalseAssertEx e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValStorClass::WrongPrintrEx e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValFactory::OverflowExep e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValFactory::UnderflowExep e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValFactory::WrongTypeExep e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ValStorClass::WrongDivZero e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::out_of_range e)
	{
		std::cout << "Very large value!" << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	delete sc;
	delete cl;
}