#include "../include/executer.h"
#include <unistd.h>

void executer::execute(std::vector<std::string> cmd_parsed) {
    char** argv = new char*[cmd_parsed.size() + 1];
    
    for (int i = 0; i < cmd_parsed.size(); i++) {
        argv[i] = const_cast<char*>(cmd_parsed[i].c_str());
    }
    argv[cmd_parsed.size()] = nullptr;

    pid_t pid = fork();
    
    if (pid==0) {
        execvp(argv[0], argv);
    }
    
    else return;
}