// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ValuesClass.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/23 10:43:37 by yholub            #+#    #+#             //
//   Updated: 2018/10/23 10:43:37 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VALUES_CLASS_HPP
# define VALUES_CLASS_HPP

# include "IOperandClass.hpp"
# include <string>
# include <cmath>

class ValFactory;

template<class T>
class ValClass : public IOperand
{
 public:
  ValClass(T val);
  ValClass(ValClass & val);
  ValClass const * operator=(ValClass & val);
  virtual ~ValClass();
  int getPrecision( void ) const;
  eOperandType getType( void ) const;
  IOperand const * operator+( IOperand const & rhs ) const;
  IOperand const * operator-( IOperand const & rhs ) const;
  IOperand const * operator*( IOperand const & rhs ) const;
  IOperand const * operator/( IOperand const & rhs ) const;
  IOperand const * operator%( IOperand const & rhs ) const;
  std::string const & toString( void ) const;
 private:
  ValClass<T>();
  std::string _val;
  ValFactory *_fc;
};

#endif