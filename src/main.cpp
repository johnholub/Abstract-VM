// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/22 11:26:12 by yholub            #+#    #+#             //
//   Updated: 2018/10/22 11:26:12 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/avm.hpp"

int		main(int argc, char **argv)
{
	if ((argc == 1 || argc == 2) && argv[0] != NULL)
		read_instuct(argc, argv);
	else
		std::cout << "Too much argumets" << std::endl;
}