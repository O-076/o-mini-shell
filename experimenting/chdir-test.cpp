#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int status;
    pid_t x = fork();
    if (x==0) {
        char * arg[] = {"pwd", NULL};
        execvp("pwd", arg);
    }
    else {
        waitpid(x, &status, 0);
    }
    chdir("..");
    pid_t y = fork();
    if (y==0) {
        char * arg[] = {"pwd", NULL};
        execvp("pwd", arg);
    }
    else {
        waitpid(y, &status, 0);
    }
}