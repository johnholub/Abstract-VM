// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ValuesClass.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/23 12:32:40 by yholub            #+#    #+#             //
//   Updated: 2018/10/23 12:32:40 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

# include "../inc/ValuesClass.hpp"
# include "../inc/ValFactory.hpp"

template<class T>
ValClass<T>::ValClass()
{
	_val = "";
	_fc = new ValFactory();
}

template<class T>
ValClass<T>::ValClass(T val)
{
	_val = std::to_string(val);
	_fc = new ValFactory();
}

template<class T>
ValClass<T>::ValClass(ValClass & val)
{
	*this = val;
}

template<class T>
ValClass<T> const * ValClass<T>::operator=(ValClass & val)
{
	_val = val._val;
	return (this);
}

template<class T>
ValClass<T>::~ValClass()
{
	delete _fc;
}

template <>
int ValClass<int8_t>::getPrecision( void ) const {
	return (Int8);
}

template <>
int ValClass<int16_t>::getPrecision( void ) const {
	return (Int16);
}

template <>
int ValClass<int32_t>::getPrecision( void ) const {
	return (Int32);
}

template <>
int ValClass<float>::getPrecision( void ) const {
	return (Float);
}

template <>
int ValClass<double>::getPrecision( void ) const {
	return (Double);
}

template <>
eOperandType ValClass<int8_t>::getType( void ) const {
	return (Int8);
}

template <>
eOperandType ValClass<int16_t>::getType( void ) const {
	return (Int16);
}

template <>
eOperandType ValClass<int32_t>::getType( void ) const {
	return (Int32);
}

template <>
eOperandType ValClass<float>::getType( void ) const {
	return (Float);
}

template <>
eOperandType ValClass<double>::getType( void ) const {
	return (Double);
}

template<class T>
IOperand const * ValClass<T>::operator+( IOperand const & rhs ) const
{
	int maxPr;
	getPrecision() > rhs.getPrecision() ? maxPr = getPrecision() : maxPr = rhs.getPrecision();
	if (maxPr < 3)
	{
		int a = std::stoi(_val);
		int b = std::stoi(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(a + b)));
	}
	else
	{
		double a = std::stod(_val);
		double b = std::stod(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(a + b)));
	}
}

template<class T>
IOperand const * ValClass<T>::operator-( IOperand const & rhs ) const
{
	int maxPr;
	getPrecision() > rhs.getPrecision() ? maxPr = getPrecision() : maxPr = rhs.getPrecision();
	if (maxPr < 3)
	{
		int a = std::stoi(_val);
		int b = std::stoi(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(b - a)));
	}
	else
	{
		double a = std::stod(_val);
		double b = std::stod(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(b - a)));
	}
}

template<class T>
IOperand const * ValClass<T>::operator*( IOperand const & rhs ) const
{
	int maxPr;
	getPrecision() > rhs.getPrecision() ? maxPr = getPrecision() : maxPr = rhs.getPrecision();
	if (maxPr < 3)
	{
		int a = std::stoi(_val);
		int b = std::stoi(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(a * b)));
	}
	else
	{
		double a = std::stod(_val);
		double b = std::stod(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(a * b)));
	}
}

template<class T>
IOperand const * ValClass<T>::operator/( IOperand const & rhs ) const
{
	int maxPr;
	getPrecision() > rhs.getPrecision() ? maxPr = getPrecision() : maxPr = rhs.getPrecision();
	if (maxPr < 3)
	{
		int a = std::stoi(_val);
		int b = std::stoi(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(b / a)));;
	}
	else
	{
		double a = std::stod(_val);
		double b = std::stod(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(b / a)));
	}
}

template<class T>
IOperand const * ValClass<T>::operator%( IOperand const & rhs ) const
{
	int maxPr;
	getPrecision() > rhs.getPrecision() ? maxPr = getPrecision() : maxPr = rhs.getPrecision();
	if (maxPr < 3)
	{
		int a = std::stoi(_val);
		int b = std::stoi(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(b % a)));
	}
	else
	{
		double a = std::stod(_val);
		double b = std::stod(rhs.toString());
		return (_fc->createOperand(getPrecision() > rhs.getPrecision() ? getType() : rhs.getType(), std::to_string(std::fmod(b, a))));
	}
}

template<class T>
std::string const & ValClass<T>::toString( void ) const
{
	return (_val);
}

template class ValClass<int8_t>;
template class ValClass<int16_t>;
template class ValClass<int32_t>;
template class ValClass<float>;
template class ValClass<double>;
