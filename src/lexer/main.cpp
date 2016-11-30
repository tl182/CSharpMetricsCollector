//
// Created by asleap on 07.11.2016.
//

#include <sstream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include "Lexer.hpp"

int main(int argc, char *argv[]) {
//    char ch = '\f';
//    std::cout << "Code: " << std::hex << static_cast<int>(ch) << ",\tsymbol: " << ch << std::endl;

    std::ifstream source_file("Test.cs.txt");

    std::string from_source((std::istreambuf_iterator<char>(source_file)),
                            std::istreambuf_iterator<char>());
    std::istringstream source_stream(from_source);

    size_t lines = static_cast<size_t>(std::count(std::istreambuf_iterator<char>(source_stream),
               std::istreambuf_iterator<char>(), '\n'));

    source_stream.seekg(0, std::ios_base::beg);

    CSMetrics::Lexer lex(source_stream, lines);

    lex.TestFunc();

    return 0;
}
