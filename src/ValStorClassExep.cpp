// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ValStorClassExep.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/01 15:27:58 by yholub            #+#    #+#             //
//   Updated: 2018/11/01 15:27:58 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/ValStorClass.hpp"

ValStorClass::WrongDivZero::WrongDivZero()
{

}

ValStorClass::WrongDivZero::WrongDivZero(const WrongDivZero &sec)
{
	*this = sec;
}

ValStorClass::WrongDivZero&	ValStorClass::WrongDivZero::operator=(WrongDivZero const &)
{
	return *this;
}

ValStorClass::WrongDivZero::~WrongDivZero() throw()
{

}

const char* ValStorClass::WrongDivZero::what() const throw()
{
	return ("Division by zero is impossible");
}

ValStorClass::WrongOerEx::WrongOerEx()
{

}

ValStorClass::WrongOerEx::WrongOerEx(const WrongOerEx &sec)
{
	*this = sec;
}

ValStorClass::WrongOerEx&	ValStorClass::WrongOerEx::operator=(WrongOerEx const &)
{
	return *this;
}

ValStorClass::WrongOerEx::~WrongOerEx() throw()
{

}

const char* ValStorClass::WrongOerEx::what() const throw()
{
	return ("Wrong command after parsing!");
}

ValStorClass::EmptyStackEx::EmptyStackEx()
{

}

ValStorClass::EmptyStackEx::EmptyStackEx(const EmptyStackEx &sec)
{
	*this = sec;
}

ValStorClass::EmptyStackEx&	ValStorClass::EmptyStackEx::operator=(EmptyStackEx const &)
{
	return *this;
}

ValStorClass::EmptyStackEx::~EmptyStackEx() throw()
{

}

const char* ValStorClass::EmptyStackEx::what() const throw()
{
	return ("Cannot pop empty stack");
}

ValStorClass::SmallStackEx::SmallStackEx()
{

}

ValStorClass::SmallStackEx::SmallStackEx(const SmallStackEx &sec)
{
	*this = sec;
}

ValStorClass::SmallStackEx&	ValStorClass::SmallStackEx::operator=(SmallStackEx const &)
{
	return *this;
}

ValStorClass::SmallStackEx::~SmallStackEx() throw()
{

}

const char* ValStorClass::SmallStackEx::what() const throw()
{
	return ("Not enough values on stack to complete operation!");
}

ValStorClass::WrongTypeEx::WrongTypeEx()
{

}

ValStorClass::WrongTypeEx::WrongTypeEx(const WrongTypeEx &sec)
{
	*this = sec;
}

ValStorClass::WrongTypeEx&	ValStorClass::WrongTypeEx::operator=(WrongTypeEx const &)
{
	return *this;
}

ValStorClass::WrongTypeEx::~WrongTypeEx() throw()
{

}

const char* ValStorClass::WrongTypeEx::what() const throw()
{
	return ("Wrong type specified!");
}

ValStorClass::FalseAssertEx::FalseAssertEx()
{

}

ValStorClass::FalseAssertEx::FalseAssertEx(const FalseAssertEx &sec)
{
	*this = sec;
}

ValStorClass::FalseAssertEx&	ValStorClass::FalseAssertEx::operator=(FalseAssertEx const &)
{
	return *this;
}

ValStorClass::FalseAssertEx::~FalseAssertEx() throw()
{

}

const char* ValStorClass::FalseAssertEx::what() const throw()
{
	return ("False result of assert!");
}

ValStorClass::WrongPrintrEx::WrongPrintrEx()
{

}

ValStorClass::WrongPrintrEx::WrongPrintrEx(const WrongPrintrEx &sec)
{
	*this = sec;
}

ValStorClass::WrongPrintrEx&	ValStorClass::WrongPrintrEx::operator=(WrongPrintrEx const &)
{
	return *this;
}

ValStorClass::WrongPrintrEx::~WrongPrintrEx() throw()
{

}

const char* ValStorClass::WrongPrintrEx::what() const throw()
{
	return ("Trying print not int8 value!");
}
