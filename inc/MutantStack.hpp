// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MutantStack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/19 11:58:45 by yholub            #+#    #+#             //
//   Updated: 2018/12/19 11:58:45 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANT_STACK
# define MUTANT_STACK

# include <deque>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
 private:
  typedef    std::stack<T> base;

 public:
  MutantStack(void) {}
  ~MutantStack(void) {}
  MutantStack(MutantStack const & o): base(o) {}
  typedef typename base::container_type::iterator iterator;
  using		base::operator=;

  iterator	begin() { return base::c.begin(); }
  iterator	end() { return base::c.end() ; }
};

#endif