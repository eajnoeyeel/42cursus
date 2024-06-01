/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:21:55 by yeolee2           #+#    #+#             */
/*   Updated: 2024/06/01 15:30:13 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>
# include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);
	
	private:
		void debug();
		void info();
		void warning();
		void error();
};