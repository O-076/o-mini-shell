#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    while (true) {
        cout << "o-mini-shell> ";
        string cmd;
        cin >> cmd;
        system(cmd.c_str());
    }
}