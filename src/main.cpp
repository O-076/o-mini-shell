#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    while (true) {
        cout << "o-mini-shell> ";
        string cmd;
        getline(cin,cmd);
        if (cmd == "exit") {
            return 0;
        }
        system(cmd.c_str());
    }
}