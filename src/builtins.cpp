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
        return;
    }
    else if (argv[0] == "cd" && argv.size() > 1) {
        if(chdir(argv[1].c_str()) == -1 ) std::cerr << "Invalid directory.\n";
    }
    else if (argv[0] == "cd") {
        std::cerr << "Please enter a valid directory\n";
    }
}