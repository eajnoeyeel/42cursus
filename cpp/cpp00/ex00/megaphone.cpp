/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:46:42 by yeolee2           #+#    #+#             */
/*   Updated: 2024/05/31 00:28:21 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		str = argv[i];
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] >= 'a' && str[j] <= 'z')
				std::cout << (char)toupper(str[j]);
			else
				std::cout << str[j];
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
