#include <iostream>
#include "../include/parser.h"
#include "../include/executer.h"
#include "../include/builtins.h"
#include <unistd.h>
using namespace std;

int main() {
    while (true) {
        char buf[256];
        cout << "o-mini-shell:" << getcwd(buf, sizeof(buf)) << "$ ";
        string cmd;
        getline(cin,cmd);
        if (cmd.empty()) continue;
        vector<std::string> cmd_parsed = parser::parse(cmd);
        if (builtins::is_builtin(cmd_parsed[0])) builtins::handle(cmd_parsed);
        else executer::execute(cmd_parsed);
    }
}