// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   avm.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/22 11:28:09 by yholub            #+#    #+#             //
//   Updated: 2018/10/22 11:28:10 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ABSTRACT_VM_HPP
# define ABSTRACT_VM_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <fstream>
# include <vector>
# include <exception>
# include "AvmClass.hpp"
# include "ValuesClass.hpp"

void	read_instuct(int c, char **v);
void	checkEachEl(std::string s);
void	compInstruct(AvmClass *com);
int		wsLen(std::string s);

#endif