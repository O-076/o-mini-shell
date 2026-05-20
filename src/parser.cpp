#include "../include/parser.h"
#include <sstream>

std::vector<std::string> parser::parse (std::string cmd) {
    std::stringstream stream(cmd);
    std::vector<std::string> tokens;
    std::string arg;
    while (stream >> arg){
        tokens.push_back(arg);
    }
    return tokens;
}