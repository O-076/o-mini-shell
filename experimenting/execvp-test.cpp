#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    cout << "Hello. I am the parent process.\n\n" << flush;
    pid_t pid = fork();
    if (pid == 0) {
        cout << "This should appear.\n\n" << flush;
        char* args [] = {"ls", "-l", NULL};
        execvp("ls", args);
        cout << "This shouldn't appear\n\n";
    }
}