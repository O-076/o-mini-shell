#include <iostream>
#include "../include/parser.h"
#include "../include/executer.h"
#include "../include/builtins.h"
#include <unistd.h>
using namespace std;

int main() {
    vector<string> history;
    while (true) {
        char buf[256];
        cout << "o-mini-shell:" << getcwd(buf, sizeof(buf)) << "$ ";
        string cmd;
        getline(cin,cmd);
        if (cmd.empty()) continue;
        history.push_back(cmd);
        vector<std::string> cmd_parsed = parser::parse(cmd);
        if (cmd_parsed.empty()) continue;
        else if(cmd_parsed[0] == "history") {
            for (int i = 0; i < history.size(); i++) {
                cout << history[i] << endl;
            }
        }
        else if (builtins::is_builtin(cmd_parsed[0])) builtins::handle(cmd_parsed);
        else executer::execute(cmd_parsed);
    }
}