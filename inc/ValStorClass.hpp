// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ValStorClass.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/01 14:07:03 by yholub            #+#    #+#             //
//   Updated: 2018/11/01 14:07:03 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VAL_STOR_CLASS_HPP
# define VAL_STOR_CLASS_HPP

#include "ValuesClass.hpp"
#include "AvmClass.hpp"
#include "MutantStack.hpp"
#include <vector>
#include <string>

class ValStorClass
{
 public:
  ValStorClass();
  ValStorClass(MutantStack<IOperand const *> vec);
  ValStorClass(ValStorClass & src);
  ValStorClass operator=(ValStorClass &src);
  ~ValStorClass();
  void	pop();
  void	push(std::string val);
  void	dump();
  void	assert(std::string val);
  void	print();
  void	add();
  void	sub();
  void	mul();
  void	div();
  void	mod();
  class		WrongOerEx : public std::exception
  {
   public:
	WrongOerEx();
	WrongOerEx(const WrongOerEx &sec);
	WrongOerEx&	operator=(WrongOerEx const &src);
	virtual const char* what() const throw();
	~WrongOerEx() throw();
  };
  class		WrongTypeEx : public std::exception
  {
   public:
	WrongTypeEx();
	WrongTypeEx(const WrongTypeEx &sec);
	WrongTypeEx&	operator=(WrongTypeEx const &src);
	virtual const char* what() const throw();
	~WrongTypeEx() throw();
  };
  class		EmptyStackEx : public std::exception
  {
   public:
	EmptyStackEx();
	EmptyStackEx(const EmptyStackEx &sec);
	EmptyStackEx&	operator=(EmptyStackEx const &src);
	virtual const char* what() const throw();
	~EmptyStackEx() throw();
  };
  class		SmallStackEx : public std::exception
  {
   public:
	SmallStackEx();
	SmallStackEx(const SmallStackEx &sec);
	SmallStackEx&	operator=(SmallStackEx const &src);
	virtual const char* what() const throw();
	~SmallStackEx() throw();
  };
  class		FalseAssertEx : public std::exception
  {
   public:
	FalseAssertEx();
	FalseAssertEx(const FalseAssertEx &sec);
	FalseAssertEx&	operator=(FalseAssertEx const &src);
	virtual const char* what() const throw();
	~FalseAssertEx() throw();
  };
  class		WrongPrintrEx : public std::exception
  {
   public:
	WrongPrintrEx();
	WrongPrintrEx(const WrongPrintrEx &sec);
	WrongPrintrEx&	operator=(WrongPrintrEx const &src);
	virtual const char* what() const throw();
	~WrongPrintrEx() throw();
  };
  class		WrongDivZero : public std::exception
  {
   public:
  	WrongDivZero();
	  WrongDivZero(const WrongDivZero &sec);
	  WrongDivZero&	operator=(WrongDivZero const &src);
	  virtual const char* what() const throw();
	  ~WrongDivZero() throw();
  };
  void	doOperatons(AvmClass *ops);
 private:
  MutantStack <IOperand const *> _vec;
  ValFactory	*_fac;
};

#endif