#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main () {
    cout << "Hello, I am your parent\n\n" << flush;
    pid_t pid = fork();
    if (pid == 0) {
        cout << "Hi Dad. Please wait for me.\n" << flush;
        char *args[3] = {"sleep", "5", NULL};
        execvp("sleep", args);
    }
    else {
        int status;
        waitpid(pid, &status , 0);
        cout << "\nAlright I did.\n" << flush;
    }
}
