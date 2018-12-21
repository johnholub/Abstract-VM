// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AvmClass.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/25 12:11:51 by yholub            #+#    #+#             //
//   Updated: 2018/10/25 12:11:51 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AVM_CLASS_HPP
# define AVM_CLASS_HPP

#include <vector>
#include <string>
#include <exception>

class AvmClass
{
 public:
  AvmClass();
  AvmClass(std::vector<std::string> *);
  AvmClass operator=(AvmClass & rhs);
  AvmClass(AvmClass & rhs);
  std::vector<std::string> getVector();
  void checkComList();
  ~AvmClass();
  class		WrongComExep : public std::exception
  {
   public:
	WrongComExep();
	WrongComExep(const WrongComExep &sec);
	WrongComExep&	operator=(WrongComExep const &src);
	virtual const char* what() const throw();
	~WrongComExep() throw();
  };
  class		EmptyComExep : public std::exception
  {
   public:
	EmptyComExep();
	EmptyComExep(const EmptyComExep &sec);
	EmptyComExep&	operator=(EmptyComExep const &src);
	virtual const char* what() const throw();
	~EmptyComExep() throw();
  };
  class		NoExitExep : public std::exception
  {
   public:
	NoExitExep();
	NoExitExep(const NoExitExep &sec);
	NoExitExep&	operator=(NoExitExep const &src);
	virtual const char* what() const throw();
	~NoExitExep() throw();
  };
 private:
  std::vector<std::string> _commands;
};

#endif