// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ValFactory.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/01 12:13:19 by yholub            #+#    #+#             //
//   Updated: 2018/11/01 12:13:20 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

# include "../inc/ValFactory.hpp"
# include <cfloat>

ValFactory::ValFactory()
{

}
ValFactory::ValFactory(std::string val)
{
	static_cast<void>(val);
}
ValFactory::ValFactory(ValFactory & src)
{
	*this = src;
}

ValFactory ValFactory::operator=(ValFactory& src)
{
	static_cast<void>(src);
	return (*this);
}

ValFactory::~ValFactory()
{

}

ValFactory::WrongTypeExep::WrongTypeExep()
{

}

ValFactory::WrongTypeExep::WrongTypeExep(const WrongTypeExep &sec)
{
	*this = sec;
}

ValFactory::WrongTypeExep&	ValFactory::WrongTypeExep::operator=(WrongTypeExep const &)
{
	return *this;
}

ValFactory::WrongTypeExep::~WrongTypeExep() throw()
{

}

const char* ValFactory::WrongTypeExep::what() const throw()
{
	return ("Wrong type specified!");
}

IOperand const * ValFactory::createOperand(eOperandType type, std::string const & value) const
{
	switch (type)
	{
		case Int8: return (createInt8(value));
		case Int16: return (createInt16(value));
		case Int32: return (createInt32(value));
		case Float:	return (createFloat(value));
		case Double: return (createDouble(value));
		default: throw (ValFactory::WrongTypeExep());
	}
}

IOperand const * ValFactory::createInt8( std::string const & value ) const
{
	if (std::stoll(value) > INT8_MAX)
		throw (OverflowExep());
	else if (std::stoll(value) < INT8_MIN)
		throw (UnderflowExep());
	return (new ValClass<int8_t >(static_cast<int8_t>(std::stoi(value))));
}

IOperand const * ValFactory::createInt16( std::string const & value ) const
{
	if (std::stoll(value) > INT16_MAX)
		throw (OverflowExep());
	else if (std::stoll(value) < INT16_MIN)
		throw (UnderflowExep());
	return (new ValClass<int16_t >(static_cast<int16_t>(std::stoi(value))));
}

IOperand const * ValFactory::createInt32( std::string const & value ) const
{
	if (std::stoll(value) > INT32_MAX)
		throw (OverflowExep());
	else if (std::stoll(value) < INT32_MIN)
		throw (UnderflowExep());
	return (new ValClass<int32_t >(static_cast<int32_t>(std::stoi(value))));
}

IOperand const * ValFactory::createFloat( std::string const & value ) const
{
	if (std::stod(value) > FLT_MAX)
		throw (OverflowExep());
	else if ((std::stod(value) * -1) > FLT_MAX)
		throw (UnderflowExep());
	return (new ValClass<float >(std::stof(value)));
}

IOperand const * ValFactory::createDouble( std::string const & value ) const
{
	if (std::stod(value) > DBL_MAX)
		throw (OverflowExep());
	else if ((std::stod(value) * -1) > DBL_MAX)
		throw (UnderflowExep());
	return (new ValClass<double >(std::stod(value)));
}

ValFactory::OverflowExep::OverflowExep()
{

}

ValFactory::OverflowExep::OverflowExep(const OverflowExep &sec)
{
	*this = sec;
}

ValFactory::OverflowExep&	ValFactory::OverflowExep::operator=(OverflowExep const &)
{
	return *this;
}

const char* ValFactory::OverflowExep::what() const throw()
{
	return ("Overflow type!");
}

ValFactory::OverflowExep::~OverflowExep() throw()
{

}

ValFactory::UnderflowExep::UnderflowExep()
{

}
ValFactory::UnderflowExep::UnderflowExep(const UnderflowExep &sec)
{
	*this = sec;
}

ValFactory::UnderflowExep&	ValFactory::UnderflowExep::operator=(UnderflowExep const &)
{
	return *this;
}

const char* ValFactory::UnderflowExep::what() const throw()
{
	return ("Underflow type!");
}

ValFactory::UnderflowExep::~UnderflowExep() throw()
{

}
