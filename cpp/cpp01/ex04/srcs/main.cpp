/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:49:44 by yeolee2           #+#    #+#             */
/*   Updated: 2024/06/01 15:14:09 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"

void replace(const std::string& filename, std::string& s1, std::string& s2) {
    // It will open the file <filename> and copies its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.
    std::ifstream infile(filename);
    if (!infile.is_open() || infile.fail()) {
        std::cout << "Error: Could not open file." << std::endl;
        return;
    }
    std::ofstream outfile(filename + ".replace");
    if (!outfile.is_open() || outfile.fail()) {
        std::cout << "Error: Could not create file." << std::endl;
        return;
    }
    for (std::string line; std::getline(infile, line);) {
        //TODO: Do I need to handle getline errors?
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <search_string> <replace_string>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replace(filename, s1, s2);

    return 0;
}