// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ValStorClass.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/01 14:06:02 by yholub            #+#    #+#             //
//   Updated: 2018/11/01 14:06:02 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/ValStorClass.hpp"
#include "../inc/ValFactory.hpp"
#include "../inc/avm.hpp"
#include <vector>
#include <algorithm>

void delEachEl(IOperand const * el)
{
	delete el;
}

ValStorClass::ValStorClass()
{
	_fac = new ValFactory();
}

ValStorClass::ValStorClass(MutantStack<IOperand const *> vec)
{
	_vec = vec;
}

ValStorClass::ValStorClass(ValStorClass & src)
{
	*this = src;
}

ValStorClass ValStorClass::operator=(ValStorClass &src)
{
	_vec = src._vec;
	return (*this);
}

ValStorClass::~ValStorClass()
{
	for_each(_vec.begin(), _vec.end(), delEachEl);
	delete _fac;
}

void	ValStorClass::doOperatons(AvmClass *ops)
{
	int i = 0;

	while (i < static_cast<int>(ops->getVector().size()))
	{
		if (wsLen(ops->getVector()[i]) == static_cast<int>(ops->getVector()[i].size()))
			i += 0;
		else if (ops->getVector()[i].find("pop") < ops->getVector()[i].length())
			pop();
		else if (ops->getVector()[i].find("push") < ops->getVector()[i].length())
			push(ops->getVector()[i]);
		else if (ops->getVector()[i].find("dump") < ops->getVector()[i].length())
			dump();
		else if (ops->getVector()[i].find("assert") < ops->getVector()[i].length())
			assert(ops->getVector()[i]);
		else if (ops->getVector()[i].find("print") < ops->getVector()[i].length())
			print();
		else if (ops->getVector()[i].find("add") < ops->getVector()[i].length())
			add();
		else if (ops->getVector()[i].find("sub") < ops->getVector()[i].length())
			sub();
		else if (ops->getVector()[i].find("mul") < ops->getVector()[i].length())
			mul();
		else if (ops->getVector()[i].find("div") < ops->getVector()[i].length())
			div();
		else if (ops->getVector()[i].find("mod") < ops->getVector()[i].length())
			mod();
		else if (ops->getVector()[i].find("exit") < ops->getVector()[i].length())
			break ;
		else
			throw ValStorClass::WrongOerEx();
		i++;
	}
}

void	ValStorClass::pop()
{
	if (_vec.size() < 1)
		throw ValStorClass::EmptyStackEx();
	delete _vec.top();
	_vec.pop();
}

void	ValStorClass::push(std::string val)
{
	if (val.find("int8") < val.size())
		_vec.push(_fac->createOperand(Int8, val.c_str() + (val.find("int8") + 5)));
	else if (val.find("int16") < val.size())
		_vec.push(_fac->createOperand(Int16, val.c_str() + (val.find("int16") + 6)));
	else if (val.find("int32") < val.size())
		_vec.push(_fac->createOperand(Int32, val.c_str() + (val.find("int32") + 6)));
	else if (val.find("float") < val.size())
		_vec.push(_fac->createOperand(Float, val.c_str() + (val.find("float") + 6)));
	else if (val.find("double") < val.size())
		_vec.push(_fac->createOperand(Double, val.c_str() + (val.find("double") + 7)));
	else
		throw ValStorClass::WrongTypeEx();
}

void	ValStorClass::dump()
{
	MutantStack<IOperand const *>::iterator it;
	int i;

	i = static_cast<int>(_vec.size());
	if (i == 0)
		throw SmallStackEx();
	it = _vec.end();
	it--;
	while (--i >= 0)
	{
		std::cout << (*it)->toString() << std::endl;
		--it;
	}
}

void	ValStorClass::assert(std::string val)
{
	IOperand const *assert = NULL;

	if (val.find("int8") < val.size())
		assert = _fac->createOperand(Int8, val.c_str() + (val.find("int8") + 5));
	else if (val.find("int16") < val.size())
		assert = _fac->createOperand(Int16, val.c_str() + (val.find("int16") + 6));
	else if (val.find("int32") < val.size())
		assert = _fac->createOperand(Int32, val.c_str() + (val.find("int32") + 6));
	else if (val.find("float") < val.size())
		assert = _fac->createOperand(Float, val.c_str() + (val.find("float") + 6));
	else if (val.find("double") < val.size())
		assert = _fac->createOperand(Double, val.c_str() + (val.find("double") + 7));
	else
	{
		delete assert;
		throw WrongTypeEx();
	}
	if (assert->getType() != _vec.top()->getType() ||
	assert->toString() != _vec.top()->toString())
	{
		delete assert;
		throw FalseAssertEx();
	}
	delete assert;
}

void	ValStorClass::print()
{
	if (_vec.size() < 1)
		throw SmallStackEx();
	if (_vec.top()->getType() != Int8)
		throw WrongPrintrEx();
	else
	{
		int val = std::stoi(_vec.top()->toString());
		if (val < 33 || val > 126)
			std::cout << "Non-displayable character " << _vec.top()->toString() << std::endl;
		else
			std::cout << static_cast<char>(val) << std::endl;
	}
}

void	ValStorClass::add()
{
	if (_vec.size() < 2)
		throw SmallStackEx();
	else
	{
		IOperand const *a;
		IOperand const *b;
		IOperand const *res;
		
		a = _vec.top();
		pop();
		b = _vec.top();
		res = *a + *b;
		pop();
		_vec.push(res);
	}
}

void	ValStorClass::sub()
{
	if (_vec.size() < 2)
		throw SmallStackEx();
	else
	{
		IOperand const *a;
		IOperand const *b;
		IOperand const *res;
		
		a = _vec.top();
		pop();
		b = _vec.top();
		res = *a - *b;
		pop();
		_vec.push(res);
	}
}

void	ValStorClass::mul()
{
	if (_vec.size() < 2)
		throw SmallStackEx();
	else
	{
		IOperand const *a;
		IOperand const *b;
		IOperand const *res;

		a = _vec.top();
		pop();
		b = _vec.top();
		res = *a * *b;
		pop();
		_vec.push(res);
	}
}

void	ValStorClass::div()
{
	if (_vec.size() < 2)
		throw SmallStackEx();
	else
	{
		IOperand const *a;
		IOperand const *b;
		IOperand const *res;

		if (std::stod(_vec.top()->toString()) == 0)
			throw ValStorClass::WrongDivZero();
		a = _vec.top();
		pop();
		b = _vec.top();
		res = *a / *b;
		pop();
		_vec.push(res);
	}
}

void	ValStorClass::mod()
{
	if (_vec.size() < 2)
		throw SmallStackEx();
	else
	{
		IOperand const *a;
		IOperand const *b;
		IOperand const *res;

		if (std::stod(_vec.top()->toString()) == 0)
			throw ValStorClass::WrongDivZero();
		a = _vec.top();
		pop();
		b = _vec.top();
		res = *a % *b;
		pop();
		_vec.push(res);
	}
}
