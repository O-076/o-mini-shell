#include <iostream>
#include <unistd.h>
#include <boost/asio.hpp>
using namespace std;

int main() {
    cout << "Hello!\nI am the parent\n\n" << flush;
    pid_t pid = fork();
    if (pid == 0) cout << "Hi, I am your child\n\n" << flush;
    else {
        boost::asio::io_context io;
        boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
        t.wait();
        cout << "Nice to meet you my child.\n\n" << flush;
    }
    return 0;
}