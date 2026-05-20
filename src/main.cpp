#include <iostream>
#include <unistd.h>
#include "../include/parser.h"
using namespace std;

int main() {
    while (true) {
        cout << "o-mini-shell> ";
        string cmd;
        getline(cin,cmd);
        if (cmd == "exit") {
            return 0;
        }
        if (cmd.empty()) continue;
        vector<std::string> cmd_parsed = parser::parse(cmd);
        
    }
}