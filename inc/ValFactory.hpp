// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ValFactory.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/01 12:13:26 by yholub            #+#    #+#             //
//   Updated: 2018/11/01 12:13:27 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VAL_FACTORY_HPP
# define VAL_FACTORY_HPP

# include <iostream>
# include "ValuesClass.hpp"

class ValFactory
{
 public:
  ValFactory();
  ValFactory(std::string val);
  ValFactory(ValFactory & src);
  ValFactory operator=(ValFactory& src);
  ~ValFactory();
  class		WrongTypeExep : public std::exception
  {
   public:
	WrongTypeExep();
	WrongTypeExep(const WrongTypeExep &sec);
	WrongTypeExep&	operator=(WrongTypeExep const &);
	virtual const char* what() const throw();
	~WrongTypeExep() throw();
  };
  class		OverflowExep : public std::exception
  {
   public:
	OverflowExep();
	OverflowExep(const OverflowExep &sec);
	OverflowExep&	operator=(OverflowExep const &);
	virtual const char* what() const throw();
	~OverflowExep() throw();
  };
  class		UnderflowExep : public std::exception
  {
   public:
	UnderflowExep();
	UnderflowExep(const UnderflowExep &sec);
	UnderflowExep&	operator=(UnderflowExep const &);
	virtual const char* what() const throw();
	~UnderflowExep() throw();
  };
  IOperand const * createOperand(eOperandType type, std::string const & value) const;
 private:
  IOperand const * createInt8( std::string const & value ) const;
  IOperand const * createInt16( std::string const & value ) const;
  IOperand const * createInt32( std::string const & value ) const;
  IOperand const * createFloat( std::string const & value ) const;
  IOperand const * createDouble( std::string const & value ) const;
};

#endif