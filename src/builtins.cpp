#include "../include/builtins.h"
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>

bool builtins::is_builtin(std::string cmd) {
    auto it = std::find(cmds.begin(), cmds.end(), cmd);

    if (it != cmds.end()) {
        return true;
    } else {
        return false;
    }
}

void builtins::handle(std::vector<std::string> argv) {
    if (argv.empty()) return;
    if (argv[0] == "exit") {
        exit(0);
    }
    else if (argv[0] == "cd" && argv.size() == 2) {
        if(chdir(argv[1].c_str()) == -1 ) std::cerr << "Invalid directory.\n";
    }
    else if (argv[0] == "cd") {
        if (argv.size() > 2) std::cerr << "Too many arguments.\n";
        else std::cerr << "Missing arguments. Please enter a directory.\n";
    }
}