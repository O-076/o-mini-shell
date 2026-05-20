#pragma once
#include <string>
#include <vector>

class builtins {
private:
    inline static std::vector<std::string> cmds = {"cd", "exit"};
public:
    static bool is_builtin(std::string);
    static void handle(std::vector<std::string>);
};